#pragma once

#include "LegacyIterator.hpp"

namespace nwr{
    template<typename T>
    class LegacyOutputIterator : public LegacyIterator<T> {
    private:
        struct LegacyOutputProxy {
            T*& pointer;
            LegacyOutputProxy(T*& ptr);

            void operator=(const T& value);
        };
    public:
        using LegacyIterator<T>::ptr;

        LegacyOutputIterator(T *pointer);
        LegacyOutputIterator(const LegacyOutputIterator<T>& iter);
        LegacyOutputIterator<T>& operator=(const LegacyOutputIterator<T>& iter);
        ~LegacyOutputIterator();

        virtual LegacyOutputProxy operator*();
    };
}