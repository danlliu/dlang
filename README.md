
# dlang

a fun compiler project

thanks to all my friends who contributed ideas

## preprocessing

```
// single line comment
/* multi
   line
   comment
 */
```

## syntax:

```
Tokens:
Ident = any token starting with nonnumeric
NumLit = [0-9]+
BoolLit = true | false

LPAREN = (
RPAREN = )
LBRACKET = [
RBRACKET = ]
LBRACE = {
RBRACE = }
PLUS = +
PLUSEQ = +=
MINUS = -
MINUSEQ = -=
TIMES = *
TIMESEQ = *=
DIVIDE = /
DIVEQ = /=
MOD = %
MODEQ = %=
BITAND = &
BITANDEQ = &=
LOGAND = &&
LOGANDEQ = &&=
BITOR = |
BITOREQ = |=
LOGOR = ||
LOGOREQ = ||=
XOR = ^
XOREQ = ^=

EOL = ;

IF = if
ELSE = else
WHILE = while
FOR = for
IN = in

FUNCTION = fn

Expr = 
| Ident
| NumLit
| BoolLit
| StrLit

| ( Expr )
| ( Expr, Expr ... )
| [ Expr, Expr... ]
| { Expr }
| <unop> Expr
  | - a
| Expr <binop> Expr
  | a + b
  | a - b
  | a * b
  | a / b
  | a % b
  | a & b
  | a && b
  | a | b
  | a || b
  | a ^ b
| Expr [ Expr ]
| Expr = Expr
| if (Expr) Expr
| if (Expr) Expr else Expr
| for (Ident in Expr) Expr
| while (Expr) Expr

FunDecl =
fn Ident (Params) { Expr }

Program = 
| FunDecl
| Program FunDecl
```

