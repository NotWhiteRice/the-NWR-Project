#include "string.hpp"
#include "../memory/bitmanip.hpp"

namespace nwr {
    size_t strlen(const char *text) {
        const char *txt = text;
        size_t i = 0;
        while(*txt++ != '\0') i++;
        return i;
    }

    String::String() : str(new char[1]{0}) {}

    String::String(const String& str1) {
        size_t len = strlen(str1.str);
        str = new char[len+1]{0};
        memcopy(str, str1.str, len);
    }

    String& String::operator=(const String& str1) {
        size_t len = strlen(str1.str);
        str = new char[len+1]{0};
        memcopy(str, str1.str, len);
        return *this;
    }

    String::String(String&& str1) : str(str1.str) { str1.str = nullptr; }

    String& String::operator=(String&& str1) {
        str = str1.str;
        str1.str = nullptr;
        return *this;
    }

    String::~String() { if(str != nullptr) delete[] str; }
}