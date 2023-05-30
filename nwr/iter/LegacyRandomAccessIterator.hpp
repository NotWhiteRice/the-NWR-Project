#pragma once

#include "LegacyBidirectionalIterator.hpp"

namespace nwr {
    template<typename T>
    class LegacyRandomAccessIterator : public LegacyBidirectionalIterator<T> {
    protected:
        T* fngr;
    public:
        using LegacyIterator<T>::ptr;

        LegacyRandomAccessIterator();
        LegacyRandomAccessIterator(T *pointer);
        LegacyRandomAccessIterator(const LegacyRandomAccessIterator<T>& iter);
        LegacyRandomAccessIterator& operator=(const LegacyRandomAccessIterator<T>& iter);
        ~LegacyRandomAccessIterator();

        LegacyRandomAccessIterator<T>& operator[](const int i);

        LegacyRandomAccessIterator<T>& operator+=(const int i);
        LegacyRandomAccessIterator<T>& operator-=(const int i);
        LegacyRandomAccessIterator<T> operator+(const int i) const;

        template<typename U>
        friend LegacyRandomAccessIterator<U> operator-(const LegacyRandomAccessIterator<U>& iter, const int i);

        bool operator==(const LegacyRandomAccessIterator<T>& iter) const;
        bool operator!=(const LegacyRandomAccessIterator<T>& iter) const;
        bool operator<(const LegacyRandomAccessIterator<T>& iter) const;
        bool operator>(const LegacyRandomAccessIterator<T>& iter) const;
        bool operator<=(const LegacyRandomAccessIterator<T>& iter) const;
        bool operator>=(const LegacyRandomAccessIterator<T>& iter) const;

        long long operator-(const LegacyRandomAccessIterator<T>& iter) const;
    };
}