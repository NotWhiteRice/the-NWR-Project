#include <cstddef>
#include <vector>
#pragma once

using std::initializer_list;

/// @brief the NWR Project
namespace nwr {

    /// @brief Returns the length of a given C string
    /// @note The value is the index of the null terminator
    static size_t strlen(const char* text);


    /// @brief A null-terminated sequence of characters
    /// @brief [Doesn't support unicode]
    class String {

        /// @brief A dynamically allocated null-terminated sequence of characters
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