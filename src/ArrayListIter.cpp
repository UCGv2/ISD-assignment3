/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: ArrayListIter.cpp
 */

/**
 * Tests for iterator equality.
 * @param rhs The iterator to compare against.
 * @return True if *this and rhs point to the same element.
 */
template <typename T> bool ArrayListIterator<T>::operator==(const ArrayListIterator<T>& rhs) const
{
    return mPtr == rhs.mPtr;
}

/**
 * Tests for iterator inequality.
 * @param rhs The iterator to compare against.
 * @return False if *this and rhs point to the same element.
 */
template <typename T> bool ArrayListIterator<T>::operator!=(const ArrayListIterator<T>& rhs) const
{
    return mPtr != rhs.mPtr;
}

/**
 * Dereference operator.
 * @return A T & to the value pointed to by *this.
 */
template <typename T> T& ArrayListIterator<T>::operator*()
{
    return const_cast<T&>(static_cast<const ArrayListIterator<T>*>(this)->operator*());
}

/**
 * Dereference operator.
 * @return A constant T & to the value pointed to by *this.
 */
template <typename T> const T& ArrayListIterator<T>::operator*() const
{
    return *mPtr;
}

/**
 * Dereference operator.
 * @return A pointer to the value pointed to by this.
 */
template <typename T> T* ArrayListIterator<T>::operator->()
{
    return const_cast<T*>(static_cast<const ArrayListIterator<T>*>(this)->operator->());
}

/**
 * Dereference operator.
 * @return A pointer to the value pointed to by this.
 */
template <typename T> const T* ArrayListIterator<T>::operator->() const
{
    return mPtr;
}

/**
 * Preincrement operator.
 * @return *this after the increment.
 */
template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator++()
{
    ++mPtr;
    return *this;
}

/**
 * Postincrement operator.
 * @return The iterator before the increment.
 */
template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator++(int)
{
    ArrayListIterator<T> temp(*this);
    ++*this;
    return temp;
}

/**
 * Predecrement operator.
 * @return *this after the decrement.
 */
template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator--()
{
    --mPtr;
    return *this;
}

/**
 * Postdecrement operator.
 * @return The iterator before the decrement.
 */
template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator--(int)
{
    ArrayListIterator<T> temp(*this);
    --*this;
    return temp;
}

/**
 * Returns an iterator offset elements forward
 * @param offset distance to move forward
 * @return the moved iterator.
 */
template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator+(int offset) const
{
    const_cast<ArrayListIterator<T>*>(this)->mPtr += offset;
    return *this;
}

/**
 * Returns an iterator offset elements backwards
 * @param offset distance to move back
 * @return the moved iterator.
 */
template <typename T> ArrayListIterator<T> ArrayListIterator<T>::operator-(int offset) const
{
    const_cast<ArrayListIterator<T>*>(this)->mPtr -= offset;
    return *this;
}

/**
 * Iterator subtraction (equivalent to pointer subtraction).
 *
 * @param rhs Iterator to subtract
 * @return distance between iterators
 */
template <typename T> int ArrayListIterator<T>::operator-(const ArrayListIterator<T>& rhs) const
{
    return (int)(mPtr - rhs.mPtr);
}

/**
 * Increments this iterator by offset
 * @param offset distance to move forward
 * @return *this after the operation
 */
template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator+=(const int& offset)
{

    mPtr += offset;
    return *this;
}

/**
 * Decrements this iterator by offset
 * @param offset distance to move backwards
 * @return *this after the operation.
 */
template <typename T> ArrayListIterator<T>& ArrayListIterator<T>::operator-=(const int& offset)
{
    mPtr -= offset;
    return *this;
}

/**
 * Subscript operator.
 * Must call to const operator[].  Do not reimplement!!!
 * @param index offset from current position.
 * @return the T & to the value at the index offset from *this.
 */
template <typename T> T& ArrayListIterator<T>::operator[](const int& index)
{
    return const_cast<T&>(static_cast<const ArrayListIterator<T>*>(this)->operator[](index));
}

/**
 * Subscript operator.
 * @param index offset from current position.
 * @return the const T & to the value at the index offset from *this.
 */
template <typename T> const T& ArrayListIterator<T>::operator[](int index) const
{
    return mPtr[index];
}

/**
 * Creates an iterator pointing to the same element as the provided pointer.
 * @param ptr
 */
template <typename T>
ArrayListIterator<T>::ArrayListIterator(T* ptr)
    : mPtr(ptr)
{
}

/**
 * Free function to make arithmetic addition commutative.
 *
 * @param offset offset from current position
 * @param iter array list iterator to offset
 * @return an offset ArrayListIterator
 */
template <typename X> ArrayListIterator<X> operator+(int offset, const ArrayListIterator<X>& iter)
{
    X* add = iter.mPtr + offset;
    ArrayListIterator<X> item(add);
    return item;
}