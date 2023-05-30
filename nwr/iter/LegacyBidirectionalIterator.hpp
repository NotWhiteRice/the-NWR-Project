#pragma once

#include "LegacyForwardIterator.hpp"

namespace nwr {
    
    /// @brief A read-write bidirectional iterator
    /// @tparam T The datatype this iterator works on [default = char]
    /// @note All default-constructed iterators access the same in situ reservoir--a 10000-char-long array
    /// @note May cause undefined behavior if T isn't char on a default-constructed iterator
    template<typename T = char>
    class LegacyBidirectionalIterator : public LegacyForwardIterator<T> {
        using LegacyIterator<T>::ptr;

        LegacyBidirectionalIterator() : LegacyForwardIterator<T>() {}
        LegacyBidirectionalIterator(T *pointer) : LegacyForwardIterator<T>(pointer) {}
        LegacyBidirectionalIterator(const LegacyBidirectionalIterator& iter) : LegacyForwardIterator<T>(iter.ptr) {}
        LegacyBidirectionalIterator& operator=(LegacyBidirectionalIterator& iter) { ptr = iter.ptr; return *this; }
        ~LegacyBidirectionalIterator() { ptr = nullptr; }

        /// @brief Pre-decrements the iterator by 1 
        /// @note [0, 1, 2, 3] -> [2, 1, 0]
        virtual LegacyBidirectionalIterator<T> operator--() { ptr--; return *this; }

        /// @brief Post-decrements the iterator by 1
        /// @note [0, 1, 2, 3] -> [3, 2, 1, 0]
        virtual LegacyBidirectionalIterator<T> operator--(int) { LegacyBidirectionalIterator<T> temp = *this; ptr--; return temp; }

    };
}