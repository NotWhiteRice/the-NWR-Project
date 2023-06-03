#pragma once

#include <string>
using std::string;

namespace nwr {
    class UniversalParser {
    private:
        const char *getFileExtension(const char *file);

    public:
        UniversalParser();
        
        virtual void parse(const char *file);
    } typedef Parser;
}