#include "Hector.h"

// constructors
template <typename T>
nonstd::Hector<T>::Hector() : capacity_{0}, size_{0}, ptrInArr_{nullptr} // default constructor
{
}
template <typename T>
nonstd::Hector<T>::Hector(const Hector<T> &rhs) // copy constructor
{
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    ptrInArr_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i)
    {
        ptrInArr_[i] = rhs.ptrInArr_[i];
    }
}
template <typename T>
nonstd::Hector<T>::Hector(Hector<T> &&rhs) noexcept // move constructor
{
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    ptrInArr_ = rhs.ptrInArr_;
    rhs.size_ = 0;
    rhs.capacity_ = 0;
    rhs.ptrInArr_ = nullptr;
}
template <typename T>
nonstd::Hector<T>::~Hector() // destructor
{
    delete[] ptrInArr_;
}

//public operators
template <typename T>
const T &nonstd::Hector<T>::operator[](const int &imdex) const // operator[]
{
    return ptrInArr_[index];
}
template <typename T>
T &nonstd::Hector<T>::operator[](const int &index) // operator[]
{
    return ptrInArr_[index];
}
template <typename T>
nonstd::Hector<T> &nonstd::Hector<T>::operator=(const Hector<T> &rhs) // copy operator=
{
    if (this == &rhs)
    {
        return *this;
    }

    if (ptrInArr_ != nullptr)
    {
        delete[] ptrInArr_;
    }
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    ptrInArr_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i)
    {
        ptrInArr_[i] = rhs.ptrInArr_[i];
    }

    return *this;
}
template <typename T>
nonstd::Hector<T> &nonstd::Hector<T>::operator=(Hector<T> &&rhs) noexcept // move operator=
{
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    ptrInArr_ = rhs.ptrInArr_;
    rhs.size_ = 0;
    rhs.capacity_ = 0;
    rhs.ptrInArr_ = nullptr;

    return *this;
}
template <typename T>
nonstd::Hector<T> nonstd::Hector<T>::operator+(const Hector<T> &rhs) // operator+
{
    Hector<T> result;
    result.size_ = size_ + rhs.size_;
    result.capacity_ = capacity_ + rhs.capacity_;
    result.ptrInArr_ = new T[result.capacity_];
    size_t i = 0;
    for (; i < size_; ++i)
    {
        result.ptrInArr_[i] = ptrInArr_[i];
    }
    for (size_t j = 0; j < rhs.size_; ++j, ++i)
    {
        result.ptrInArr_[i] = rhs.ptrInArr_[j];
    }

    return result;
}
template <typename T>
nonstd::Hector<T> nonstd::Hector<T>::operator+=(const Hector<T> &rhs) // operator+=
{
    if (rhs.ptrInArr_ == nullptr)
    {
        return *this;
    }

    capacity_ = capacity_ + rhs.capacity_;
    T *tmp = new T[capacity_];
    size_t i = 0;
    for (; i < size_; ++i)
    {
        tmp[i] = ptrInArr_[i];
    }
    for (size_t j = 0; j < rhs.size_; ++j, ++i)
    {
        tmp[i] = rhs.ptrInArr_[j];
    }
    size_ = size_ + rhs.size_;
    delete[] ptrInArr_;
    ptrInArr_ = tmp;

    return *this;
}
template <typename T>
bool nonstd::Hector<T>::operator==(const Hector<T> &rhs) // operator==
{
    if (this == &rhs)
    {
        return true;
    }

    if (size_ != rhs.size_)
    {
        return false;
    }

    for (size_t i = 0; i < size_; ++i)
    {
        if (ptrInArr_[i] != rhs.ptrInArr_[i])
        {
            return false;
        }
    }
    return true;
}
template <typename T>
bool nonstd::Hector<T>::operator!=(const Hector<T> &rhs) // operator!=
{
    return !(operator==(rhs));
}

