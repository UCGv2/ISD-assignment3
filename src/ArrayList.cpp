/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: ArrayList.cpp
 */

#include <memory>
#include <stdexcept>

// safe bc no memory alloc and only primitive types
/**
 * Creates an ArrayList of size 0.
 */
template <typename T>
ArrayList<T>::ArrayList()
    : mArray()
    , mSize(0)
    , mCapacity(0)
{
}

/**
 * Creates an ArrayList of the provided size and fills it with the provided
 * value - default to the default value of the template type.
 * @param size size of the ArrayList to create
 * @param value value used to fill the ArrayList
 */
// make ctors safe perhaps with smart ptrs
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

/**
 * Creates a deep copy of the provided ArrayList
 * @param src ArrayList to copy
 */
// make mArray safe by handling its new operation
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

/**
 * Makes *this a deep copy of the provided ArrayList.
 * @param src ArrayList to copy
 * @return *this for chaining
 */

// this is probably not exception safe
template <typename T> ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& src)
{
    ArrayList<T> copy(src);
    mArray.swap(copy.mArray);
    mSize = copy.mSize;
    mCapacity = copy.mCapacity;
    return *this;
}

/**
 * Adds the provided element to the end of this ArrayList.  If the ArrayList needs to be
 * enlarged,
 * double the capacity from the current capacity, or go from zero to one.  Fill the empty
 * elements with
 * the default values for the template type.
 * @param value value to add
 * @return total array capacity
 */

template <typename T> const uint32_t& ArrayList<T>::add(const T& value)
{
    return add(mSize, value);
}

/**
 * Inserts the specified value into this ArrayList at the specified index.
 * The object is inserted before any previous element at the specified
 * location. If the ArrayList needs to be enlarged, continue doubling the capacity
 * from the current capacity until the desired index is in range.  Fill the empty
 * elements with the default value for the template type.
 * @param index location at which to insert the new element
 * @param value the element to insert
 * @return total array capacity
 */
// make new operations safe, edit to work for the other design
template <typename T> const uint32_t& ArrayList<T>::add(const uint32_t& index, const T& value)
{
    uint32_t capCopy = mCapacity;
    uint32_t nextSize = mSize + 1;
    if (capCopy == 0) {
        capCopy++;
        mArray.reset(new T[1]);
    }
    while (capCopy < index || nextSize > capCopy) {
        capCopy *= 2;
    }
    if (index < capCopy && index < nextSize) {
        ScopedArray<T> temp(new T[capCopy]);
        for (uint32_t i = 0; i < capCopy; ++i) {
            if (i < index) {
                temp[i] = mArray[i];
            } else if (i > index && i < nextSize) {
                temp[i] = mArray[i - 1];
            } else {
                temp[i] = T();
            }
        }
        mArray.swap(temp);
    }
    mArray[index] = value;
    mSize = nextSize;
    mCapacity = capCopy;
    return mCapacity;
}

/**
 * Clears this ArrayList, leaving it empty.
 */
// only unsafe if mArray is not initialized
template <typename T> void ArrayList<T>::clear()
{
    mArray.reset();
    mSize = 0;
    mCapacity = 0;
}

/**
 * Returns a const T & to the element stored at the specified index.
 * If the index is out of bounds, std::out_of_range is thrown with the index
 * as its message.
 * @param index the desired location
 * @return a const T & to the desired element.
 */
// doesn't alter anything just returns a value
template <typename T> const T& ArrayList<T>::get(const uint32_t& index) const
{
    if (index > mSize) {
        throw std::out_of_range(std::to_string(index));
    } else {
        return mArray[index];
    }
}

/**
 * Returns a T & to the element stored at the specified index.
 * If the index is out of bounds, std::out_of_range is thrown with the index
 * as its message.
 * @param index the desired location
 * @return a T & to the desired element.
 */
template <typename T> T& ArrayList<T>::get(const uint32_t& index)
{
    return const_cast<T&>(static_cast<const ArrayList<T>*>(this)->get(index));
}

/**
 * Returns a T & to the element stored at the specified index.
 * No range checking is performed.
 * Must call to the const operator[] - do not reimplement logic!
 * @param index the desired location
 * @return a T & to the desired element.
 */
template <typename T> T& ArrayList<T>::operator[](const uint32_t& index)
{
    return const_cast<T&>(static_cast<const ArrayList<T>*>(this)->operator[](index));
}

/**
 * Returns a const T & to the element stored at the specified index.
 * No range checking is performed.
 * @param index the desired location
 * @return a const T & to the desired element.
 */
template <typename T> const T& ArrayList<T>::operator[](const uint32_t& index) const
{
    return mArray[index];
}

/**
 * Empty check.
 * @return True if this ArrayList is empty and false otherwise.
 */
// no except
template <typename T> bool ArrayList<T>::isEmpty() const
{
    return !mArray && mSize == 0 && mCapacity == 0;
}

/**
 * Returns iterator to the beginning; in this case, a random access iterator
 * @return an iterator to the beginning of this ArrayList.
 */
// can these be combo'd
template <typename T> ArrayListIterator<T> ArrayList<T>::begin()
{
    ArrayListIterator<T> begin(mArray.get());
    return begin;
}

/**
 * Returns the past-the-end iterator of this ArrayList.
 * @return a past-the-end iterator of this ArrayList.
 */
template <typename T> ArrayListIterator<T> ArrayList<T>::end()
{
    ArrayListIterator<T> end(mArray.get() + mSize);
    return end;
}
/**
 * Returns const iterator to the beginning; in this case, a random access
 * iterator
 * @return an const iterator to the beginning of this ArrayList.
 */
template <typename T> ArrayListConstIterator<T> ArrayList<T>::begin() const
{
    ArrayListConstIterator<T> cbegin(mArray.get());
    return cbegin;
}

/**
 * Returns the past-the-end const iterator of this ArrayList.
 * @return a past-the-end const iterator of this ArrayList.
 */
template <typename T> ArrayListConstIterator<T> ArrayList<T>::end() const
{
    ArrayListConstIterator<T> cend(mArray.get() + mSize);
    return cend;
}

/**
 * Removes an element at the specified location from this ArrayList and
 * returns it. Elements following index are shifted down. If index is out of
 * range, std::out_of_range is thrown with index as its message.
 * @param index the desired location
 * @return a copy of the removed element.
 */
// safe because if exception is thrown remove will not happen
template <typename T> T ArrayList<T>::remove(const uint32_t& index)
{
    if (index > mCapacity || index >= mSize) {
        throw std::out_of_range(std::to_string(index));
    }

    T takeOut = mArray[index];
    mSize--;
    for (uint32_t i = index; i < mSize; i++) {
        mArray[i] = mArray[i + 1];
    }
    if (mSize == 0) {
        mArray.reset();
        mCapacity = 0;
    }
    return takeOut;
}

/**
 * Sets the element at the desired location to the specified value. If index
 * is out of range, std::out_of_range is thrown with index as its message.
 * @param index the location to change
 * @param value the new value of the specified element.
 */
// safe because the value is not set if an exception is thrown
template <typename T> void ArrayList<T>::set(const uint32_t& index, const T& value)
{
    if (index > mSize || mSize == 0) {
        throw std::out_of_range(std::to_string(index));
    }
    mArray[index] = value;
}

/**
 * Returns the size of this ArrayList.
 * @return the size of this ArrayList.
 */
// safe
template <typename T> uint32_t ArrayList<T>::size() const
{
    return mSize;
}