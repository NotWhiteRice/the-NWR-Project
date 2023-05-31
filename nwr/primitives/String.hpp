#pragma once

#include "Character.hpp"

namespace nwr {

    /// @brief Returns the length of a given null-terminated C string
    int strlen(const char* text);

    /// @brief Returns true if the two given C strings are equal
    /// @note If two C strings have the same sequence of characters until the null terminator and end at the same place, they are considered equal.
    bool strcomp(const char* text1, const char* text2);

    /// @brief A null-terminated sequence of characters
    /// @note Supported character encodings: UTF-8
    class String {
    private:
        Character *str;

    public:
        String();
        String(const String& str1);
        String& operator=(const String& str1);
        String(String&& str1);
        String& operator=(String&& str1);
        ~String();

        /// @brief Returns the size (in bytes) of the string (including the null terminator)
        int size() const;
        /// @brief Returns the amount of characters in the string (not including null terminator) 
        int length() const;
    };
}