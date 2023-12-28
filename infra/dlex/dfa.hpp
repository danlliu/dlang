
#pragma once

#include <memory>
#include <vector>

#include "nfa.hpp"

namespace dlex {

struct DFA {
    struct State {
        struct Transition {
            char ch;
            int next;
        };

        std::vector<Transition> transitions;
        bool accept;
    };

    std::vector<State> states;
    int initial;
};

DFA DFAFromNFA(NFA nfa);

} // namespace dlex


