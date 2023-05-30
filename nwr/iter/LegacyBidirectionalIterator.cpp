#include "LegacyBidirectionalIterator.hpp"

namespace nwr {
    template<typename T>
    LegacyBidirectionalIterator<T>::LegacyBidirectionalIterator() : LegacyForwardIterator<T>() {}
    
    template<typename T>
    LegacyBidirectionalIterator<T>::LegacyBidirectionalIterator(T *pointer) : LegacyForwardIterator<T>(pointer) {}
    
    template<typename T>
    LegacyBidirectionalIterator<T>::LegacyBidirectionalIterator(const LegacyBidirectionalIterator<T>& iter) : LegacyForwardIterator<T>(iter.ptr) {}
                
    template<typename T>
    LegacyBidirectionalIterator<T>& LegacyBidirectionalIterator<T>::operator=(const LegacyBidirectionalIterator<T>& iter) { ptr = iter.ptr; return *this; }
    
    template<typename T>
    LegacyBidirectionalIterator<T>::~LegacyBidirectionalIterator() { ptr = nullptr; }
    
    template<typename T>
    LegacyBidirectionalIterator<T> LegacyBidirectionalIterator<T>::operator--() { ptr--; return *this; }

    template<typename T>
    LegacyBidirectionalIterator<T> LegacyBidirectionalIterator<T>::operator--(int) { LegacyBidirectionalIterator<T> temp = *this; ptr--; return temp; }
}