#include <queue>
#include "set.h"

// constructors

template <typename T>
nonstd::set<T>::set() : BST<T>() // default constructor
{
}
template <typename T>
nonstd::set<T>::set(const T &val) : BST<T>(val) // constructor with parametor
{
}
template <typename T>
nonstd::set<T>::set(const set<T> &rhs) : BST<T>(rhs) // copy constructor
{
}
template <typename T>
nonstd::set<T>::set(set<T> &&rhs) : BST<T>(std::move(rhs)) // move constructor
{
}
template <typename T>
nonstd::set<T>::~set() // destructor
{
}

//operators
template <typename T>
nonstd::set<T> &nonstd::set<T>::operator=(const set<T> &rhs) // copy operator=
{
    BST<T>::operator=(rhs);
    return *this;
}
template <typename T>
nonstd::set<T> &nonstd::set<T>::operator=(set &&rhs) // move operator=
{
    BST<T>::operator=(std::move(rhs));
    return *this;
}

// functions
template <typename T>
typename BST<T>::Node *nonstd::set<T>::insert(const T &rhs) // inserts elements
{
    return BST<T>::insert(BST<T>::getRoot(), rhs);
}
template <typename T>
void nonstd::set<T>::erase(const T &elem) // Removes specified elements from the container.
{
    BST<T>::deleteElement(elem);
}
template <typename T>
void nonstd::set<T>::clear() // clears the contents
{
    BST<T>::__delete(BST<T>::getRoot());
}
template <typename T>
void nonstd::set<T>::print() const
{
    BST<T>::inorder(BST<T>::getRoot());
}
template <typename T>
bool nonstd::set<T>::find(const T &key) const // finds element with specific key
{
    if (!BST<T>::getRoot())
    {
        return false;
    }

    std::queue<typename BST<T>::Node *> elements;
    elements.push(BST<T>::getRoot());

    while (!elements.empty())
    {
        typename BST<T>::Node *node = elements.front();
        if(key == node->m_data)
            return true;

        elements.pop();

        if (node->m_left)
            elements.push(node->m_left);

        if (node->m_right)
            elements.push(node->m_right);
    }

    return false;
}
template <typename T>
bool nonstd::set<T>::empty() const // checks whether the container is empty
{
    if(!BST<T>::getRoot())
        return true;

    return false;
}
template <typename T>
size_t nonstd::set<T>::size() const // returns the number of elements
{
    if (!BST<T>::getRoot())
    {
        return size_t(0);
    }

    std::queue<typename BST<T>::Node *> elements;
    elements.push(BST<T>::getRoot());

    size_t size = 0;
    while (!elements.empty())
    {
        typename BST<T>::Node *node = elements.front();
        ++size;

        elements.pop();

        if (node->m_left)
            elements.push(node->m_left);

        if (node->m_right)
            elements.push(node->m_right);
    }

    return size;
}
