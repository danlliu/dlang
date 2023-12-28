
#include "nfa.hpp"

#include <concepts>
#include <iterator>
#include <memory>
#include <stack>

using namespace dlex;

/*
 * HELPERS
 */

void appendNFA(NFA &dst, NFA &&right) {

    // L accept -(eps)-> R entry

    for (auto d : dst.acceptingStates) {
        auto p = d.lock();
        p->accept = false;
        p->transitions.emplace_back(
            NFA::State::Transition{'\0', right.initial});
    }
    dst.acceptingStates = right.acceptingStates;

    for (auto s : right.states) {
        dst.states.emplace_back(std::move(s));
    }
    right.acceptingStates.clear();
    right.states.clear();
}

/*
 * IMPLEMENTATION
 */

template <typename T>
concept StringIter = requires(T a) {
                         { *a } -> std::convertible_to<char>;
                     };

/*
 * a(bc|[de])f|gh
 *
 * a b * c
 *
 *
 */

template <StringIter It> struct NFAConstructionResult {
    NFA nfa;
    It new_start;
};

template <StringIter It>
NFAConstructionResult<It> untaggedNFAFromRegex(It regex, It end, char start) {
    auto base = NFA{};
    {
        auto init = std::make_shared<NFA::State>(NFA::State{{}, -1, true});
        base.initial = init;
        base.acceptingStates.push_back(init);
        base.states.emplace_back(std::move(init));
    }

    if (regex == end) {
        if (start == '(') {
            throw RegexCompilationError{"unbalanced parentheses"};
        }
        /*
        [ start, accept ]
        */
        return {base, end};
    }
    /*
     * if it's (: call it again
     * if it's ): end of group
     * if it's [: finish the group and append it
     * if it's |: end of group; call it again on next and union them
     */
    std::vector<NFA> groups{};
    while (regex != end) {
        if (*regex == ')' && start == '(') {
            ++regex;
            break;
        } else if (*regex == '(') {
            ++regex;
            auto [nfa, it] = untaggedNFAFromRegex(regex, end, '(');
            regex = it;
            groups.emplace_back(nfa);
        } else if (*regex == '[') {
            auto letterNFA = NFA{};

            {
                auto init =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, false});
                auto acc =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, true});

                char lastChar = '\0';

                ++regex;
                while (*regex != ']') {
                    char c = *regex;
                    ++regex;
                    if (c == '\\') {
                        char c2 = *regex;
                        ++regex;
                        if (c2 == 'n')
                            c = '\n';
                        else if (c2 == 't')
                            c = '\t';
                        else
                            c = c2;
                        init->transitions.emplace_back(
                            NFA::State::Transition{c, acc});
                        lastChar = c;
                    } else if (c == '-') {
                        char c2 = *regex;
                        ++regex;
                        for (char i = lastChar + 1; i <= c2; ++i)
                            init->transitions.emplace_back(
                                NFA::State::Transition{i, acc});
                    } else {
                        init->transitions.emplace_back(
                            NFA::State::Transition{c, acc});
                        lastChar = c;
                    }
                }

                letterNFA.initial = init;
                letterNFA.acceptingStates.push_back(acc);
                letterNFA.states.emplace_back(std::move(init));
                letterNFA.states.emplace_back(std::move(acc));
            }

            ++regex;
            groups.emplace_back(letterNFA);
        } else if (*regex == '*') {
            auto &prev = groups.back();
            {
                auto init =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, false});
                auto acc =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, true});
                init->transitions.emplace_back(
                    NFA::State::Transition{'\0', acc});
                acc->transitions.emplace_back(
                    NFA::State::Transition{'\0', init});
                init->transitions.emplace_back(
                    NFA::State::Transition{'\0', prev.initial});
                prev.initial = init;
                for (auto s : prev.acceptingStates) {
                    auto p = s.lock();
                    p->accept = false;
                    p->transitions.emplace_back(
                        NFA::State::Transition{'\0', acc});
                }
                prev.acceptingStates.clear();
                prev.acceptingStates.emplace_back(acc);
                prev.states.emplace_back(std::move(init));
                prev.states.emplace_back(std::move(acc));
            }
            ++regex;
        } else if (*regex == '|') {
            auto base = NFA{};
            {
                auto init =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, true});
                base.initial = init;
                base.acceptingStates.push_back(init);
                base.states.emplace_back(std::move(init));
            }
            for (auto g : groups)
                appendNFA(base, std::move(g));
            groups.clear();

            ++regex;
            auto [nfa, it] = untaggedNFAFromRegex(regex, end, start);

            auto joined = NFA{};
            {
                auto init =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, false});
                auto acc =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, true});

                init->transitions.emplace_back(
                    NFA::State::Transition{'\0', base.initial});
                base.initial.lock()->accept = false;
                init->transitions.emplace_back(
                    NFA::State::Transition{'\0', nfa.initial});
                nfa.initial.lock()->accept = false;

                for (auto a : base.acceptingStates) {
                    auto p = a.lock();
                    p->accept = false;
                    p->transitions.emplace_back(
                        NFA::State::Transition{'\0', acc});
                }
                for (auto a : nfa.acceptingStates) {
                    auto p = a.lock();
                    p->accept = false;
                    p->transitions.emplace_back(
                        NFA::State::Transition{'\0', acc});
                }

                joined.initial = init;
                joined.acceptingStates.push_back(acc);
                joined.states.emplace_back(std::move(init));
                joined.states.emplace_back(std::move(acc));
                for (auto s : base.states)
                    joined.states.emplace_back(std::move(s));
                for (auto s : nfa.states)
                    joined.states.emplace_back(std::move(s));
            }
            return {joined, it};
        } else {
            auto letterNFA = NFA{};

            char c = *regex;
            ++regex;

            if (c == '\\') {
                char c2 = *regex;
                ++regex;
                if (c2 == 'n')
                    c = '\n';
                else if (c2 == 't')
                    c = '\t';
                else
                    c = c2;
            }

            {
                auto init =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, false});
                auto acc =
                    std::make_shared<NFA::State>(NFA::State{{}, -1, true});

                init->transitions.emplace_back(NFA::State::Transition{c, acc});

                letterNFA.initial = init;
                letterNFA.acceptingStates.push_back(acc);
                letterNFA.states.emplace_back(std::move(init));
                letterNFA.states.emplace_back(std::move(acc));
            }

            groups.emplace_back(letterNFA);
        }
    }

    // append all the groups
    for (auto &&g : groups) {
        appendNFA(base, std::move(g));
    }
    return {base, regex};
}

void tagNFA(const NFA &nfa) {
    std::stack<std::weak_ptr<NFA::State>> dfs;
    if (nfa.initial.lock().get() != nullptr)
        dfs.emplace(nfa.initial);
    int id = 0;
    while (dfs.size()) {
        auto front = dfs.top().lock();
        dfs.pop();
        if (front->ann != -1)
            continue;
        front->ann = id++;
        for (auto [_, next] : front->transitions)
            if (next.lock()->ann == -1)
                dfs.emplace(next);
    }
}

NFA dlex::NFAFromRegex(std::span<char> regex) {

    auto [nfa, it] = untaggedNFAFromRegex(regex.begin(), regex.end(), '\0');
    tagNFA(nfa);
    return nfa;
}
