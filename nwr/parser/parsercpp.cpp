#include "parsercpp.hpp"
#include "lexer.hpp"

#include <iostream>

void ParserCPP::parse(const char* dir) {
    Lexer lexer = Lexer(dir);
    int i = 0;
    bool isComment;
    Token token = lexer.nextToken();
    while(!token(Token::t_EOF)) {
        if(token(Token::t_COMMIN)) isComment = true;
        if(!isComment) {
            if(token(Token::t_DFSLASH)) lexer.nextLine();
            std::cout << token.is() << " is " << (token(Token::t_UNKNOWN) ? "not " : "") << "registered."<< std::endl;
        }
        if(token(Token::t_COMMOUT)) isComment = false;
        token = lexer.nextToken();
    }   
}