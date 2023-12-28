enum TokenType {
    Ident = 0,
    Num = 1,
    BoolLit = 2,
    LPAREN = 3,
    RPAREN = 4,
    LBRACKET = 5,
    RBRACKET = 6,
    LBRACE = 7,
    RBRACE = 8,
    PLUS = 9,
    PLUSEQ = 10,
    MINUS = 11,
    MINUSEQ = 12,
    TIMES = 13,
    TIMESEQ = 14,
    DIVIDE = 15,
    DIVIDEEQ = 16,
    EOL = 17,
    IF = 18,
    ELSE = 19,
    WHILE = 20,
    FOR = 21,
    IN = 22,
    FUNCTION = 23,
    Whitespace = 24,
};
#include <concepts>
#include <string>
template <typename T>
concept CharIter = requires(T a) {
{ *a } -> std::convertible_to<char>;
++a;
};
struct LexingError { std::string msg; };
template <typename Ann>
struct Token {
    TokenType type;
    std::string content;
    Ann ann;
};
template <CharIter It>
std::pair<Token<int>, It> lexToken(It _cur, It _end) {
    bool _accepted = false;
    auto _start = _cur;
    auto _accit = _cur;
    TokenType _acctype;
    int _state0 = 0;
    int _state1 = 0;
    int _state2 = 0;
    int _state3 = 0;
    int _state4 = 0;
    int _state5 = 0;
    int _state6 = 0;
    int _state7 = 0;
    int _state8 = 0;
    int _state9 = 0;
    int _state10 = 0;
    int _state11 = 0;
    int _state12 = 0;
    int _state13 = 0;
    int _state14 = 0;
    int _state15 = 0;
    int _state16 = 0;
    int _state17 = 0;
    int _state18 = 0;
    int _state19 = 0;
    int _state20 = 0;
    int _state21 = 0;
    int _state22 = 0;
    int _state23 = 0;
    int _state24 = 0;
    int _live = 25;
while (_cur != _end && _live) {
// token type Ident
do {
switch (_state0) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'A') _state0 = 1;
    else if (*_cur == 'B') _state0 = 1;
    else if (*_cur == 'C') _state0 = 1;
    else if (*_cur == 'D') _state0 = 1;
    else if (*_cur == 'E') _state0 = 1;
    else if (*_cur == 'F') _state0 = 1;
    else if (*_cur == 'G') _state0 = 1;
    else if (*_cur == 'H') _state0 = 1;
    else if (*_cur == 'I') _state0 = 1;
    else if (*_cur == 'J') _state0 = 1;
    else if (*_cur == 'K') _state0 = 1;
    else if (*_cur == 'L') _state0 = 1;
    else if (*_cur == 'M') _state0 = 1;
    else if (*_cur == 'N') _state0 = 1;
    else if (*_cur == 'O') _state0 = 1;
    else if (*_cur == 'P') _state0 = 1;
    else if (*_cur == 'Q') _state0 = 1;
    else if (*_cur == 'R') _state0 = 1;
    else if (*_cur == 'S') _state0 = 1;
    else if (*_cur == 'T') _state0 = 1;
    else if (*_cur == 'U') _state0 = 1;
    else if (*_cur == 'V') _state0 = 1;
    else if (*_cur == 'W') _state0 = 1;
    else if (*_cur == 'X') _state0 = 1;
    else if (*_cur == 'Y') _state0 = 1;
    else if (*_cur == 'Z') _state0 = 1;
    else if (*_cur == 'a') _state0 = 1;
    else if (*_cur == 'b') _state0 = 1;
    else if (*_cur == 'c') _state0 = 1;
    else if (*_cur == 'd') _state0 = 1;
    else if (*_cur == 'e') _state0 = 1;
    else if (*_cur == 'f') _state0 = 1;
    else if (*_cur == 'g') _state0 = 1;
    else if (*_cur == 'h') _state0 = 1;
    else if (*_cur == 'i') _state0 = 1;
    else if (*_cur == 'j') _state0 = 1;
    else if (*_cur == 'k') _state0 = 1;
    else if (*_cur == 'l') _state0 = 1;
    else if (*_cur == 'm') _state0 = 1;
    else if (*_cur == 'n') _state0 = 1;
    else if (*_cur == 'o') _state0 = 1;
    else if (*_cur == 'p') _state0 = 1;
    else if (*_cur == 'q') _state0 = 1;
    else if (*_cur == 'r') _state0 = 1;
    else if (*_cur == 's') _state0 = 1;
    else if (*_cur == 't') _state0 = 1;
    else if (*_cur == 'u') _state0 = 1;
    else if (*_cur == 'v') _state0 = 1;
    else if (*_cur == 'w') _state0 = 1;
    else if (*_cur == 'x') _state0 = 1;
    else if (*_cur == 'y') _state0 = 1;
    else if (*_cur == 'z') _state0 = 1;
    else goto fail0;
    break;
    case 1:
    if (0);
    else if (*_cur == '0') _state0 = 2;
    else if (*_cur == '1') _state0 = 2;
    else if (*_cur == '2') _state0 = 2;
    else if (*_cur == '3') _state0 = 2;
    else if (*_cur == '4') _state0 = 2;
    else if (*_cur == '5') _state0 = 2;
    else if (*_cur == '6') _state0 = 2;
    else if (*_cur == '7') _state0 = 2;
    else if (*_cur == '8') _state0 = 2;
    else if (*_cur == '9') _state0 = 2;
    else if (*_cur == 'A') _state0 = 2;
    else if (*_cur == 'B') _state0 = 2;
    else if (*_cur == 'C') _state0 = 2;
    else if (*_cur == 'D') _state0 = 2;
    else if (*_cur == 'E') _state0 = 2;
    else if (*_cur == 'F') _state0 = 2;
    else if (*_cur == 'G') _state0 = 2;
    else if (*_cur == 'H') _state0 = 2;
    else if (*_cur == 'I') _state0 = 2;
    else if (*_cur == 'J') _state0 = 2;
    else if (*_cur == 'K') _state0 = 2;
    else if (*_cur == 'L') _state0 = 2;
    else if (*_cur == 'M') _state0 = 2;
    else if (*_cur == 'N') _state0 = 2;
    else if (*_cur == 'O') _state0 = 2;
    else if (*_cur == 'P') _state0 = 2;
    else if (*_cur == 'Q') _state0 = 2;
    else if (*_cur == 'R') _state0 = 2;
    else if (*_cur == 'S') _state0 = 2;
    else if (*_cur == 'T') _state0 = 2;
    else if (*_cur == 'U') _state0 = 2;
    else if (*_cur == 'V') _state0 = 2;
    else if (*_cur == 'W') _state0 = 2;
    else if (*_cur == 'X') _state0 = 2;
    else if (*_cur == 'Y') _state0 = 2;
    else if (*_cur == 'Z') _state0 = 2;
    else if (*_cur == '_') _state0 = 2;
    else if (*_cur == 'a') _state0 = 2;
    else if (*_cur == 'b') _state0 = 2;
    else if (*_cur == 'c') _state0 = 2;
    else if (*_cur == 'd') _state0 = 2;
    else if (*_cur == 'e') _state0 = 2;
    else if (*_cur == 'f') _state0 = 2;
    else if (*_cur == 'g') _state0 = 2;
    else if (*_cur == 'h') _state0 = 2;
    else if (*_cur == 'i') _state0 = 2;
    else if (*_cur == 'j') _state0 = 2;
    else if (*_cur == 'k') _state0 = 2;
    else if (*_cur == 'l') _state0 = 2;
    else if (*_cur == 'm') _state0 = 2;
    else if (*_cur == 'n') _state0 = 2;
    else if (*_cur == 'o') _state0 = 2;
    else if (*_cur == 'p') _state0 = 2;
    else if (*_cur == 'q') _state0 = 2;
    else if (*_cur == 'r') _state0 = 2;
    else if (*_cur == 's') _state0 = 2;
    else if (*_cur == 't') _state0 = 2;
    else if (*_cur == 'u') _state0 = 2;
    else if (*_cur == 'v') _state0 = 2;
    else if (*_cur == 'w') _state0 = 2;
    else if (*_cur == 'x') _state0 = 2;
    else if (*_cur == 'y') _state0 = 2;
    else if (*_cur == 'z') _state0 = 2;
    else goto fail0;
    break;
    case 2:
    if (0);
    else if (*_cur == '0') _state0 = 2;
    else if (*_cur == '1') _state0 = 2;
    else if (*_cur == '2') _state0 = 2;
    else if (*_cur == '3') _state0 = 2;
    else if (*_cur == '4') _state0 = 2;
    else if (*_cur == '5') _state0 = 2;
    else if (*_cur == '6') _state0 = 2;
    else if (*_cur == '7') _state0 = 2;
    else if (*_cur == '8') _state0 = 2;
    else if (*_cur == '9') _state0 = 2;
    else if (*_cur == 'A') _state0 = 2;
    else if (*_cur == 'B') _state0 = 2;
    else if (*_cur == 'C') _state0 = 2;
    else if (*_cur == 'D') _state0 = 2;
    else if (*_cur == 'E') _state0 = 2;
    else if (*_cur == 'F') _state0 = 2;
    else if (*_cur == 'G') _state0 = 2;
    else if (*_cur == 'H') _state0 = 2;
    else if (*_cur == 'I') _state0 = 2;
    else if (*_cur == 'J') _state0 = 2;
    else if (*_cur == 'K') _state0 = 2;
    else if (*_cur == 'L') _state0 = 2;
    else if (*_cur == 'M') _state0 = 2;
    else if (*_cur == 'N') _state0 = 2;
    else if (*_cur == 'O') _state0 = 2;
    else if (*_cur == 'P') _state0 = 2;
    else if (*_cur == 'Q') _state0 = 2;
    else if (*_cur == 'R') _state0 = 2;
    else if (*_cur == 'S') _state0 = 2;
    else if (*_cur == 'T') _state0 = 2;
    else if (*_cur == 'U') _state0 = 2;
    else if (*_cur == 'V') _state0 = 2;
    else if (*_cur == 'W') _state0 = 2;
    else if (*_cur == 'X') _state0 = 2;
    else if (*_cur == 'Y') _state0 = 2;
    else if (*_cur == 'Z') _state0 = 2;
    else if (*_cur == '_') _state0 = 2;
    else if (*_cur == 'a') _state0 = 2;
    else if (*_cur == 'b') _state0 = 2;
    else if (*_cur == 'c') _state0 = 2;
    else if (*_cur == 'd') _state0 = 2;
    else if (*_cur == 'e') _state0 = 2;
    else if (*_cur == 'f') _state0 = 2;
    else if (*_cur == 'g') _state0 = 2;
    else if (*_cur == 'h') _state0 = 2;
    else if (*_cur == 'i') _state0 = 2;
    else if (*_cur == 'j') _state0 = 2;
    else if (*_cur == 'k') _state0 = 2;
    else if (*_cur == 'l') _state0 = 2;
    else if (*_cur == 'm') _state0 = 2;
    else if (*_cur == 'n') _state0 = 2;
    else if (*_cur == 'o') _state0 = 2;
    else if (*_cur == 'p') _state0 = 2;
    else if (*_cur == 'q') _state0 = 2;
    else if (*_cur == 'r') _state0 = 2;
    else if (*_cur == 's') _state0 = 2;
    else if (*_cur == 't') _state0 = 2;
    else if (*_cur == 'u') _state0 = 2;
    else if (*_cur == 'v') _state0 = 2;
    else if (*_cur == 'w') _state0 = 2;
    else if (*_cur == 'x') _state0 = 2;
    else if (*_cur == 'y') _state0 = 2;
    else if (*_cur == 'z') _state0 = 2;
    else goto fail0;
    break;
}
switch (_state0) {
    case 1: [[fallthrough]];
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(0); break;
    default: break;
}
break;
fail0: _state0 = -1; _live -= 1;
} while(0);

