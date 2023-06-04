#pragma once

#include "../../exec/UniversalParser.h"

namespace nwr {
	class ParserCPP: public UniversalParser {
	public:
		ParserCPP( );
		
		void parse(int args, ...) override;
	};
}

