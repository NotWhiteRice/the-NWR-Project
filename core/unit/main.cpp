
import nwr.memory;
import nwr.primitive;

#include <iostream>
using std::cout;
using std::endl;
using namespace nwr;

int main( ) {
	system("chcp 65001");
	cout << "All characters that can be put in console---" << endl;
	cout << "   0123456789ABCDEF" << endl;
	for(int i = 0; i < 16; i++) {
		cout << (char) (i + (i > 9 ? 0x37 : 0x30)) << "X ";
		for(int j = 0; j < 16; j++) {
			int v = 16 * i + j;
			if(v == 7 || v == 8 || v == 9 || v == 10 || v == 13) cout << " ";
			else cout << Character(v);
		}
		cout << endl;
	}
	cout << "--- Exceptions ---" << endl;
	cout << "07--Bell" << endl;
	cout << "08--Backspace" << endl;
	cout << "09--Tab" << endl;
	cout << "0A--New line" << endl;
	cout << "0D--Carriage return" << endl;
	cout << endl;

	Character ch(0x2265);
	cout << "0x2265--" << ch << endl;
	printHeap( );
	while(true) { }
	return 0;
}