#include "UniversalParser.hpp"


#include "UniversalLexer.hpp"
#include "../parser/cpp/parser.hpp"
//#include "../parser/nwr/parser.hpp"

#include <cstring>
#include <string>
#include <fstream>
#include <iostream>

using std::ifstream;

namespace nwr {
    UniversalParser::UniversalParser() {}


    const char *UniversalParser::getFileExtension(const char *file) {
        size_t i = strlen(file), j = i;
        while(j--) if(file[j] == '.') break;
        char *ext = new char[i - j + 1]{0};
        for(size_t k = 0; j <= i; j++, k++)
            ext[k] = file[j];
        return ext;
    }

    void UniversalParser::parse(const char *file) {
        string dir = (string("../unit/") + string(file));
        std::cout << dir << " || " << file << std::endl;
        ifstream unit = ifstream(dir.c_str());
        const char *temp = getFileExtension(file);
        string ext = string(temp);
        unit.close();
        if(ext == ".nwr") {
            //ParserNWR parser;
        } else if(ext == ".cpp" || ext == ".hpp" || ext == ".h") {
            ParserCPP parser;
            parser.parse(dir.c_str());
        }
    }
}