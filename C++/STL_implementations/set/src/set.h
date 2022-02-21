#ifndef _SET_
#define _SET_

#include "BST.h"

namespace nonstd
{
    template <typename T>
    class set : private BST<T>
    {
    public:
        // constructors
        set();            // default constructor
        set(const T &);   // constructor whit parametor
        set(const set &); // copy constructor
        set(set &&);      // move constructor
        ~set();           // destructor
    public:
        // operators
        set &operator=(const set &); // copy operator=
        set &operator=(set &&);      // move operator=

    public:
        // functions
        typename BST<T>::Node *insert(const T &); // inserts elements
        void erase(const T &);                    // Removes specified elements from the container.
        void clear();                             // clears the contents
        void print() const;                       // print set
        bool find(const T &key) const;            // finds element with specific key
        bool empty() const;                       // checks whether the container is empty
        size_t size() const;                      // returns the number of elements
    };
}

#include "set.hpp"

#endif //_SET_
