#include "UniversalParser.h"

#include "../Reference.h"
#include "../parser/cpp/parser.h"

#include <string>
#include <cstdarg>
using std::string;

namespace nwr {
	UniversalParser::UniversalParser( ) {}

	const char *UniversalParser::getFileExtension(const char *file) {
		size_t i = strlen(file), j = i;
		while(j--) if(file[j] == '.') break;
		if(j == 0) throw "[ERROR--nwr::UniversalParser] getFileExtension(*file)\\ Not a valid file name";
		char *ext = new char[i - j + 1] { 0 };
		for(size_t k = 0; j <= i; j++, k++) ext[k] = file[j];
		return ext;
	}

	void UniversalParser::parse(int args, ...) {
		va_list param;
		va_start(param, args);
		if(args < 1) throw "[ERROR--nwr::UniversalParser] parse(args, param)\\ Must have at least one argument: the file being parsed";
		char *file = va_arg(param, char *);
		const char *ext = getFileExtension(file);
		string dir = workspaceFolder + string(file);
		if(strcmp(ext, ".nwr") == 0) {
			//ParserNWR parser;
		} else if(strcmp(ext, ".C") == 0 || strcmp(ext, ".H") == 0 || strcmp(ext, ".cc") == 0 || strcmp(ext, ".hh") == 0 || strcmp(ext, ".cpp") == 0 || strcmp(ext, ".hpp") == 0 || strcmp(ext, ".cxx") == 0 || strcmp(ext, ".hxx") == 0 || strcmp(ext, ".c++") == 0 || strcmp(ext, ".h++") == 0 || strcmp(ext, ".h") == 0) {
			ParserCPP parser;
			parser.parse(args, dir.c_str(), param);
		}
	}
}