// token type Num
do {
switch (_state1) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '0') _state1 = 1;
    else if (*_cur == '1') _state1 = 1;
    else if (*_cur == '2') _state1 = 1;
    else if (*_cur == '3') _state1 = 1;
    else if (*_cur == '4') _state1 = 1;
    else if (*_cur == '5') _state1 = 1;
    else if (*_cur == '6') _state1 = 1;
    else if (*_cur == '7') _state1 = 1;
    else if (*_cur == '8') _state1 = 1;
    else if (*_cur == '9') _state1 = 1;
    else goto fail1;
    break;
    case 1:
    if (0);
    else if (*_cur == '0') _state1 = 1;
    else if (*_cur == '1') _state1 = 1;
    else if (*_cur == '2') _state1 = 1;
    else if (*_cur == '3') _state1 = 1;
    else if (*_cur == '4') _state1 = 1;
    else if (*_cur == '5') _state1 = 1;
    else if (*_cur == '6') _state1 = 1;
    else if (*_cur == '7') _state1 = 1;
    else if (*_cur == '8') _state1 = 1;
    else if (*_cur == '9') _state1 = 1;
    else goto fail1;
    break;
}
switch (_state1) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(1); break;
    default: break;
}
break;
fail1: _state1 = -1; _live -= 1;
} while(0);

