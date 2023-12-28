
/*
 * dlex: lexer generator
 *
 * usage: dlex <infile> <outfile>
 *
 * input file format:
 * <token_name> <regex>
 *
 * supported regex features:
 * character = itself
 * a | b = either a or b
 * (a) = grouping
 * [characters] = any of them
 * a* = a repeated any number of times
 *
 * output file generates cpp code
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "codegen.hpp"
#include "dfa.hpp"
#include "nfa.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <infile>";
        return 1;
    }

    std::string tokenName;
    std::string regex;

    std::ifstream ifs(argv[1]);

    std::ostringstream enumDef;
    std::ostringstream prelude;
    prelude << "#include <concepts>\n"
               "#include <string>\n"
               "template <typename T>\n"
               "concept CharIter = requires(T a) {\n"
               "{ *a } -> std::convertible_to<char>;\n"
               "++a;\n"
               "};\n"
               "struct LexingError { std::string msg; };\n"
               "template <typename Ann>\n"
               "struct Token {\n"
               "    TokenType type;\n"
               "    std::string content;\n"
               "    Ann ann;\n"
               "};\n"
               "template <CharIter It>\n"
               "std::pair<Token<int>, It> lexToken(It _cur, It _end) {\n"
               "    bool _accepted = false;\n"
               "    auto _start = _cur;\n"
               "    auto _accit = _cur;\n"
               "    TokenType _acctype;\n";

    std::ostringstream mainLoop;
    mainLoop << "while (_cur != _end && _live) {\n";

    enumDef << "enum TokenType {\n";

    int id = 0;

    while (std::getline(ifs, tokenName, ' ')) {
        std::getline(ifs, regex, '\n');
        if (tokenName[0] == '#') continue;
        enumDef << "    " << tokenName << " = " << id << ",\n";
        std::cerr << "compiling regex \"" << regex << "\"\n" << std::endl;

        try {
            // nfa generation
            auto nfa = dlex::NFAFromRegex(regex);
            std::cerr << "[initial] state " << nfa.initial.lock()->ann
                      << std::endl;
            for (auto s : nfa.states) {
                std::cerr << "-- NFA state " << s->ann << " --\n";
                if (s->accept)
                    std::cerr << "  [accepting]\n";
                for (auto [c, n] : s->transitions) {
                    if (c == '\0') {
                        std::cerr << "  eps -> " << n.lock()->ann << "\n";
                    } else {
                        std::cerr << "  '" << c << "' -> " << n.lock()->ann
                                  << "\n";
                    }
                }
            }

            // dfa generation
            auto dfa = dlex::DFAFromNFA(nfa);
            std::cerr << "\n\n";
            std::cerr << "[initial] state " << nfa.initial.lock()->ann
                      << std::endl;
            for (int i = 0; i < dfa.states.size(); ++i) {
                auto s = dfa.states[i];
                std::cerr << "-- DFA state " << i << " --\n";
                if (s.accept)
                    std::cerr << "  [accepting]\n";
                for (auto [c, n] : s.transitions) {
                    std::cerr << "  '" << c << "' -> " << n << "\n";
                }
            }

            // code generation: maximal munch
            prelude << "    int _state" << id << " = " << dfa.initial << ";\n";
            auto code = codeFromDFA(dfa, id++);
            mainLoop << "// token type " << tokenName << "\n";
            mainLoop << code << "\n";
        } catch (dlex::RegexCompilationError err) {
            std::cerr << err.message << std::endl;
        }
    }

    prelude << "    int _live = " << id << ";\n";
    mainLoop << "++_cur;\n"
                "}\n";
    enumDef << "};\n";
    std::cout << enumDef.str() << prelude.str() << mainLoop.str();
    std::cout
        << "\n"
           "if (!_accepted) throw LexingError{\"could not match any "
           "tokens\"};\n"
           "++_accit;\n"
           "return {{_acctype, std::string(_start.it, _accit.it), 0}, _accit};\n";
    std::cout << "}\n" << std::endl;
}
