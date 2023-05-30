#pragma once

#include "LegacyForwardIterator.hpp"

namespace nwr {
    template<typename T>
    class LegacyBidirectionalIterator : public LegacyForwardIterator<T> {
    public:
        using LegacyIterator<T>::ptr;

        LegacyBidirectionalIterator();
        LegacyBidirectionalIterator(T *pointer);
        LegacyBidirectionalIterator(const LegacyBidirectionalIterator<T>& iter);
        LegacyBidirectionalIterator& operator=(const LegacyBidirectionalIterator<T>& iter);
        ~LegacyBidirectionalIterator();

        virtual LegacyBidirectionalIterator<T> operator--();
        virtual LegacyBidirectionalIterator<T> operator--(int);
    };
}