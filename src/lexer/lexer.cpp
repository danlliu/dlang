
#include "lexer.hpp"

#include <sstream>
#include <string>

template <typename It> struct LexerIterator {
    It it;
    int line;
    int col;

    LexerIterator(It it) : it{it}, line{1}, col{1} {}

    auto operator*() { return *it; }

    auto operator++() -> LexerIterator<It> & {
        if (*it == '\n') {
            ++line;
            col = 1;
        } else
            ++col;
        ++it;
        return *this;
    }

    bool operator==(const LexerIterator<It> &other) const {
        return it == other.it;
    }
};

auto dlang::lex(const std::string &input) -> std::vector<Token<FileLocation>> {
    auto it = LexerIterator<decltype(input.begin())>{input.begin()};
    auto end = LexerIterator<decltype(input.end())>{input.end()};

    std::vector<Token<FileLocation>> result;

    while (it != end) {
        try {
            auto [tok, it2] = lexToken(it, end);
            auto loc = FileLocation{it.line, it.col};
            result.emplace_back(Token<FileLocation>{tok.type, tok.content, loc});
            it = it2;
        } catch (dlang::LexingError err) {
            std::ostringstream oss;
            oss << "error at line " << it.line << ", column " << it.col << ": "
                << err.msg;
            throw dlang::LexingError{oss.str()};
        }
    }
    return result;
}
