#pragma once

#include "LegacyIterator.hpp"

namespace nwr {
    template<typename T>
    class LegacyInputIterator : public LegacyIterator<T> {
    public:
        using LegacyIterator<T>::ptr;

        LegacyInputIterator(T *pointer);
        LegacyInputIterator(const LegacyInputIterator<T>& iter);
        LegacyInputIterator& operator=(const LegacyInputIterator<T>& iter);
        ~LegacyInputIterator();

        virtual bool operator==(const LegacyInputIterator<T>& iter) const;
        virtual bool operator!=(const LegacyInputIterator<T>& iter) const;

        virtual const T& operator*() const &;
    };
}