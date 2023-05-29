#pragma once

#include "Token.hpp"

#include <fstream>
#include <string>

using std::ifstream;
using std::string;

class Lexer {
private:
    bool eod;
    Lexer(ifstream& file);

    void nextLine();
public:
    string line;
    ifstream& unit;

    bool operator!() const;

    static Lexer* initLexer(const char* fileDir);
    string extractToken();
    Token* nextToken();
} typedef Lexer;