//
// Created by fours on 9/21/2018.
//

#include "ArrayList.h"
#include <iterator>
#include <stdexcept>

template <typename T>
ArrayList<T>::ArrayList()
    : mArray(nullptr)
    , mSize(0)
    , mCapacity(0)
{
}

template <typename T>
ArrayList<T>::ArrayList(const uint32_t& size, const T& value)
    : mArray(new T[size])
    , mSize(size)
    , mCapacity(size)
{
    for (size_t i = 0; i < size; ++i) {
        mArray[i] = value;
    }
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& src)
    : mArray(new T[src.mSize])
    , mSize(src.mSize)
    , mCapacity(src.mCapacity)
{
    for (size_t i = 0; i < src.mSize; ++i) {
        mArray[i] = src.mArray[i];
    }
}

template <typename T> ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& src)
{
    ArrayList<T> copy(src);
    mArray.swap(copy.mArray);
    mSize = copy.mSize;
    mCapacity = copy.mCapacity;
    return *this;
}

template <typename T> const uint32_t& ArrayList<T>::add(const T& value) {
        if (mCapacity == 0) {
            mCapacity = 1;
            mArray.reset(new T[1]);
        }
        mSize++;
        if (mSize > mCapacity) {
            mCapacity *= 2;
            ScopedArray<T> temp(new T[mCapacity]);
            for (uint32_t i = 0; i < mCapacity; i++) {
                if (i < mSize) {
                    temp[i] = mArray[i];
                }
                else {
                    temp[i] = T();
                }
            }
            mArray.swap(temp);
        }
        mArray[mSize - 1] = value;
        return mCapacity;
//    if(mSize ==0) {
//        return add(0,value);
//    }
//        return add(mSize, value);
    }

template <typename T> const uint32_t& ArrayList<T>::add(const uint32_t& index, const T& value)
{
    if (mCapacity == 0) {
        mCapacity++;
//        T* initmArray = new T[1];
        mArray.reset(new T[1]);
    }
    mSize++;
//    if (index > mCapacity) {
        while (index > mCapacity || mSize > mCapacity) {
            mCapacity *= 2;
        }
        if(index < mCapacity && index <mSize) {
            ScopedArray<T> temp(new T[mCapacity]);
            for (uint32_t i = 0; i < mSize; i++) {
                if (i < index) {
                    temp[i] = mArray[i];
                } else if (i == index) {
//                    temp[i] = value;
                } else if (i > index) {
                    temp[i] = mArray[i - 1];
                } else {
                    temp[i] = T();
        }
            }
            mArray.swap(temp);
        }
        mArray[index] = value;
    return mCapacity;
}

template <typename T> void ArrayList<T>::clear()
{
    for (uint32_t i = mSize; i > 0; --i) {
        mArray[i-1] = T();
        mSize--;
    }
    mArray.reset();
}

template <typename T> const T& ArrayList<T>::get(const uint32_t& index) const
{
    if (index > mSize) {
        throw std::out_of_range("Index out of range");
    } else {
        return mArray[index];
    }
}

template <typename T> T& ArrayList<T>::get(const uint32_t& index)
{
    if (index > mSize) {
        throw std::out_of_range("Index out of range");
    } else {
        return mArray[index];
    }
}

template <typename T> T& ArrayList<T>::operator[](const uint32_t& index)
{
    return const_cast<T&>(static_cast<const ArrayList<T>*>(this)->operator[](index));
}

template <typename T> const T& ArrayList<T>::operator[](const uint32_t& index) const
{
    return mArray[index];
}

template <typename T> bool ArrayList<T>::isEmpty() const
{
    return !mArray && mSize == 0;
}
template <typename T> ArrayListIterator<T> ArrayList<T>::begin()
{
    ArrayListIterator<T> begin(mArray.get());
    return begin;
}
template <typename T> ArrayListIterator<T> ArrayList<T>::end()
{
    ArrayListIterator<T> end(mArray.get() + mSize);
    return end;
}

template <typename T> ArrayListConstIterator<T> ArrayList<T>::begin() const
{
    ArrayListConstIterator<T> cbegin(mArray.get());
    return cbegin;
}
template <typename T> ArrayListConstIterator<T> ArrayList<T>::end() const
{
    ArrayListConstIterator<T> cend(mArray.get() + mSize);
    return cend;
}

template <typename T> T ArrayList<T>::remove(const uint32_t& index)
{
    if (index > mCapacity || mSize == 0) {
        throw std::out_of_range(std::to_string(index));
    }

    T takeOut = mArray[index];
    mSize--;
    for (uint32_t i = index; i < mSize; i++) {
        mArray[i] = mArray[i + 1];
    }
    if (mSize == 0) {
        mArray.reset(nullptr);
    }
    return takeOut;
}

template <typename T> void ArrayList<T>::set(const uint32_t& index, const T& value)
{
    if (index > mSize || mSize == 0) {
        throw std::out_of_range(std::to_string(index));
    }
    mArray[index] = value;
}

template <typename T> uint32_t ArrayList<T>::size() const
{
    return mSize;
}