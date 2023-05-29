#pragma once

#include <string>

using std::string;

class Token {
private:
    Token(string ch, int type);
    
public:
    string value;
    int type;

    enum types {
        t_TYPE,
        t_ID,

        t_LPAREN,
        t_LSQBRACE,
        t_LBRACE,
        t_RPAREN,
        t_RSQBRACE,
        t_RBRACE,

        t_RARROW,
        t_RDARROW,

        t_COLON,
        t_COMMA,
        t_PERIOD,

        t_INT,
        t_FLOAT,
        t_RETURN,
        t_EOF,

        t_UNKNOWN,
    };

    static Token* initToken(string str, int type);
    
} typedef Token;