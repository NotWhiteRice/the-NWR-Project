#include "parser.h"
#include "lexer.h"
#include <cstdarg>
#include <iostream>

namespace nwr {
	ParserCPP::ParserCPP( ): UniversalParser() { }

	void ParserCPP::parse(int args, ...) {
		va_list param;
		va_start(param, args);
		const char *file = va_arg(param, const char *);
		LexerCPP lexer = LexerCPP(file);
		while(lexer) {
			std::cout << lexer.readLine( ) << std::endl;
			lexer.nextLine( );
		}
	}
}