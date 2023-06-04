#include "../exec/UniversalParser.h"

using namespace nwr;

Parser parser;

int main( ) {
	parser.parse(1, "core/unit/main.cpp");

	return 0;
}