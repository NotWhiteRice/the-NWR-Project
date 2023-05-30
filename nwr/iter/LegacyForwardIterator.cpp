#include "LegacyForwardIterator.hpp"

namespace nwr {
    template<typename T>
    LegacyForwardIterator<T>::LegacyForwardIterator() : LegacyInputIterator<T>(nullptr) {}

    template<typename T>
    LegacyForwardIterator<T>::LegacyForwardIterator(T *pointer) : LegacyInputIterator<T>(pointer) {}
    
    template<typename T>
    LegacyForwardIterator<T>::LegacyForwardIterator(const LegacyForwardIterator<T>& iter) : LegacyInputIterator<T>(iter.ptr) {}
        
    template<typename T>
    LegacyForwardIterator<T>& LegacyForwardIterator<T>::operator=(const LegacyForwardIterator<T>& iter) { ptr = iter.ptr; return *this; }
    
    template<typename T>
    LegacyForwardIterator<T>::~LegacyForwardIterator() { ptr = nullptr; }

    template<typename T>
    T& LegacyForwardIterator<T>::operator*() { return *ptr; }
}