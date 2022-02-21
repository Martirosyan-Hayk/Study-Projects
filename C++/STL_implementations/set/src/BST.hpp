#include <vector>
#include <queue>
#include "BST.h"

// canstructors

// Node canstructors
template <typename T>
BST<T>::Node::Node() // default constructor Node
{
    m_data = 0;
    m_left = nullptr;
    m_right = nullptr;
}
template <typename T>
BST<T>::Node::Node(const T &data) // constructor whith parametors Node
{
    m_data = data;
    m_left = nullptr;
    m_right = nullptr;
}

// BST canstructors
template <typename T>
BST<T>::BST() // default constructor BST
{
    m_root = nullptr;
}
template <typename T>
BST<T>::BST(const T &data) // constructor whith parametors BST
{
    m_root->m_data = data;
    m_root->m_left = nullptr;
    m_root->m_right = nullptr;
}
template <typename T>
BST<T>::BST(const BST &rhs) : m_root{nullptr} // copy constructor BST
{
    if (!rhs.m_root)
    {
        m_root = nullptr;
    }
    else
    {
        std::queue<Node *> elements;
        elements.push(rhs.m_root);

        while (!elements.empty())
        {
            BST<T>::Node *node = elements.front();

            insert(m_root, node->m_data);

            elements.pop();

            if (node->m_left)
                elements.push(node->m_left);

            if (node->m_right)
                elements.push(node->m_right);
        }
    }
}
template <typename T>
BST<T>::BST(BST &&rhs) // move constructor BST
{
    m_root = rhs.m_root;
    rhs.m_root = nullptr;
}
template <typename T>
BST<T>::~BST() // destructor BST
{
    __delete(m_root);
}

// member private function
template <typename T>
void BST<T>::__delete(Node *root) // delete all tree
{
    if (!root)
    {
        return;
    }

    std::queue<Node *> elements;
    elements.push(root);

    while (!elements.empty())
    {
        BST<T>::Node *node = elements.front();
        elements.pop();

        if (node->m_left)
            elements.push(node->m_left);

        if (node->m_right)
            elements.push(node->m_right);

        delete node;
        node = nullptr;
    }
    m_root = nullptr;
}

// operator
template <typename T>
std::ostream &operator<<(std::ostream &out, const BST<T> &root) // operator ostreame (operator<<)
{
    root.inorder(root.getRoot());

    return out;
}
template<typename T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) // copy operator=
{
    if(this == &rhs)
        return *this;

    if (!rhs.m_root)
    {
        m_root = nullptr;
    }
    else
    {
        std::queue<Node *> elements;
        elements.push(rhs.m_root);

        while (!elements.empty())
        {
            BST<T>::Node *node = elements.front();

            insert(m_root, node->m_data);

            elements.pop();

            if (node->m_left)
                elements.push(node->m_left);

            if (node->m_right)
                elements.push(node->m_right);
        }
    }
    return *this;
}
template<typename T>
BST<T> &BST<T>::operator=(BST<T> &&rhs) // move operator=
{
    m_root = rhs.m_root;
    rhs.m_root = nullptr;

    return *this;
}

// member public functions
template <typename T>
typename BST<T>::Node *BST<T>::insert(Node *root, const T &value) // insert
{

    if (!m_root)
    {
        m_root = new BST<T>::Node(value);
    }

    if (!root)
    {
        return new BST<T>::Node(value);
    }

    if (value > root->m_data)
    {
        root->m_right = insert(root->m_right, value);
    }
    else if (value < root->m_data)
    {
        root->m_left = insert(root->m_left, value);
    }

    return root;
}
template <typename T>
void BST<T>::inorder(const Node *root) const // inorder traversal
{
    if (!root)
    {
        return;
    }

    inorder(root->m_left);
    std::cout << root->m_data << " ";
    inorder(root->m_right);
}
template <typename T>
void BST<T>::postorder(const Node *root) const // postorder traversal
{
    if (!root)
    {
        return;
    }
    postorder(root->m_left);
    postorder(root->m_right);
    std::cout << root->m_data << " ";
}
template <typename T>
void BST<T>::preorder(const Node *root) const // preorder traversal
{
    if (!root)
    {
        return;
    }

    std::cout << root->m_data << " ";
    preorder(root->m_left);
    preorder(root->m_right);
}
template <typename T>
void BST<T>::levelorder(Node *root) const // levelorder traversal
{
    if (!root)
    {
        return;
    }

    std::queue<Node *> elements;
    elements.push(root);

    while (!elements.empty())
    {
        BST<T>::Node *node = elements.front();
        std::cout << node->m_data << " ";
        elements.pop();

        if (node->m_left)
            elements.push(node->m_left);

        if (node->m_right)
            elements.push(node->m_right);
    }
}
template <typename T>
void BST<T>::find(const Node *root, const T &key) const // serche in tree
{
    if (!root)
    {
        return;
    }

    if (root->m_data == key)
    {
        std::cout << root->m_data;
        return;
    }

    if (key < root->m_data)
    {
        find(root->m_left, key);
    }

    find(root->m_right, key);
}
template <typename T>
void BST<T>::clear() // clear
{
    __delete(m_root);
}
template <typename T>
void BST<T>::deleteElement(const T &data) // delete element in tree
{
    std::vector<T> vecOfElements;
    std::queue<Node *> elements;
    elements.push(m_root);

    while (!elements.empty())
    {
        BST<T>::Node *node = elements.front();
        elements.pop();

        if (node->m_data != data)
            vecOfElements.push_back(node->m_data);

        if (node->m_left)
            elements.push(node->m_left);

        if (node->m_right)
            elements.push(node->m_right);
    }
    __delete(m_root);

    for (size_t indexElement = 0; indexElement < vecOfElements.size(); ++indexElement)
        insert(m_root, vecOfElements[indexElement]);
}

// geter
template <typename T>
typename BST<T>::Node *BST<T>::getRoot() const // geter of my m_root
{
    return m_root;
}
