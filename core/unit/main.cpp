#include "../interpreter/UniversalParser.hpp"

using namespace nwr;

Parser parser;

int main(int argc, char* argv[]) {
    parser.parse("../parser/cpp/parser.cpp");

    return 0;
}