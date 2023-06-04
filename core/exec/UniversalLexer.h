#pragma once

#include "Token.h"

#include <fstream>
#include <string>

using std::ifstream;
using std::string;

namespace nwr {
	class UniversalLexer {
	private:
		bool eof;
		string line;
		ifstream unit;
		size_t length, size;

		void advance(size_t len = 1);
	public:
		UniversalLexer(const char *file);

		enum universalTokens {
			t_UNKNOWN = -2,
			t_EOF = -1,
		};

		bool operator!( ) const;
		operator bool( ) const;

		string readLine( ) const;

		virtual Token nextToken( ) = 0;
		void nextLine( );
	};
}

