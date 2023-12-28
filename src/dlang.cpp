
#include <fstream>
#include <iostream>
#include <sstream>

#include "lexer/lexer.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        std::ifstream ifs(argv[1]);
        std::ostringstream oss;
        oss << ifs.rdbuf();

        try {
            auto lexed = dlang::lex(oss.str());
            for (auto tok : lexed) {
                std::cout << "Token(line " << tok.ann.line << ", col "
                          << tok.ann.col << "; type "
                          << static_cast<int>(tok.type) << ", content = \""
                          << tok.content << "\")" << std::endl;
            }
        } catch (dlang::LexingError err) {
            std::cerr << "Error: " << err.msg << std::endl;
            return 1;
        }
    } else {
        std::cerr << "usage: " << argv[0] << " <file>" << std::endl;
    }
}
