#pragma once

#include "LegacyInputIterator.hpp"

namespace nwr {
    /// @brief A read-write left to right iterator
    /// @tparam T The datatype this iterator works on [default = char]
    /// @note All default-constructed iterators access the same in situ reservoir--a 10000-char-long array
    /// @note May cause undefined behavior if T isn't char on a default-constructed iterator
    template<typename T = char>
    class LegacyForwardIterator : public LegacyInputIterator<T> {
    public:
        using LegacyIterator<T>::ptr;

        static char in_situ[10000];

        LegacyForwardIterator() : LegacyInputIterator<T>(*in_situ) {}
        LegacyForwardIterator(T *pointer) : LegacyInputIterator<T>(pointer) {}
        LegacyForwardIterator(const LegacyForwardIterator& iter) : LegacyInputIterator<T>(iter.ptr) {}
        LegacyForwardIterator& operator=(LegacyForwardIterator& iter) { ptr = iter.ptr; return *this; }
        ~LegacyForwardIterator() { ptr = nullptr; }

        /// @brief Accesses the current position of the iterator 
        virtual T& operator*() { return *ptr; }
    };
}