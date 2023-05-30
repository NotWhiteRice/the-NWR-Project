#include "../parser/parsercpp.hpp"

Parser parser;

int main(int argc, char* argv[]) {

    parser.parse("../parser/lexer.cpp");

    return 0;
}