#pragma once

#include <fstream>
#include <string>

#include "Token.hpp"

using std::ifstream;
using std::string;

namespace nwr {
    class UniversalLexer {
    private:
        bool eof;
        string line;
        ifstream unit;
        size_t len, size;

        void advance(const size_t i = 1);
        void skipWhitespace(bool skipLines = true);
        Token validateLexer() const;

#define addToken(str, size, token)\
if(len >= size) if(line.substr(0, size) == str) {\
advance(size);\
return Token(str, token);\
}

    public:
        UniversalLexer(const char *file);

        enum universal_tokens {
            t_UNKNOWN,
            t_EOF,
            t_INT,
            t_FLOAT,
            t_ID,
        };

        bool operator!() const;
        operator bool() const;

        virtual Token nextToken();
        void nextLine();

        friend class LexerCPP;
    } typedef Lexer;
}