#include "../iter/Iterator.hpp"

#include "../parser/parsercpp.hpp"

#include "../lang/string.hpp"
#include "../memory/bitmanip.hpp"

#include <iostream>

using namespace nwr;

Parser parser;

int main(int argc, char* argv[]) {
    int test1[] = {1, 3, 12, 28, 4};
    LegacyRandomAccessIterator<int> test;

    LegacyRandomAccessIterator<int> test3 = test + 3;

    std::cout << *test3 << std::endl;

    return 0;
}