#pragma once

#include "LegacyInputIterator.hpp"

namespace nwr {
    template<typename T>
    class LegacyForwardIterator : public LegacyInputIterator<T> {
    public:
        using LegacyIterator<T>::ptr;

        LegacyForwardIterator();
        LegacyForwardIterator(T *pointer);
        LegacyForwardIterator(const LegacyForwardIterator<T>& iter);
        LegacyForwardIterator& operator=(const LegacyForwardIterator<T>& iter);
        ~LegacyForwardIterator();
 
        virtual T& operator*();
    };
}