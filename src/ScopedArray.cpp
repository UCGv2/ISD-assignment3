// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef SCOPEDARRAY_CPP
#define SCOPEDARRAY_CPP

template <class T>
ScopedArray<T>::ScopedArray(T* rhs)
    : array(rhs)
{
}

template <typename T> ScopedArray<T>::~ScopedArray()
{
    reset();
}

template <typename T> T* ScopedArray<T>::get() const
{
    return array;
}

template <typename T> const T& ScopedArray<T>::operator[](std::uint32_t pos) const
{
    return array[pos];
}

template <typename T> T& ScopedArray<T>::operator[](std::uint32_t pos)
{
    /* Simple solution */
    // return array[pos];
    /* Bonus solution - use of const_cast and static_cast */
    return const_cast<T&>(static_cast<const ScopedArray<T>*>(this)->operator[](pos));
}

template <typename T> ScopedArray<T>::operator bool() const
{
    return array != nullptr;
}

template <typename T> void ScopedArray<T>::swap(ScopedArray& rhs)
{
    std::swap(array, rhs.array);
}

template <typename T> T* ScopedArray<T>::release()
{
    T* tmp = array;
    array = nullptr;
    return tmp;
}

template <typename T> void ScopedArray<T>::reset(T* rhs)
{
    // Do nothing if resetting to self
    if (rhs != array) {
        T* tmp = array;
        array = rhs;
        delete[] tmp;
    }
}

#endif // SCOPEDARRAY_CPP
