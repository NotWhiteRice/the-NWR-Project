#include "parser.hpp"
#include "lexer.hpp"

#include <iostream>

namespace nwr {
    void ParserNWR::parse(const char* dir) {
        Lexer lexer = Lexer(dir);
        bool isComment;
        Token token = lexer.nextToken();
        while(!token(Token::t_EOF)) {
            if(token(Token::t_COMMIN)) isComment = true;
            if(!isComment) {
                if(token(Token::t_DFSLASH)) lexer.nextLine();
                if(token(Token::t_UNKNOWN)) std::cout << token.is() << " is not registered." << std::endl;
            }
            if(token(Token::t_COMMOUT)) isComment = false;
            token = lexer.nextToken();
        }   
    }
}