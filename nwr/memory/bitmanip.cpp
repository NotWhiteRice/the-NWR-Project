#include "bitmanip.hpp"

namespace nwr {
    void memcopy(void *dest, const void *src, size_t count) {
        char *d = (char*) dest; const char *s = (const char*) src;
        while(count--)
            *d++ = *s++;
    }

    void memmove(void *dest, void *src, size_t count) {
        char *d = (char*) dest; char *s = (char*) src;
        while(count--) {
            *d++ = *s;
            *s++ = (char) 0;
        }
    }

    void memset(void *dest, char ch, size_t count) {
        char *d = (char*) dest;
        while(count--)
            *d++ = ch;
    }
}