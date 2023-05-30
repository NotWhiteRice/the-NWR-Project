#pragma once

namespace nwr{

    /// @brief An enforced, using a proxy object, write-only left to right iterator
    /// @tparam T The datatype this iterator works on
    template<typename T>
    class LegacyOutputIterator : virtual public LegacyIterator<T> {
    private:
        struct LegacyOutputProxy {
            T*& pointer;
            LegacyOutputProxy(T*& ptr) : pointer(ptr) {}

            /// @brief [write only] Accesses the current position of the iterator
            /// @param value [in, const] The value being written
            void operator=(const T& value) { *pointer = value; }
        };
    public:
        using LegacyIterator<T>::ptr;

        LegacyOutputIterator(T *pointer) : LegacyIterator<T>(pointer) {}
        LegacyOutputIterator(const LegacyOutputIterator& iter) : LegacyIterator<T>(iter.ptr) {}
        LegacyOutputIterator& operator=(LegacyOutputIterator& iter) { ptr = iter.ptr; return *this; }
        ~LegacyOutputIterator() { ptr = nullptr; }

        /// @brief Returns a proxy object that can only be written to
        virtual LegacyOutputProxy operator*() { return LegacyOutputProxy(ptr); }
    };
}