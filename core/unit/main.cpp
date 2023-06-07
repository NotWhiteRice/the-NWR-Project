
import nwr.memory;
import nwr.primitive;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <conio.h>
using namespace nwr;

unsigned int page = 0;

void printPage( ) {
	system("cls");
	char hex[] = "000000";
	for(int i = 0; i < 6; i++) {
		char temp = ((page & (0x0000000F << (i * 4))) >> (i * 4));
		temp += (temp > 9) ? 'A' - 10 : '0';
		hex[5-i] = temp;
	}
	cout << "Page: " << page << "--0x" << hex << "XX" << endl;
	cout << "   0123456789ABCDEF" << endl;
	for(int i = 0; i < 16; i++) {
		cout << (char) (i + (i > 9 ? 0x37 : 0x30)) << "X ";
		for(int j = 0; j < 16; j++) {
			int v = 256 * page + 16 * i + j;
			if(v == 7 || v == 8 || v == 9 || v == 10 || v == 13) cout << " ";
			else cout << Character(v);
		}
		cout << endl;
	}
}

int main( ) {
	system("chcp 65001");
	printPage( );
	while(true) {
		int key;
		if(_kbhit) {
			key = _getch( );
			switch(key) {
				case 32:
					cin >> page;
					break;
				case 75:
					page--;
					if(page > 0x7FFFFF) page = 0x7FFFFF;
					break;
				case 77:
					page++;
					if(page > 0x7FFFFF) page = 0;
					break;
				default:
					cout << key;
					break;
			}
			printPage( );
		}
	}
	return 0;
}