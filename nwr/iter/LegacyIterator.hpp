#pragma once

namespace nwr {
    template<typename T>
    class LegacyIterator {
    protected:
        T *ptr;
    public:
        LegacyIterator(T* pointer);
        LegacyIterator(const LegacyIterator<T>& iter);
        LegacyIterator& operator=(const LegacyIterator<T>& iter);
        ~LegacyIterator();

        virtual LegacyIterator<T> operator++();
        virtual LegacyIterator<T> operator++(int);
    };
}