// public operator assignment other type
template <typename T>
template <typename R>
nonstd::Hector<T> &nonstd::Hector<T>::operator=(Hector<R> &rhs) // operator=
{

    if (ptrInArr_ != nullptr)
    {
        delete[] ptrInArr_;
    }
    size_ = rhs.size();
    capacity_ = rhs.capacity();
    ptrInArr_ = new T[capacity_];

    for (size_t i = 0; i < size_; ++i)
    {
        ptrInArr_[i] = rhs.ret_ptr(i);
    }
    return *this;
}

//public functions
template <typename T>
void nonstd::Hector<T>::push_back(const T &element) // push_back
{
    if (ptrInArr_ == nullptr)
    {
        capacity_ = 1;
        ptrInArr_ = new T[capacity_];
    }
    else if (capacity_ == size_)
    {
        capacity_ = capacity_ * 2;

        T *tempPtrInNewArr = new T[capacity_];
        for (size_t i = 0; i < size_; ++i)
        {
            tempPtrInNewArr[i] = ptrInArr_[i];
        }
        delete[] ptrInArr_;
        ptrInArr_ = tempPtrInNewArr;
    }

    ptrInArr_[size_] = element;
    ++size_;
}
template <typename T>
void nonstd::Hector<T>::push_front(const T &element) // push_front
{
    if (ptrInArr_ == nullptr)
    {
        capacity_ = 1;
        ptrInArr_ = new T[capacity_];
        ptrInArr_[size_] = element;
        ++size_;
    }
    else if (capacity_ == size_)
    {
        capacity_ *= 2;

        T *tempPtrInNewArr = new T[capacity_];
        tempPtrInNewArr[0] = element;
        for (size_t i = 1; i < size_; ++i)
        {
            tempPtrInNewArr[i] = ptrInArr_[i - 1];
        }
        ++size_;
        delete[] ptrInArr_;
        ptrInArr_ = tempPtrInNewArr;
    }
}
template <typename T>
T &nonstd::Hector<T>::front() // front
{
    if (size_ > 0)
        return ptrInArr_[0];
    throw std::out_of_range("OUT_OF_RANGE");
}
template <typename T>
T &nonstd::Hector<T>::back() // back
{
    if (size_ > 0)
        return ptrInArr_[size_ - 1];
    throw std::out_of_range("OUT_OF_RANGE");
}
template <typename T>
const T &nonstd::Hector<T>::front() const // front for const object
{
    if (size_ > 0)
        return ptrInArr_[0];
    throw std::out_of_range("OUT_OF_RANGE");
}
template <typename T>
const T &nonstd::Hector<T>::back() const // back for const object
{
    if (size_ > 0)
        return ptrInArr_[size_ - 1];
    throw std::out_of_range("OUT_OF_RANGE");
}
template <typename T>
void nonstd::Hector<T>::reserve(size_t resSize) // reserve
{
    if (resSize <= capacity_)
    {
        return;
    }

    T *tempPtrInNewArr = new T[resSize];
    for (size_t i = 0; i < size_; ++i)
    {
        tempPtrInNewArr[i] = ptrInArr_[i];
    }
    delete[] ptrInArr_;
    ptrInArr_ = tempPtrInNewArr;
    capacity_ = resSize;
}
template <typename T>
size_t nonstd::Hector<T>::capacity() const // capacity
{
    return capacity_;
}
template <typename T>
size_t nonstd::Hector<T>::size() const // size
{
    return size_;
}
template <typename T>
bool nonstd::Hector<T>::empty() const // empty
{
    return (size_ == 0);
}
template <typename T>
void nonstd::Hector<T>::pop_back() // pop_back
{
    --size_;
}
template <typename T>
void nonstd::Hector<T>::resize(size_t newSize) // resize
{
    if (newSize > size_)
    {
        for (size_t i = size_; i <= newSize; ++i)
        {
            ptrInArr_[i] = 0;
        }
    }
    size_ = newSize;
}
template <typename T>
void nonstd::Hector<T>::resize(const size_t newSize, const T &value) // resize with size
{
    for (size_t i = size_; i <= newSize; ++i)
    {
        ptrInArr_[i] = value;
    }
    size_ = newSize;
}
template <typename T>
T nonstd::Hector<T>::ret_ptr(size_t ind) // return pointer
{
    return ptrInArr_[ind];
}
