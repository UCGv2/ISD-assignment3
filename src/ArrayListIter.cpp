//
// Created by fours on 9/21/2018.
//

#include "ArrayListIter.h"
template <typename T> bool ArrayListIterator<T>::operator==(const ArrayListIterator<T>& rhs) const
{
    return mPtr == rhs.mPtr;
}

template <typename T> bool ArrayListIterator<T>::operator!=(const ArrayListIterator<T>& rhs) const
{
    return mPtr != rhs.mPtr;
}
template <typename T> // const cast stuff?
T& ArrayListIterator<T>::operator*()
{
    return const_cast<T&>(static_cast<const ArrayListIterator<T>*>(this)->operator*());
}
template <typename T> const T& ArrayListIterator<T>::operator*() const
{
    return *mPtr;
}
template <typename T>
ArrayListIterator<T>::ArrayListIterator(T* ptr)
    : mPtr(ptr)
{
}
template <typename T> T* ArrayListIterator<T>::operator->()
{
    return const_cast<T*>(static_cast<const ArrayListIterator<T>*>(this)->operator->());
}

template <typename T> const T* ArrayListIterator<T>::operator->() const
{
    return mPtr;
}

template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator++()
{
    ++mPtr;
    return *this;
}

template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator++(int)
{
    mPtr++;
    return *this;
}
template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator--()
{
    --mPtr;
    return *this;
}
template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator--(int)
{
    mPtr--;
    return *this;
}

template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator+(int offset) const
{
    const_cast<ArrayListIterator<T>*>(this)->mPtr += offset;
    return *this;
}

template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator-(int offset) const
{
    const_cast<ArrayListIterator<T>*>(this)->mPtr -= offset;
    return *this;
}
template <typename T> int ArrayListIterator<T>::operator-(const ArrayListIterator<T>& rhs) const
{
    return (int)(mPtr - rhs.mPtr);
}

template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator+=(const int& offset)
{
    mPtr += offset;
    return *this;
}

template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator-=(const int& offset)
{
    mPtr -= offset;
    return *this;
}

template <typename X> ArrayListIterator<X> operator+(int offset, const ArrayListIterator<X>& iter)
{
    X* add = iter.mPtr + offset;
    ArrayListIterator<X> item(add);
    return item;
}

template <typename T> T& ArrayListIterator<T>::operator[](const int& index)
{
    return const_cast<T&>(static_cast<const ArrayListIterator<T>*>(this)->operator[](index));
}
template <typename T> const T& ArrayListIterator<T>::operator[](int index) const
{
    return mPtr[index];
}