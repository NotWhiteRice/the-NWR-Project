#pragma once

namespace nwr {
    template<typename T>
    class LegacyIterator {
    protected:

        /// @brief The current position of the iterator
        T *ptr;
    public:

        LegacyIterator(T* pointer) : ptr(pointer) {}
        LegacyIterator(const LegacyIterator& iter) : ptr(iter.ptr) {}
        LegacyIterator& operator=(LegacyIterator& iter) { ptr = iter.ptr;}
        ~LegacyIterator() { ptr = nullptr; }

        /// @brief Pre-increments the iterator
        /// @note [0, 1, 2, 3] -> [1, 2, 3] 
        virtual LegacyIterator<T> operator++() { ptr++; return *this; }

        /// @brief Post-increments the iterator
        /// @note [0, 1, 2, 3] -> [0, 1, 2, 3] 
        virtual LegacyIterator<T> operator++(int) { LegacyIterator<T> temp = *this; ptr++; return temp; }
    };
}