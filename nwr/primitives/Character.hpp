#pragma once

#include <iostream>
using std::ostream;

namespace nwr {
    /// @brief A single character
    /// @note Not for use manipulating memory, for memory manipulation use std::bitset
    /// @note Supported encodings: UTF-8
    class Character {
    private:
        char *chr;

    public:
        Character();
        Character(const Character& ch);
        Character& operator=(const Character& ch);
        Character(Character&& ch);
        Character& operator=(Character&& ch);
        ~Character();

        Character(const char ch);
        Character(const short sh);
        Character(const int i);

        /// @brief Returns the amount of bytes the character comprises (UTF-8 encoding, but of arbitrary length)
        /// @note worst: O(n), best: O(1)
        inline char size() const;

        friend ostream& operator<<(ostream& out, const Character& ch);
    };
}