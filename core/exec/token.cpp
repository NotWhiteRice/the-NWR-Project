#include "token.hpp"

namespace nwr {
    Token::Token() : value(""), type(t_UNKNOWN) {}
    Token::Token(string str, int type) : value(str), type(type) {}

    bool Token::operator()(Token::types type) const {
        return this->type == type;
    }

    string Token::is() const { return value; }
}