#include "parser.hpp"

#include "lexer.hpp"

#include <iostream>
using std::cout;
using std::endl;

namespace nwr {
    ParserCPP::ParserCPP() : UniversalParser() {}
std::string test = "%:%:";
    void ParserCPP::parse(const char *file) {
        LexerCPP lexer = LexerCPP(file);
        bool isComment;
        Token token = lexer.nextToken();
        int type = token.getType();
        while(type != LexerCPP::t_EOF) {
            if(type == LexerCPP::t_COMMIN) isComment = true;
            if(!isComment) {
                if(type == LexerCPP::t_DFSLASH) lexer.nextLine();
                if(type == LexerCPP::t_UNKNOWN) cout << token.getValue() << " is not registered." << endl;
                if(type == LexerCPP::t_ID) cout << token.getValue() << "is an unrecognized word." << endl;
            }
            if(type == LexerCPP::t_COMMOUT) isComment = false;
            token = lexer.nextToken();
            type = token.getType();
        }
    }
}