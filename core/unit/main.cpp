
import nwr.memory;
import nwr.primitive;

#include <iostream>

using namespace nwr;

int main( ) {
	std::cout << "   0123456789ABCDEF" << std::endl;
	for(int i = 0; i < 16; i++) {
		std::cout << (char) (i + (i > 9 ? 0x37 : 0x30)) << ": ";
		for(int j = 0; j < 16; j++) {
			int v = 16 * i + j;
			if(v == 8 || v == 9 || v == 10 || v == 13) std::cout << " ";
			else std::cout << (unsigned char) v;
		}
		std::cout << std::endl;
	}
	printHeap( );
	std::cout << "It's just 10MB";

	while(true) {

	}
	return 0;
}