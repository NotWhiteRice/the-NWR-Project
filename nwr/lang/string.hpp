#include <cstddef>
#include <vector>
#pragma once

using std::initializer_list;

namespace nwr {
    static size_t strlen(const char* text);

    class String {
        char* str;
    public:
        String();
        String(const String& str1);
        String& operator=(const String& str1);
        String(String&& str1);
        String& operator=(String&& str1);
        ~String();
    } typedef String;
}