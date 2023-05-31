#include "Character.hpp"

#include "../memory/bitmanip.hpp"

namespace nwr {
    Character::Character() : chr(new char[1]{0}) {}
    Character::Character(const Character& ch) {
        char len = ch.size();
        chr = new char[len]{0};
        memcopy(chr, ch.chr, len);
    }
    Character& Character::operator=(const Character& ch) {
        char len = ch.size();
        chr = new char[len]{0};
        memcopy(chr, ch.chr, len);
        return *this;
    }
    Character::Character(Character&& ch) : chr(ch.chr) { ch.chr = nullptr; }
    Character& Character::operator=(Character&& ch) {
        chr = ch.chr;
        ch.chr = nullptr;
        return *this;
    }
    Character::~Character() { if(chr != nullptr) delete[] chr; }

    Character::Character(const char ch) {
        if(ch & 0xE0 == 0) chr = new char[1]{ch};
        else {
            chr = new char[2]{0};
            chr[0] = (0xC0 | (ch >> 6));
            chr[1] = (0x80 | (ch & 0x3F));
        }
    }
    Character::Character(const short sh) {
        if(sh > 0x07FF) {
            chr = new char[3]{0};
            chr[0] = (0xE0 | (sh >> 12));
            chr[1] = (0x80 | ((sh & 0x0FC0) >> 6));
            chr[2] = (0x80 | (sh & 0x003F));
        } else if(sh > 0x007F) {
            chr = new char[2]{0};
            chr[0] = (0xC0 | (sh >> 6));
            chr[1] = (0x80 | (sh & 0x003F));
        } else Character((char) sh);
    }
    Character::Character(const int i) {
        if(i > 0x7FFFFFFF) {
            chr = new char[7]{0};
            chr[0] = 0xFE;
            chr[1] = (0xFE | ((i & 0xB0000000) >> 30));
            chr[2] = (0x80 | ((i & 0x3F000000) >> 24));
            chr[3] = (0x80 | ((i & 0x00FC0000) >> 18));
            chr[4] = (0x80 | ((i & 0x0003F000) >> 12));
            chr[5] = (0x80 | ((i & 0x00000FC0) >> 6));
            chr[6] = (0x80 | (i & 0x0000003F));
        } else if(i > 0x03FFFFFF) {
            chr = new char[6]{0};
            chr[0] = (0xFC | ((i & 0x40000000) >> 30));
            chr[1] = (0x80 | ((i & 0x3F000000) >> 24));
            chr[2] = (0x80 | ((i & 0x00FC0000) >> 18));
            chr[3] = (0x80 | ((i & 0x0003F000) >> 12));
            chr[4] = (0x80 | ((i & 0x00000FC0) >> 6));
            chr[5] = (0x80 | (i & 0x0000003F));
        } else if(i > 0x0010FFFF) {
            chr = new char[5]{0};
            chr[0] = (0xF8 | ((i & 0x03000000) >> 24));
            chr[1] = (0x80 | ((i & 0x00FC0000) >> 18));
            chr[2] = (0x80 | ((i & 0x0003F000) >> 12));
            chr[3] = (0x80 | ((i & 0x00000FC0) >> 6));
            chr[4] = (0x80 | (i & 0x0000003F));
        } else if(i > 0x0000FFFF) {
            chr = new char[4]{0};
            chr[0] = (0xF0 | ((i & 0x001C0000) >> 18));
            chr[1] = (0x80 | ((i & 0x0003F000) >> 12));
            chr[2] = (0x80 | ((i & 0x00000FC0) >> 6));
            chr[3] = (0x80 | (i & 0x0000003F));
        } else Character((short) i);
    }

    inline char Character::size() const {
        int i = 0, j = 0;
        const char *ptr2 = (const char*) chr;
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

    ostream& operator<<(ostream& out, const Character& ch) {
        out.write((const char*) ch.chr, ch.size());
        return out;
    }
}
