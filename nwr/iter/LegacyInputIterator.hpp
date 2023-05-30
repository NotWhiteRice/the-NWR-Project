#pragma once
#include "LegacyIterator.hpp"

namespace nwr {

    /// @brief An enforced read-only left to right iterator
    /// @tparam T The datatype this iterator works on
    template<typename T>
    class LegacyInputIterator : public LegacyIterator<T> {
    public:
        using LegacyIterator<T>::ptr;

        LegacyInputIterator(T *pointer) : LegacyIterator<T>(pointer) {}
        LegacyInputIterator(const LegacyInputIterator& iter) : LegacyIterator<T>(iter.ptr) {}
        LegacyInputIterator& operator=(LegacyInputIterator& iter) { ptr = iter.ptr; return *this; }
        ~LegacyInputIterator() { ptr = nullptr; }

        /// @brief Returns whether or not two iterators are on the same block of memory
        /// @param iter [in, const] The iterator being compared
        virtual bool operator==(const LegacyInputIterator<T>& iter) const { return ptr == iter.ptr; }

        /// @brief Returns whether or not two iterators are on the same block of memory
        /// @param iter [in, const] The iterator being compared
        virtual bool operator==(const LegacyInputIterator<T>& iter) const { return ptr == iter.ptr; }
        virtual bool operator!=(const LegacyInputIterator<T>& iter) const { return ptr != iter.ptr; }

        /// @brief [read only] Accesses the current position the iterator 
        virtual const T& operator*() const & { return *ptr; }
    };
}