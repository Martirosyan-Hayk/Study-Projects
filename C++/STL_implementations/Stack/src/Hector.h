#ifndef _HECTOR_
#define _HECTOR_

#include <ostream>

namespace nonstd
{
    template <typename T>
    class Hector
    {
    public:
        // constructors
        Hector();                   // default constructor
        Hector(const Hector &);     // copy constructor
        Hector(Hector &&) noexcept; // move constructor
        virtual ~Hector();          // destructor

    public:
        // public operators
        const T &operator[](const int &) const;                                         // operator[]
        T &operator[](const int &);                                                     // operator[]
        Hector &operator=(const Hector &);                                              // copy operator=
        Hector &operator=(Hector &&) noexcept;                                          // move operator=
        Hector operator+(const Hector &);                                               // operator+
        Hector operator+=(const Hector &);                                              // operator+=
        bool operator==(const Hector &);                                                // operator==
        bool operator!=(const Hector &);                                                // operator!=
        friend std::ostream &operator<<(std::ostream &os, const nonstd::Hector<T> &rhs) // operator<<
        {
            for (int i = 0; i < rhs.size_; ++i)
            {
                os << rhs.ptrInArr_[i];
            }
            return os;
        }

    public:
        // public operator assignment other type
        template <typename R>
        Hector<T> &operator=(Hector<R> &); // operator=

    public:
        // public functions
        void push_back(const T &);            // push_back
        void push_front(const T &);           // push_front
        T &front();                           // front
        T &back();                            // back
        const T &front() const;               // front for const object
        const T &back() const;                // back for const object
        void reserve(size_t);                 // reserve
        size_t capacity() const;              // capacity
        size_t size() const;                  // size
        bool empty() const;                   // empty
        T ret_ptr(size_t);                    // return pointer
        void pop_back();                      // pop_back
        void resize(const size_t);            // resize
        void resize(const size_t, const T &); // resize with size

    private:
        //private members
        size_t capacity_;
        size_t size_;
        T *ptrInArr_;
    };
}

#include "Hector.hpp"

#endif //_HECTOR_!