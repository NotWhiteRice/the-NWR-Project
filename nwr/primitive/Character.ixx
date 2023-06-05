#include <iostream>

export module nwr.primitive:Character;

using std::ostream;

import nwr.memory;


namespace nwr {
	export struct Character {
	private:
		char *chr;
	public:
		Character( ): chr((char *) alloc(1)) { }
		Character(const Character &ch) {
			size_t len = ch.size( );
			chr = (char *) alloc(len);
			memcopy(chr, ch.chr, len);
		}
		Character &operator=(const Character &ch) {
			size_t len = ch.size( );
			chr = (char *) alloc(len);
			memcopy(chr, ch.chr, len);
			return *this;
		}
		Character(Character &&ch): chr(ch.chr) {
			ch.chr = nullptr;
		}
		Character &operator=(Character &&ch) {
			chr = ch.chr;
			ch.chr = nullptr;
			return *this;
		}
		~Character( ) {
			if(chr != nullptr) free(chr);
		}

		Character(const char ch) {
			if((ch & 0x80) == 0x80) {
				chr = (char *) alloc(2);
				chr[0] = 0xC0 | (ch >> 6);
				chr[1] = 0x80 | (ch & 0x3F);
			} else {
				chr = (char *) alloc(1);
				chr[0] = ch;
			}
		}
		Character(const short sh) {
			if((sh & 0xFF80) == 0) *this = Character((char) sh);
			else if((sh & 0xF800) == 0) {
				chr = (char *) alloc(2);
				chr[0] = 0xC0 | ((sh & 0x07C0) >> 6);
				chr[1] = 0x80 | ((sh & 0x003F));
			} else {
				chr = (char *) alloc(3);
				chr[0] = 0xE0 | ((sh & 0xF000) >> 12);
				chr[1] = 0x80 | ((sh & 0x0FC0) >> 6);
				chr[2] = 0x80 | ((sh & 0x003F));
			}
		}
		Character(const int i) {
			if((i & 0xFFFF0000) == 0) *this = Character((short) i);
			else if((i & 0xFFE00000) == 0) {
				chr = (char *) alloc(4);
				chr[0] = 0xF0 | ((i & 0x001C0000) >> 18);
				chr[1] = 0x80 | ((i & 0x0003F000) >> 12);
				chr[2] = 0x80 | ((i & 0x00000FC0) >> 6);
				chr[3] = 0x80 | ((i & 0x0000003F));
			} else if((i & 0xFC000000) == 0) {
				chr = (char *) alloc(5);
				chr[0] = 0xF8 | ((i & 0x03000000) >> 24);
				chr[1] = 0x80 | ((i & 0x00FC0000) >> 18);
				chr[2] = 0x80 | ((i & 0x0003F000) >> 12);
				chr[3] = 0x80 | ((i & 0x00000FC0) >> 6);
				chr[4] = 0x80 | ((i & 0x0000003F));
			} else if((i & 0x80000000) == 0) {
				chr = (char *) alloc(6);
				chr[0] = 0xFC | ((i & 0x40000000) >> 30);
				chr[1] = 0x80 | ((i & 0x3F000000) >> 24);
				chr[2] = 0x80 | ((i & 0x00FC0000) >> 18);
				chr[3] = 0x80 | ((i & 0x0003F000) >> 12);
				chr[4] = 0x80 | ((i & 0x00000FC0) >> 6);
				chr[5] = 0x80 | ((i & 0x0000003F));
			} else {
				chr = (char *) alloc(7);
				chr[0] = 0xFE;
				chr[1] = 0x80 | ((i & 0xC0000000) >> 30);
				chr[2] = 0x80 | ((i & 0x3F000000) >> 24);
				chr[3] = 0x80 | ((i & 0x00FC0000) >> 18);
				chr[4] = 0x80 | ((i & 0x0003F000) >> 12);
				chr[5] = 0x80 | ((i & 0x00000FC0) >> 6);
				chr[6] = 0x80 | ((i & 0x0000003F));
			}
		}


		size_t size( ) const {
			size_t i = 0, j = 0;
			const char *ptr = chr;
			while(j == 0) {
				if(*ptr == 0xFF && ((i & 0b111) == 0)) { 
					i += 8;
					continue;
				} else if(((*ptr & 0xC0) != 0x80 && ((i & 0b111) != 0b111) && i != 0) || ((*ptr & 0xC0) == 0x80 && i == 0)) {
					throw "[ERROR--nwr.String] strcount(*cstr): The given C string must be encoded in UTF-8";
				} else {
					if((~(*ptr) & 0xF0) == 0) j += 4;
					if((~(*ptr) & (0xC0 >> j)) == 0) j += 2;
					if((~(*ptr) & (0x80 >> j)) == 0) j += 1;
					break;
				}
				j = (i == 0) ? 1 : *ptr >> 7;
			}
			return i + j;
		}

		friend ostream &operator<<(ostream &out, const Character &ch) {
			out << ch.chr;
			return out;
		}

	} typedef UnicodeC;
}