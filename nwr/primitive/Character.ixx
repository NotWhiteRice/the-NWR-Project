#include <iostream>

export module nwr.primitive:Character;

using std::ostream;

import nwr.memory;

namespace nwr {
    export struct Character {
    private:
        char *chr;

    public:
        Character() : chr((char *) alloc(1)) { }
        Character(const Character &ch) {
            char len = ch.size( );
            chr = (char *) alloc(len);
            memcopy(chr, ch.chr, len);
        }
        Character &operator=(const Character &ch) {
            char len = ch.size( );
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
            if((ch & 0x80) == 0) {
                chr = (char *) alloc(1);
                chr[0] = ch;
            } else {
                chr = (char *) alloc(2);
                chr[0] = (0xC0 | (ch >> 6));
                chr[1] = (0x80 | (ch & 0x3F));
            }
        }
        Character(const short sh) {
            if(sh > 0x07FF) {
                chr = (char *) alloc(3);
                chr[0] = (0xE0 | (sh >> 12));
                chr[1] = (0x80 | ((sh & 0x0FC0) >> 6));
                chr[2] = (0x80 | (sh & 0x003F));
            } else if(sh > 0x007F) { 
                chr = (char *) alloc(2);
                chr[0] = (0xC0 | (sh >> 6));
                chr[1] = (0x80 | (sh & 0x003F));
            } else *this = Character((char) sh);
        }
        Character(const int i) { 
            if(i > 0x7FFFFFFF) {
                chr = (char *) alloc(7);
                chr[0] = 0xFE;
                chr[1] = (0xFE | ((i & 0xB0000000) >> 30));
                chr[2] = (0x80 | ((i & 0x3F000000) >> 24));
                chr[3] = (0x80 | ((i & 0x00FC0000) >> 18));
                chr[4] = (0x80 | ((i & 0x0003F000) >> 12));
                chr[5] = (0x80 | ((i & 0x00000FC0) >> 6));
                chr[6] = (0x80 | (i & 0x0000003F));
            } else if(i > 0x03FFFFFF) {
                chr = (char *) alloc(6);
                chr[0] = (0xFC | ((i & 0x40000000) >> 30));
                chr[1] = (0x80 | ((i & 0x3F000000) >> 24));
                chr[2] = (0x80 | ((i & 0x00FC0000) >> 18));
                chr[3] = (0x80 | ((i & 0x0003F000) >> 12));
                chr[4] = (0x80 | ((i & 0x00000FC0) >> 6));
                chr[5] = (0x80 | (i & 0x0000003F));
            } else if(i > 0x0010FFFF) {
                chr = (char *) alloc(5);
                chr[0] = (0xF8 | ((i & 0x03000000) >> 24));
                chr[1] = (0x80 | ((i & 0x00FC0000) >> 18));
                chr[2] = (0x80 | ((i & 0x0003F000) >> 12));
                chr[3] = (0x80 | ((i & 0x00000FC0) >> 6));
                chr[4] = (0x80 | (i & 0x0000003F));
            } else if(i > 0x0000FFFF) {
                chr = (char *) alloc(4);
                chr[0] = (0xF0 | ((i & 0x001C0000) >> 18));
                chr[1] = (0x80 | ((i & 0x0003F000) >> 12));
                chr[2] = (0x80 | ((i & 0x00000FC0) >> 6));
                chr[3] = (0x80 | (i & 0x0000003F));
            } else *this = Character((short) i);
        }

        inline char size( ) const {
            int i = 0, j = 0;
            const char *ptr2 = (const char *) chr;
            while(j == 0) {
                if(*ptr2 == 0xFF) {
                    ptr2++; i += 8; continue;
                } else if((*ptr2 & 0b11000000) == 0b11000000) {
                    if(((~(*ptr2)) & 0b11110000) == 0) j += 4;
                    if(((~(*ptr2)) & (0b11000000 >> j)) == 0) j += 2;
                    if(((~(*ptr2)) & (0b10000000 >> j)) == 0) j += 1;
                    break;
                }
                j = i == 0 ? 1 : *ptr2 >> 7;
                break;
            }
            return i + j;
        }

        friend ostream &operator<<(ostream &out, const Character &ch) {
            out.write((const char *) ch.chr, ch.size( ));
            return out;
        }

    } typedef UnicodeC;
}