// token type BoolLit
do {
switch (_state2) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'f') _state2 = 1;
    else if (*_cur == 't') _state2 = 2;
    else goto fail2;
    break;
    case 1:
    if (0);
    else if (*_cur == 'a') _state2 = 3;
    else goto fail2;
    break;
    case 2:
    if (0);
    else if (*_cur == 'r') _state2 = 4;
    else goto fail2;
    break;
    case 3:
    if (0);
    else if (*_cur == 'l') _state2 = 5;
    else goto fail2;
    break;
    case 4:
    if (0);
    else if (*_cur == 'u') _state2 = 6;
    else goto fail2;
    break;
    case 5:
    if (0);
    else if (*_cur == 's') _state2 = 7;
    else goto fail2;
    break;
    case 6:
    if (0);
    else if (*_cur == 'e') _state2 = 8;
    else goto fail2;
    break;
    case 7:
    if (0);
    else if (*_cur == 'e') _state2 = 9;
    else goto fail2;
    break;
    case 8:
    if (0);
    else goto fail2;
    break;
    case 9:
    if (0);
    else goto fail2;
    break;
}
switch (_state2) {
    case 8: [[fallthrough]];
    case 9: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(2); break;
    default: break;
}
break;
fail2: _state2 = -1; _live -= 1;
} while(0);

