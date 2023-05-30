#include "lexer.hpp"

#include <iostream>

using std::getline;
const char* idAlph = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ_1234567890";

Lexer::Lexer(const char* dir) : line("") {
    unit = ifstream(dir);
    eof = !unit.is_open();
    if(eof) std::cout << "[ERROR in nwr/parser/lexer.cpp] at> Lexer(dir) \\ Unable to retrieve file--" << dir << std::endl;
}

void Lexer::nextLine() { 
    if(!eof) {
        eof = !getline(unit, line); 
        len = line.size();
        size += len;
    }
}

void Lexer::advance(size_t i) {
    if(len == 0) std::cout << "[DEBUG in nwr/parser/lexer.cpp] at> advance(i) \\ Somehow went off despite the line being empty." << std::endl;
    if(len >= i) {
        len-=i;
        line = line.substr(i);
    } else advance(len);
}

bool Lexer::operator!() const { return eof; }
Lexer::operator bool() const { return !eof; }

Token Lexer::nextToken() {
    while(line.find_first_not_of(' ') == -1 && !eof) nextLine();
    if(eof) return Token("", Token::t_EOF);

    advance(line.find_first_not_of(' '));

#define addSpecial(str, size, token)\
if(len >= size) if(line.substr(0, size) == str) {\
advance(size);\
return Token(str, token);\
}
#define addSingle(str, token)\
if(len >= size) if(line.front() == str.c_str();) {\
advance();\
return Token(str, token);\
}
    
    addSpecial("//", 2, Token::t_DFSLASH);
    addSpecial("/*", 2, Token::t_COMMIN);
    addSpecial("*/", 2, Token::t_COMMOUT);

    if(len>=1) if(line.front() == '.' && !isdigit(line.at(1))) {
        advance();
        return Token(".", Token::t_PERIOD);
    }
    
    size_t pos = line.find_first_not_of("1234567890.");
    string val = line.substr(0, pos);
    if(val.empty()) {
        pos = line.find_first_not_of(idAlph);
        val = line.substr(0, pos);
        if(val.empty()) {
            if(pos == -1) {
                val = line;
                pos = len;
keyword:
                advance(pos);
                if(val == "return") return Token("return", Token::t_RETURN);
                if(val == "int") return Token("int", Token::t_TYPE);
                return Token(val, Token::t_ID);
            }
            val = string(1, line.front());
            advance();
            return Token(val, Token::t_UNKNOWN);
        } else goto keyword;
    } else {
        size_t pos = line.find('.');
        Token::types id = pos == line.rfind('.') ? pos == -1 ? Token::t_INT : Token::t_FLOAT : Token::t_UNKNOWN;
        advance(pos);
        return Token(val, id);
    }
}