#include "../parser/parsercpp.hpp"

#include "../lang/string.hpp"
#include "../memory/bitmanip.hpp"
#include "../iter/LegacyRandomAccessIterator.hpp"
#include "../iter/LegacyOutputIterator.hpp"
Parser parser;

#include <iostream>

using namespace nwr;

int main(int argc, char* argv[]) {
    int test1[] = {1, 3, 12, 28, 4};
    LegacyForwardIterator<int> test;
    LegacyOutputIterator<int> test3(test1);
    test++;
    std::cout << *test << std::endl;
    test3++; test3++;
    *test3 = *test;
    std::cout << *test << std::endl;
    *test = 100;
    std::cout << *test << std::endl;

    return 0;
}