// token type LPAREN
do {
switch (_state3) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '(') _state3 = 1;
    else goto fail3;
    break;
    case 1:
    if (0);
    else goto fail3;
    break;
}
switch (_state3) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(3); break;
    default: break;
}
break;
fail3: _state3 = -1; _live -= 1;
} while(0);

// token type RPAREN
do {
switch (_state4) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == ')') _state4 = 1;
    else goto fail4;
    break;
    case 1:
    if (0);
    else goto fail4;
    break;
}
switch (_state4) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(4); break;
    default: break;
}
break;
fail4: _state4 = -1; _live -= 1;
} while(0);

// token type LBRACKET
do {
switch (_state5) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '[') _state5 = 1;
    else goto fail5;
    break;
    case 1:
    if (0);
    else goto fail5;
    break;
}
switch (_state5) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(5); break;
    default: break;
}
break;
fail5: _state5 = -1; _live -= 1;
} while(0);

// token type RBRACKET
do {
switch (_state6) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == ']') _state6 = 1;
    else goto fail6;
    break;
    case 1:
    if (0);
    else goto fail6;
    break;
}
switch (_state6) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(6); break;
    default: break;
}
break;
fail6: _state6 = -1; _live -= 1;
} while(0);

// token type LBRACE
do {
switch (_state7) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '{') _state7 = 1;
    else goto fail7;
    break;
    case 1:
    if (0);
    else goto fail7;
    break;
}
switch (_state7) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(7); break;
    default: break;
}
break;
fail7: _state7 = -1; _live -= 1;
} while(0);

