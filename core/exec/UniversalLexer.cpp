#include "UniversalLexer.h"

#include <iostream>
using std::cout;
using std::endl;

namespace nwr {
	UniversalLexer::UniversalLexer(const char *file): line("") {
		unit = ifstream(file);
		eof = !unit.is_open( );
		if(eof) throw "[ERROR--nwr::UniversalLexer] UniversalLexer(*file)\\ Unable to retrieve file";
		nextLine( );
	}

	void UniversalLexer::advance(size_t i) {
		if(length == 0) cout << "[DEBUG--nwr::UniversalLexer] advance(count)\\ Somehow went off despite the line being empty";
		if(length >= i) {
			length -= i;
			line = line.substr(i);
		} else advance(length);
	}

	void UniversalLexer::nextLine( ) {
		if(!eof) {
			eof = !getline(unit, line);
			length = line.size( );
			size += length;
		}
	}

	string UniversalLexer::readLine( ) const { return line; }

	bool UniversalLexer::operator!( ) const { return eof; }
	UniversalLexer::operator bool( ) const { return !eof; }
}