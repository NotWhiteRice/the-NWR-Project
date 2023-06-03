#include "../interpreter/UniversalParser.hpp"

using namespace nwr;

Parser parser;

int main(int argc, char* argv[]) {
    parser.parse("build/modular_filesystem.cc");

    return 0;
}