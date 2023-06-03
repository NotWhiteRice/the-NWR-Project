#pragma once


#include <fstream>
#include <string>

#include "token.hpp"

using std::ifstream;
using std::string;

namespace nwr {
    class Lexer {
    private:
        bool eof;
        string line;
        ifstream unit;
        size_t len, size;

        void advance(const size_t i = 1);
    public:
        Lexer(const char* dir);

        bool operator!() const;
        operator bool() const;

        Token nextToken();
        void nextLine();
    } typedef Lexer;
}