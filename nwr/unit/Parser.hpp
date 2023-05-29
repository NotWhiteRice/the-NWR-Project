#pragma once

#include <fstream>
#include <string>
#include <iostream>

using std::ifstream;
using std::string;
using std::getline;
using std::cout;
using std::endl;

namespace nwr {
    class Parser {
        ifstream unit;

    public:
        void parse(const char* fileDir);
    };
}