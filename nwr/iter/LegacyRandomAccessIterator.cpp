#include "LegacyRandomAccessIterator.hpp"

namespace nwr {
    template<typename T>
    LegacyRandomAccessIterator<T>::LegacyRandomAccessIterator() : LegacyBidirectionalIterator<T>() { fngr = ptr; }
    
    template<typename T>
    LegacyRandomAccessIterator<T>::LegacyRandomAccessIterator(T *pointer) : LegacyBidirectionalIterator<T>(pointer) { fngr = ptr; }
    
    template<typename T>
    LegacyRandomAccessIterator<T>::LegacyRandomAccessIterator(const LegacyRandomAccessIterator<T>& iter) : LegacyBidirectionalIterator<T>(iter.ptr) {fngr = iter.fngr; }
    
    template<typename T>
    LegacyRandomAccessIterator<T>& LegacyRandomAccessIterator<T>::operator=(const LegacyRandomAccessIterator<T>& iter) { ptr = iter.ptr; fngr = iter.fngr; return *this; }
    
    template<typename T>
    LegacyRandomAccessIterator<T>::~LegacyRandomAccessIterator() { ptr = nullptr; fngr = nullptr; }

    template<typename T>
    LegacyRandomAccessIterator<T>& LegacyRandomAccessIterator<T>::operator[](const int i) { ptr = fngr + i; return *this; }

    template<typename T>
    LegacyRandomAccessIterator<T>& LegacyRandomAccessIterator<T>::operator+=(const int i) { ptr += i; return *this; }
    
    template<typename T>
    LegacyRandomAccessIterator<T>& LegacyRandomAccessIterator<T>::operator-=(const int i) { ptr -= i; return *this; }
    
    template<typename T>
    LegacyRandomAccessIterator<T> LegacyRandomAccessIterator<T>::operator+(const int i) const { LegacyRandomAccessIterator<T> temp = *this; temp.ptr += i; return temp; }
    
    template<typename T>
    LegacyRandomAccessIterator<T> operator-(const LegacyRandomAccessIterator<T>& iter, const int i) { LegacyRandomAccessIterator<T> temp = iter; temp.ptr -= i; return temp; }

    template<typename T>
    bool LegacyRandomAccessIterator<T>::operator==(const LegacyRandomAccessIterator<T>& iter) const { return (fngr == iter.fngr) && (ptr == iter.ptr); }
    
    template<typename T>
    bool LegacyRandomAccessIterator<T>::operator!=(const LegacyRandomAccessIterator<T>& iter) const { return (fngr != iter.fngr) || (ptr != iter.ptr); }
    
    template<typename T>
    bool LegacyRandomAccessIterator<T>::operator<(const LegacyRandomAccessIterator<T>& iter) const { return (ptr - fngr) < (iter.ptr - iter.fngr); }
    
    template<typename T>
    bool LegacyRandomAccessIterator<T>::operator>(const LegacyRandomAccessIterator<T>& iter) const { return (ptr - fngr) > (iter.ptr - iter.fngr); }
    
    template<typename T>
    bool LegacyRandomAccessIterator<T>::operator<=(const LegacyRandomAccessIterator<T>& iter) const { return (ptr - fngr) <= (iter.ptr - iter.fngr); }

    template<typename T>
    bool LegacyRandomAccessIterator<T>::operator>=(const LegacyRandomAccessIterator<T>& iter) const { return (ptr - fngr) >= (iter.ptr - iter.fngr); }
    
    template<typename T>
    long long LegacyRandomAccessIterator<T>::operator-(const LegacyRandomAccessIterator<T>& iter) const { return (ptr - fngr) - (iter.ptr - iter.fngr); }
}