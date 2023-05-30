#pragma once

#include "LegacyBidirectionalIterator.hpp"

namespace nwr {
    
    /// @brief A read-write random-access iterator
    /// @tparam T The datatype this iterator works on [default = char]
    /// @note All default-constructed iterators access the same in situ reservoir--a 10000-char-long array
    /// @note May cause undefined behavior if T isn't char on a default-constructed iterator
    template<typename T = char>
    class LegacyRandomAccessIterator : public LegacyBidirectionalIterator<T> {
    protected:
        /// @brief Always points to the original block
        T* fngr;
    public:
        using LegacyIterator<T>::ptr;

        LegacyRandomAccessIterator() : LegacyBidirectionalIterator<T>() { fngr = ptr; }
        LegacyRandomAccessIterator(T *pointer) : LegacyBidirectionalIterator<T>(pointer) { fngr = ptr; }
        LegacyRandomAccessIterator(const LegacyRandomAccessIterator& iter) : LegacyBidirectionalIterator<T>(iter.ptr) {fngr = iter.fngr; }
        LegacyRandomAccessIterator& operator=(LegacyRandomAccessIterator& iter) { ptr = iter.ptr; fngr = iter.fngr; return *this; }
        ~LegacyRandomAccessIterator() { ptr = nullptr; fngr = nullptr; }

        /// @brief Moves the iterator to the i-th block in the set
        /// @param i [in, const] The index the iterator will jump to
        LegacyRandomAccessIterator<T>& operator[](const int i) { ptr = fngr + i; return *this; }

        /// @brief Moves the iterator i blocks forward
        /// @param i [in, const] The length of the jump
        LegacyRandomAccessIterator<T>& operator+=(const int i) { ptr += i; return *this; }

        /// @brief Moves the iterator i blocks backward
        /// @param i [in, const] The length of the jump
        LegacyRandomAccessIterator<T>& operator-=(const int i) { ptr -= i; return *this; }

        /// @brief Returns an iterator i blocks forward
        /// @param i [in, const] The jump the next iterator will take
        LegacyRandomAccessIterator<T> operator+(const int i) const { LegacyRandomAccessIterator<T> temp = *this; temp.ptr += i; return temp; }

        /// @brief Returns an iterator i blocks backward
        /// @param iter [in, const] The original iterator
        /// @param i [in, const] The backwards jump the next iterator will take
        friend LegacyRandomAccessIterator<T> operator-(const LegacyRandomAccessIterator<T>& iter, const int i) { LegacyRandomAccessIterator<T> temp = iter; temp.ptr -= i; return temp; }

        /// @brief Returns if both iterators are on the same block and have the same starting position
        /// @param iter [in, const] The rhs iterator
        bool operator==(const LegacyRandomAccessIterator<T>& iter) const { return (fngr == iter.fngr) && (ptr == iter.ptr); }

        /// @brief Returns if both iterators are not on the same block or don't have the same starting position
        /// @param iter [in, const] The rhs iterator
        bool operator!=(const LegacyRandomAccessIterator<T>& iter) const { return (fngr != iter.fngr) || (ptr != iter.ptr); }

        /// @brief Returns if the lhs iterator is closer to its starting point than the rhs iterator
        /// @param iter1 [in, const] The lhs iterator
        /// @param iter2 [in, const] The rhs iterator
        friend bool operator<(const LegacyRandomAccessIterator<T>& iter1, const LegacyRandomAccessIterator<T>& iter2) { return (iter1.ptr - iter1.fngr) < (iter2.ptr - iter2.fngr); }
        
        /// @brief Returns if the lhs iterator is further from its starting point than the rhs iterator
        /// @param iter1 [in, const] The lhs iterator
        /// @param iter2 [in, const] The rhs iterator
        friend bool operator>(const LegacyRandomAccessIterator<T>& iter1, const LegacyRandomAccessIterator<T>& iter2) { return (iter1.ptr - iter1.fngr) > (iter2.ptr - iter2.fngr); }
        
        /// @brief Returns if the lhs iterator is closer to or equidistant from its starting point than the rhs iterator
        /// @param iter1 [in, const] The lhs iterator
        /// @param iter2 [in, const] The rhs iterator
        friend bool operator<=(const LegacyRandomAccessIterator<T>& iter1, const LegacyRandomAccessIterator<T>& iter2) { return (iter1.ptr - iter1.fngr) <= (iter2.ptr - iter2.fngr); }
        
        /// @brief Returns if the lhs iterator is further or equidistant from its starting point than the rhs iterator
        /// @param iter1 [in, const] The lhs iterator
        /// @param iter2 [in, const] The rhs iterator
        friend bool operator>=(const LegacyRandomAccessIterator<T>& iter1, const LegacyRandomAccessIterator<T>& iter2) { return (iter1.ptr - iter1.fngr) >= (iter2.ptr - iter2.fngr); }

        /// @brief Returns the difference between the two iterators indices
        /// @param iter1 [in, const] The lhs iterator
        /// @param iter2 [in, const] The rhs iterator
        friend long long operator-(const LegacyRandomAccessIterator<T>& iter1, const LegacyRandomAccessIterator<T>& iter2) { return (iter1.ptr - iter1.fngr) - (iter2.ptr - iter2.fngr); }
    };
}