#include "Lexer.hpp"

#include <iostream>

Lexer::Lexer(ifstream& file) : unit(file) {}

bool Lexer::operator!() const { return eod; }
void Lexer::nextLine() { eod = !getline(unit, line); }

Lexer* Lexer::initLexer(const char* fileDir) {
    ifstream* unit = new ifstream(fileDir);
    Lexer* lexer = new Lexer(*unit);
    lexer->nextLine();
    return lexer;
}

string Lexer::extractToken() {
    string val = "";

    line = line.substr(line.find_first_not_of(' '));

    char c = line.front();

    if(line.substr(1).empty()) {
        val += c;
        line = line.substr(1);
        return val;
    }

    while((isalpha(c) || c == '_') || (!val.empty() && isdigit(c))) {
        val += c;
        line = line.substr(1);
        c = line.front();
    }
    if(val.empty()) {
        while(!line.empty() && (isdigit(c) || c == '.')) {
            val += c;
            line = line.substr(1);
            c = line.front();
        }
        if(val.empty()) {

#define L2C1(i, j)\
case(i): {\
if(line.at(1) == j) {\
val+=c;\
line = line.substr(1);\
c = line.front();\
}\
} break;
#define L2C2(i, j, k)\
case(i): {\
if(line.at(1) == j || line.at(1) == k) {\
val+=c;\
line = line.substr(1);\
c = line.front();\
}\
} break;
#define L2C3(i, j, k, l)\
case(i): {\
if(line.at(1) == j || line.at(1) == k || line.at(1) == l) {\
val+=c;\
line = line.substr(1);\
c = line.front();\
}\
} break;

            switch(c) {
                L2C1('-', '>');
                L2C1('=', '>');
                default:
                    break;
            }
            val+=c;
            line = line.substr(1);
        }
    }
    return val;
}

#define processToken(str, type) if(val == str) return Token::initToken(str, type)

string val;
Token* Lexer::nextToken() {
    if(line.empty()) nextLine();
    if(!!(*this)) val = extractToken();
    else return Token::initToken("", Token::t_EOF);
    processToken("(", Token::t_LPAREN);
    processToken("[", Token::t_LSQBRACE);
    processToken("{", Token::t_LBRACE);
    processToken(")", Token::t_RPAREN);
    processToken("]", Token::t_RSQBRACE);
    processToken("}", Token::t_RBRACE);

    processToken("->", Token::t_RARROW);
    processToken("=>", Token::t_RDARROW);

    processToken(":", Token::t_COLON);
    processToken(",", Token::t_COMMA);
    processToken(".", Token::t_PERIOD);

    processToken("return", Token::t_RETURN);
    processToken("int", Token::t_TYPE);

    if(val.find_first_not_of("1234567890.") == -1) {
        if(val.find('.') == -1) return Token::initToken(val, Token::t_INT);
        else return Token::initToken(val, Token::t_FLOAT);
    }
    if(val.find_first_not_of("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ_1234567890") == -1)
        return Token::initToken(val, Token::t_ID);

    return Token::initToken(val, Token::t_UNKNOWN);
}