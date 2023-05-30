#include "LegacyInputIterator.hpp"

namespace nwr {
    template<typename T>
    LegacyInputIterator<T>::LegacyInputIterator(T *pointer) : LegacyIterator<T>(pointer) {}
    
    template<typename T>
    LegacyInputIterator<T>::LegacyInputIterator(const LegacyInputIterator<T>& iter) : LegacyIterator<T>(iter.ptr) {}
    
    template<typename T>
    LegacyInputIterator<T>& LegacyInputIterator<T>::operator=(const LegacyInputIterator<T>& iter) { ptr = iter.ptr; return *this; }
    
    template<typename T>
    LegacyInputIterator<T>::~LegacyInputIterator() { ptr = nullptr; }

    template<typename T>
    bool LegacyInputIterator<T>::operator==(const LegacyInputIterator<T>& iter) const { return ptr == iter.ptr; }
    
    template<typename T>
    bool LegacyInputIterator<T>::operator!=(const LegacyInputIterator<T>& iter) const { return ptr != iter.ptr; }
    
    template<typename T>
    const T& LegacyInputIterator<T>::operator*() const & { return *ptr; }
}