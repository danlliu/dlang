
#pragma once

#include <memory>
#include <span>
#include <string>
#include <vector>

namespace dlex {

struct NFA {
    struct State {
        struct Transition {
            char ch;
            std::weak_ptr<State> next;
        };

        std::vector<Transition> transitions;
        int ann;
        bool accept;
    };

    std::vector<std::shared_ptr<State>> states;
    std::weak_ptr<State> initial;
    std::vector<std::weak_ptr<State>> acceptingStates;
};

struct RegexCompilationError {
    std::string message;
};

NFA NFAFromRegex(std::span<char> regex);

} // namespace dlex

