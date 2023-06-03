#pragma once

#include "../../interpreter/UniversalParser.hpp"

#include <fstream>
using std::ifstream;

namespace nwr {
    class ParserCPP : private UniversalParser {
    public:
        ParserCPP();

        void parse(const char *file) override;
    };
}