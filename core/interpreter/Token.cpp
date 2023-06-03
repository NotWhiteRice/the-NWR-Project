#include "Token.hpp"
#include "UniversalLexer.hpp"

namespace nwr {
    Token::Token() : value(""), type(UniversalLexer::universal_tokens::t_UNKNOWN) {}
    Token::Token(string str, int type) : value(str), type(type) {}

    string Token::getValue() const { return value; }
    int Token::getType() const { return type; }
}