#pragma once

#include <string>

using std::string;

namespace nwr {
	class Token {
	private:
		string value;
		int type;
	public:
		Token( );
		Token(string str, int type);

		string getValue( ) const;
		int getType( ) const;
	};
}