// token type RBRACE
do {
switch (_state8) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '}') _state8 = 1;
    else goto fail8;
    break;
    case 1:
    if (0);
    else goto fail8;
    break;
}
switch (_state8) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(8); break;
    default: break;
}
break;
fail8: _state8 = -1; _live -= 1;
} while(0);

// token type PLUS
do {
switch (_state9) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '+') _state9 = 1;
    else goto fail9;
    break;
    case 1:
    if (0);
    else goto fail9;
    break;
}
switch (_state9) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(9); break;
    default: break;
}
break;
fail9: _state9 = -1; _live -= 1;
} while(0);

// token type PLUSEQ
do {
switch (_state10) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '+') _state10 = 1;
    else goto fail10;
    break;
    case 1:
    if (0);
    else if (*_cur == '=') _state10 = 2;
    else goto fail10;
    break;
    case 2:
    if (0);
    else goto fail10;
    break;
}
switch (_state10) {
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(10); break;
    default: break;
}
break;
fail10: _state10 = -1; _live -= 1;
} while(0);

// token type MINUS
do {
switch (_state11) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '-') _state11 = 1;
    else goto fail11;
    break;
    case 1:
    if (0);
    else goto fail11;
    break;
}
switch (_state11) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(11); break;
    default: break;
}
break;
fail11: _state11 = -1; _live -= 1;
} while(0);

// token type MINUSEQ
do {
switch (_state12) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '-') _state12 = 1;
    else goto fail12;
    break;
    case 1:
    if (0);
    else if (*_cur == '=') _state12 = 2;
    else goto fail12;
    break;
    case 2:
    if (0);
    else goto fail12;
    break;
}
switch (_state12) {
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(12); break;
    default: break;
}
break;
fail12: _state12 = -1; _live -= 1;
} while(0);

// token type TIMES
do {
switch (_state13) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '*') _state13 = 1;
    else goto fail13;
    break;
    case 1:
    if (0);
    else goto fail13;
    break;
}
switch (_state13) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(13); break;
    default: break;
}
break;
fail13: _state13 = -1; _live -= 1;
} while(0);

// token type TIMESEQ
do {
switch (_state14) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '*') _state14 = 1;
    else goto fail14;
    break;
    case 1:
    if (0);
    else if (*_cur == '=') _state14 = 2;
    else goto fail14;
    break;
    case 2:
    if (0);
    else goto fail14;
    break;
}
switch (_state14) {
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(14); break;
    default: break;
}
break;
fail14: _state14 = -1; _live -= 1;
} while(0);

// token type DIVIDE
do {
switch (_state15) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '/') _state15 = 1;
    else goto fail15;
    break;
    case 1:
    if (0);
    else goto fail15;
    break;
}
switch (_state15) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(15); break;
    default: break;
}
break;
fail15: _state15 = -1; _live -= 1;
} while(0);

// token type DIVIDEEQ
do {
switch (_state16) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '/') _state16 = 1;
    else goto fail16;
    break;
    case 1:
    if (0);
    else if (*_cur == '=') _state16 = 2;
    else goto fail16;
    break;
    case 2:
    if (0);
    else goto fail16;
    break;
}
switch (_state16) {
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(16); break;
    default: break;
}
break;
fail16: _state16 = -1; _live -= 1;
} while(0);

// token type EOL
do {
switch (_state17) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == ';') _state17 = 1;
    else goto fail17;
    break;
    case 1:
    if (0);
    else goto fail17;
    break;
}
switch (_state17) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(17); break;
    default: break;
}
break;
fail17: _state17 = -1; _live -= 1;
} while(0);

