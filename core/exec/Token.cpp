#include "Token.h"
#include "UniversalLexer.h"

namespace nwr {
	Token::Token( ): value(""), type(UniversalLexer::t_UNKNOWN) { }
	Token::Token(string str, int type): value(str), type(type) { }

	string Token::getValue( ) const { return value; }
	int Token::getType( ) const { return type; }
}