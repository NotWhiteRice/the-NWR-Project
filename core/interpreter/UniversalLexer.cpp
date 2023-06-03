#include "UniversalLexer.hpp"

#include <iostream>

using std::cout;
using std::endl;

namespace nwr {
    UniversalLexer::UniversalLexer(const char *file) : line("") {
        unit = ifstream(file);
        eof = !unit.is_open();
        if(eof) throw "nwr::UniversalLexer UniversalLever(*file)\\ Unable to retrieve file";
        nextLine();
    }

    void UniversalLexer::advance(size_t i) {
        if(len == 0) cout << "[DEBUG in nwr/parser/lexer.cpp] at> advance(i) \\ Somehow went off despite the line being empty." << endl;
        if(len >= i) {
            len -= i;
            line = line.substr(i);
        } else advance(len);
    }

    void UniversalLexer::nextLine() {
        if(!eof) {
            eof = !getline(unit, line);
            len = line.size();
            size += len;
        }
    }

    void UniversalLexer::skipWhitespace(bool skipLines) {
        if(skipLines) while(line.find_first_not_of(' ') == -1 && !eof) nextLine();    
        if(eof) return;

        advance(line.find_first_not_of(' '));
    }

    Token UniversalLexer::validateLexer() const {
        return eof ? Token("", t_EOF) : Token("", t_UNKNOWN);
    }

    bool UniversalLexer::operator!() const { return eof; }
    UniversalLexer::operator bool() const { return !eof; }

    Token UniversalLexer::nextToken() {
        const char ch = line.front();
        char *val;
        size_t length;
        string temp;
        string numKey = "1234567890";
        string idKey = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ_";
        if(ch == '.' || numKey.find_first_of(ch) != -1) {
            if(ch == '.' && len > 1) if(numKey.find_first_of(line.at(1)) != -1) {
                    goto numeric_literal;
            } else if(ch == '.') {}
            else goto numeric_literal;
        } else if(idKey.find_first_of(ch) != -1) {
            goto identifier;
        } else {
            string temp(1, ch);
            advance(1);
            return Token(temp, t_UNKNOWN);
        }
numeric_literal:
length = line.find_first_not_of("1234567890.");
val = new char[length + 1]{0};
for(size_t i = 0; i < length; i++) val[i] = line[i];
temp = string(val);
advance(length);
if(temp.find('.') != temp.rfind('.')) return Token(temp, t_UNKNOWN);
if(temp.find('.') == -1) return Token(temp, t_FLOAT);
return Token(temp, t_INT);
identifier:
length = line.find_first_not_of(idKey);
val = new char[length + 1]{0};
for(size_t i = 0; i < length; i++) val[i] = line[i];
temp = string(val);
advance(length);
return Token(temp, t_ID);
    }
}