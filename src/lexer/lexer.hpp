
#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace dlang {

#include "generated_lexer.hpp"

struct FileLocation {
    int line;
    int col;
};

auto lex(const std::string &input) -> std::vector<Token<FileLocation>>;

} // namespace meowlang
