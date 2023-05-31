#include <cstddef>
#pragma once

namespace nwr {
    void memcopy(void *dest, const void *src, size_t count);
    void memmove(void *dest, void *src, size_t count);
    void memset(void *dest, char ch, size_t count);
}