#include "Token.hpp"

#include <string>

using std::string;

Token::Token(string str, int type) : value(str), type(type) {}
Token* Token::initToken(string str, int type) { 
    Token* token = new Token(str, type);
    return token;
}