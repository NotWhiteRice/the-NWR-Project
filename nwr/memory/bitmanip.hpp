#include <cstddef>
#pragma once

namespace nwr {

    /// @brief Copies a specific amount of bytes from one pointer to another.
    /// @param dest [in] The pointer being copied to
    /// @param src [in, const] The pointer being copied from
    /// @param count [in] The amount of bytes being copied over
    /// @note byte order: L to R
    /// @note bit order: L to R
    void memcopy(void *dest, const void *src, size_t count);


    /// @brief Moves a specific amount of bytes from one pointer to another.
    /// @param dest [in] The pointer being transferred to
    /// @param src [in] The pointer being transferred from
    /// @param count [in] The amount of bytes being moved over
    /// @note byte order: L to R
    /// @note bit order: L to R
    void memmove(void *dest, void *src, size_t count);

    /// @brief Sets a specific amount of bytes after a given pointer to a single character
    /// @param dest [in] The pointer being written from
    /// @param ch [in] The filler character 
    /// @param count [in] The amount of bytes being set
    void memset(void *dest, char ch, size_t count);
}