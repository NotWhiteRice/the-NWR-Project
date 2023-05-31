#include "String.hpp"

#include "../memory/bitmanip.hpp"

namespace nwr {

    int strlen(const char* text) {
        int len = 0;
        for(const char* ptr = text; *ptr++ != '\0'; len++);
        return len;
    }

    bool strcomp(const char* text1, const char* text2) {
        for(const char* A = text1, *B = text2; *A != '\0' && *B != '\0'; A++, B++)
            if(*A != *B) return false;
        return true;
    }

    String::String() : str(new Character[1]()) {}
    String::String(const String& str1) {
        int len = str1.length();
        str = new Character[len];
        memcopy(str, str1.str, str1.size());
    }
    String& String::operator=(const String& str1) {
        int len = str1.length();
        str = new Character[len];
        memcopy(str, str1.str, str1.size());
        return *this;
    }
    String::String(String&& str1) : str(str1.str) { str1.str = nullptr; }
    String& String::operator=(String&& str1) {
        str = str1.str;
        str1.str = nullptr;
        return *this;
    }
    String::~String() { if(str != nullptr) delete[] str; }

    int String::size() const { return strlen((char*) str); }

    int String::length() const {
        const char *ptr = (const char*) str;
        int len = 0;
        while(*ptr++ != '\0')
            if(*ptr & 0b11000000 == 0b11000000 || *ptr & 0b10000000 == 0) len++;
        return len;
    }
}