#include "lexer.h"

namespace nwr {
	LexerCPP::LexerCPP(const char *file): UniversalLexer(file) { }

	Token LexerCPP::nextToken( ) {
		return Token("", t_EOF);
	}
}