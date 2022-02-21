#include "Hector.h"
#include "Stack.h"

// constructors
template <typename T>
nonstd::Stack<T>::Stack() : Hector<T>() // default constructor
{
}
template <typename T>
nonstd::Stack<T>::Stack(const Stack &rhs) : Hector<T>(rhs) // copy constructor
{
}
template <typename T>
nonstd::Stack<T>::Stack(Stack &&rhs) : Hector<T>(std::move(rhs)) // move constructor
{
}
template <typename T>
nonstd::Stack<T>::~Stack() // destructor
{
}

// operators
template <typename T>
nonstd::Stack<T> &nonstd::Stack<T>::operator=(const Stack<T> &rhs) // copy operator=
{

    Hector<T>::operator=(rhs);
    return *this;
}
template <typename T>
nonstd::Stack<T> &nonstd::Stack<T>::operator=(Stack<T> &&rhs) // move operator=
{
    Hector<T>::operator=(rhs);
    return *this;
}

// functions
template <typename T>
T &nonstd::Stack<T>::top() // top
{
    return Hector<T>::back();
}
template <typename T>
const T &nonstd::Stack<T>::top() const // top for const object
{
    return Hector<T>::back();
}
template <typename T>
void nonstd::Stack<T>::push(const T &rhs) // push
{
    Hector<T>::push_back(rhs);
}
template <typename T>
void nonstd::Stack<T>::pop() // pop
{
    Hector<T>::pop_back();
}
template <typename T>
bool nonstd::Stack<T>::empty() const // empty
{
    Hector<T>::empty();
}
template <typename T>
size_t nonstd::Stack<T>::size() const // size
{
    Hector<T>::size();
}