// token type IF
do {
switch (_state18) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'i') _state18 = 1;
    else goto fail18;
    break;
    case 1:
    if (0);
    else if (*_cur == 'f') _state18 = 2;
    else goto fail18;
    break;
    case 2:
    if (0);
    else goto fail18;
    break;
}
switch (_state18) {
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(18); break;
    default: break;
}
break;
fail18: _state18 = -1; _live -= 1;
} while(0);

// token type ELSE
do {
switch (_state19) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'e') _state19 = 1;
    else goto fail19;
    break;
    case 1:
    if (0);
    else if (*_cur == 'l') _state19 = 2;
    else goto fail19;
    break;
    case 2:
    if (0);
    else if (*_cur == 's') _state19 = 3;
    else goto fail19;
    break;
    case 3:
    if (0);
    else if (*_cur == 'e') _state19 = 4;
    else goto fail19;
    break;
    case 4:
    if (0);
    else goto fail19;
    break;
}
switch (_state19) {
    case 4: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(19); break;
    default: break;
}
break;
fail19: _state19 = -1; _live -= 1;
} while(0);

// token type WHILE
do {
switch (_state20) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'w') _state20 = 1;
    else goto fail20;
    break;
    case 1:
    if (0);
    else if (*_cur == 'h') _state20 = 2;
    else goto fail20;
    break;
    case 2:
    if (0);
    else if (*_cur == 'i') _state20 = 3;
    else goto fail20;
    break;
    case 3:
    if (0);
    else if (*_cur == 'l') _state20 = 4;
    else goto fail20;
    break;
    case 4:
    if (0);
    else if (*_cur == 'e') _state20 = 5;
    else goto fail20;
    break;
    case 5:
    if (0);
    else goto fail20;
    break;
}
switch (_state20) {
    case 5: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(20); break;
    default: break;
}
break;
fail20: _state20 = -1; _live -= 1;
} while(0);

// token type FOR
do {
switch (_state21) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'f') _state21 = 1;
    else goto fail21;
    break;
    case 1:
    if (0);
    else if (*_cur == 'o') _state21 = 2;
    else goto fail21;
    break;
    case 2:
    if (0);
    else if (*_cur == 'r') _state21 = 3;
    else goto fail21;
    break;
    case 3:
    if (0);
    else goto fail21;
    break;
}
switch (_state21) {
    case 3: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(21); break;
    default: break;
}
break;
fail21: _state21 = -1; _live -= 1;
} while(0);

// token type IN
do {
switch (_state22) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'i') _state22 = 1;
    else goto fail22;
    break;
    case 1:
    if (0);
    else if (*_cur == 'n') _state22 = 2;
    else goto fail22;
    break;
    case 2:
    if (0);
    else goto fail22;
    break;
}
switch (_state22) {
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(22); break;
    default: break;
}
break;
fail22: _state22 = -1; _live -= 1;
} while(0);

// token type FUNCTION
do {
switch (_state23) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == 'f') _state23 = 1;
    else goto fail23;
    break;
    case 1:
    if (0);
    else if (*_cur == 'n') _state23 = 2;
    else goto fail23;
    break;
    case 2:
    if (0);
    else goto fail23;
    break;
}
switch (_state23) {
    case 2: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(23); break;
    default: break;
}
break;
fail23: _state23 = -1; _live -= 1;
} while(0);

// token type Whitespace
do {
switch (_state24) {
    case -1: break;
    case 0:
    if (0);
    else if (*_cur == '\n') _state24 = 1;
    else if (*_cur == ' ') _state24 = 1;
    else goto fail24;
    break;
    case 1:
    if (0);
    else if (*_cur == '\n') _state24 = 1;
    else if (*_cur == ' ') _state24 = 1;
    else goto fail24;
    break;
}
switch (_state24) {
    case 1: [[fallthrough]];
    _accepted = true; _accit = _cur; _acctype = static_cast<TokenType>(24); break;
    default: break;
}
break;
fail24: _state24 = -1; _live -= 1;
} while(0);

++_cur;
}

if (!_accepted) throw LexingError{"could not match any tokens"};
++_accit;
return {{_acctype, std::string(_start.it, _accit.it), 0}, _accit};
}

