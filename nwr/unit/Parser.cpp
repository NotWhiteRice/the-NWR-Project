#include "parser.hpp"
#include <cstring>

#include "Lexer.hpp"

using namespace nwr;

void Parser::parse(const char* fileDir) {
    Lexer *lexer = Lexer::initLexer(fileDir);

    if (lexer->line != "") {
        Token* token = Token::initToken("", Token::t_UNKNOWN);
        bool isComment = false;
        bool printStatus = 0;
        while(token->type != Token::t_EOF) {
            token = lexer->nextToken();
            if(token->type == Token::t_DFSLASH) lexer->nextLine();
            else {
                if(token->type == Token::t_COMMIN) isComment = true;
                if(!isComment) {
                    //if(token->type == Token::t_UNKNOWN) throw "nwr::Parser parse(fileDir)\\ Unknown character.";
                    if(printStatus == 1 && token->type != Token::t_LPAREN) {
                        if(token->type == Token::t_RPAREN) printStatus = 0;
                        else cout << token->value;
                    }
                    if(token->type == Token::t_ID && printStatus == 0 && token->value == "print") printStatus = 1;
                }
                if(token->type == Token::t_COMMOUT) isComment = false;
            }
        }
        lexer->unit.close();
    } else {
        cout << "Unable to retrieve the file." << endl;
    }
    delete lexer;
}