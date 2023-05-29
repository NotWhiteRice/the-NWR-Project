#include "parser.hpp"
#include <cstring>


#include "Lexer.hpp"

using namespace nwr;

void Parser::parse(const char* fileDir) {
    Lexer *lexer = Lexer::initLexer(fileDir);

    if (lexer->line != "") {
        Token* token = Token::initToken("", Token::t_UNKNOWN);
        while(token->type != Token::t_EOF) {
            token = lexer->nextToken();
            if(token != nullptr) cout << "id: " << token->type << ", value: " << (token->value) << endl;
        }
        lexer->unit.close();
    } else {
        cout << "Unable to retrieve the file." << endl;
    }
    delete lexer;
}