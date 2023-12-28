
#include "dfa.hpp"

#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

#include "nfa.hpp"

using namespace dlex;

std::unordered_set<int>
closure(const std::vector<std::weak_ptr<NFA::State>> &states,
        const std::unordered_set<int> &current) {
    std::unordered_set<int> result = current;
    std::deque<int> bfs(current.begin(), current.end());
    while (bfs.size()) {
        auto c = bfs.front();
        bfs.pop_front();
        for (auto t : states[c].lock()->transitions) {
            if (t.ch == '\0') {
                int ann = t.next.lock()->ann;
                if (!result.contains(ann)) {
                    result.insert(ann);
                    bfs.push_back(ann);
                }
            }
        }
    }
    return result;
}

std::vector<std::pair<char, std::unordered_set<int>>>
allDerivatives(const std::vector<std::weak_ptr<NFA::State>> &states,
               const std::unordered_set<int> &current) {
    std::set<char> availableTransitions{};
    for (auto s : current) {
        auto p = states[s].lock();
        for (auto [c, _] : p->transitions)
            if (c != '\0')
                availableTransitions.insert(c);
    }
    std::vector<std::pair<char, std::unordered_set<int>>> result;
    for (auto c : availableTransitions) {
        std::unordered_set<int> post;
        for (auto s : current) {
            auto p = states[s].lock();
            for (auto [t, s2] : p->transitions)
                if (t == c)
                    post.insert(s2.lock()->ann);
        }
        result.emplace_back(std::make_pair(c, closure(states, post)));
    }
    return result;
}

DFA dlex::DFAFromNFA(NFA nfa) {
    auto dfa = DFA{};

    // generate state map
    std::vector<std::weak_ptr<NFA::State>> states(nfa.states.size());
    for (auto state : nfa.states) {
        states[state->ann] = state;
    }

    // initial state is the closure of the initial
    std::vector<std::unordered_set<int>> stateGroups;
    std::queue<int> stateBFS;

    {
        std::unordered_set<int> initial;
        initial.insert(nfa.initial.lock()->ann);
        stateGroups.emplace_back(closure(states, initial));
        stateBFS.push(0);
        dfa.states.emplace_back(DFA::State{{}, false});
        dfa.initial = 0;
    }

    while (!stateBFS.empty()) {
        auto front = stateBFS.front();
        stateBFS.pop();

        for (auto [t, s] : allDerivatives(states, stateGroups[front])) {
            bool newState = true;
            for (int i = 0; i < stateGroups.size(); ++i) {
                if (stateGroups[i] == s) {
                    newState = false;
                    dfa.states[front].transitions.emplace_back(
                        DFA::State::Transition{t, i});
                    break;
                }
            }
            if (newState) {
                bool accepting = false;
                for (auto i : s)
                    if (states[i].lock()->accept)
                        accepting = true;

                stateGroups.emplace_back(s);
                dfa.states.emplace_back(DFA::State{{}, accepting});
                dfa.states[front].transitions.emplace_back(
                    DFA::State::Transition{
                        t, static_cast<int>(stateGroups.size() - 1)});

                stateBFS.push(stateGroups.size() - 1);
            }
        }
    }

    return dfa;
}
