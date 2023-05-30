#include "LegacyIterator.hpp"

namespace nwr {
    template<typename T>
    LegacyIterator<T>::LegacyIterator(T* pointer) : ptr(pointer) {}
    
    template<typename T>
    LegacyIterator<T>::LegacyIterator(const LegacyIterator<T>& iter) : ptr(iter.ptr) {}
    
    template<typename T>
    LegacyIterator<T>& LegacyIterator<T>::operator=(const LegacyIterator<T>& iter) { ptr = iter.ptr;}
    
    template<typename T>
    LegacyIterator<T>::~LegacyIterator() { ptr = nullptr; }
    
    template<typename T>
    LegacyIterator<T> LegacyIterator<T>::operator++() { ptr++; return *this; }
    
    template<typename T>
    LegacyIterator<T> LegacyIterator<T>::operator++(int) { LegacyIterator<T> temp = *this; ptr++; return temp; }
}