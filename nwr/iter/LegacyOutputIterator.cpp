#include "LegacyOutputIterator.hpp"

namespace nwr{
    template<typename T>
    LegacyOutputIterator<T>::LegacyOutputProxy::LegacyOutputProxy(T*& ptr) : pointer(ptr) {}

    template<typename T>
    void LegacyOutputIterator<T>::LegacyOutputProxy::operator=(const T& value) { *pointer = value; }

    template<typename T>
    LegacyOutputIterator<T>::LegacyOutputIterator(T *pointer) : LegacyIterator<T>(pointer) {}
    
    template<typename T>
    LegacyOutputIterator<T>::LegacyOutputIterator(const LegacyOutputIterator<T>& iter) : LegacyIterator<T>(iter.ptr) {}
    
    template<typename T>
    LegacyOutputIterator<T>& LegacyOutputIterator<T>::operator=(const LegacyOutputIterator<T>& iter) { ptr = iter.ptr; return *this; }
    
    template<typename T>
    LegacyOutputIterator<T>::~LegacyOutputIterator() { ptr = nullptr; }

    template<typename T>
    typename LegacyOutputIterator<T>::LegacyOutputProxy LegacyOutputIterator<T>::operator*() { return LegacyOutputProxy(ptr); }
}