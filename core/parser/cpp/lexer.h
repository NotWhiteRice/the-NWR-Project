#pragma once

#include "../../exec/UniversalLexer.h"

namespace nwr {
	class LexerCPP: public UniversalLexer {
	public:
		LexerCPP(const char *file);

		enum cppTokens {
			
		};

		Token nextToken( ) override;
	};
}


