
#include "codegen.hpp"

#include <sstream>

using namespace dlex;

std::string escapeChar(char c) {
    if (c == '\n') return "\\n";
    if (c == '\t') return "\\t";
    return {c};
}

std::string dlex::codeFromDFA(DFA dfa, int id) {
    std::ostringstream oss;

    oss << "do {\n";
    oss << "switch (_state" << id << ") {\n";
    oss << "    case -1: break;\n";

    for (int i = 0; i < dfa.states.size(); ++i) {
        oss << "    case " << i << ":\n";
        oss << "    if (0);\n";
        for (auto [t, s] : dfa.states[i].transitions) {
            oss << "    else if (*_cur == '" << escapeChar(t) << "') _state" << id << " = " << s << ";\n"; 
        }
        oss << "    else goto fail" << id << ";\n";
        oss << "    break;\n";
    }
    oss << "}\n"; // switch
    oss << "switch (_state" << id << ") {\n";
    for (int i = 0; i < dfa.states.size(); ++i) {
        if (dfa.states[i].accept)
            oss << "    case " << i << ": [[fallthrough]];\n";
    }
    oss << "    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(" << id << "); break;\n";
    oss << "    default: break;\n";
    oss << "}\n"; // switch
    oss << "break;\n"; // switch
    oss << "fail" << id << ": _state" << id << " = -1; _live -= 1;\n";
    oss << "} while(0);\n";

    return oss.str();
}

