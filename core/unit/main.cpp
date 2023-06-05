
import nwr.memory;
import nwr.primitive;

#include <iostream>

using namespace nwr;

int main( ) {
	std::cout << sizeof(char8_t) << std::endl;
	Character ch(0x265a);
	std::cout << ch << std::endl;
	printHeap( );
	return 0;
}