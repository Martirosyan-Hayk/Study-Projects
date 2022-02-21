#ifndef _STACK_
#define _STACK_

#include "Hector.h"

namespace nonstd
{
    template <typename T>
    class Stack final : private Hector<T>
    {
    public:
        // constructors
        Stack();              // default constructor
        Stack(const Stack &); // copy constructor
        Stack(Stack &&);      // move constructor
        ~Stack();             // destructor

    public:
        // public operators
        Stack &operator=(const Stack &); // copy operator=
        Stack &operator=(Stack &&);      // move operator=

    public:
        // public functions
        T &top();             // top
        const T &top() const; // top for const object
        void push(const T &); // push
        void pop();           // pop
        bool empty() const;   // empty
        size_t size() const;  // size
    };
}
#include "Stack.hpp"

#endif //_STACK_!