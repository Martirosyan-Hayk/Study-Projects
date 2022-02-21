#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <iostream>

template <typename T>
class BST
{
protected:
    // member struct
    struct Node
    {
        T m_data;
        Node *m_left;
        Node *m_right;
        Node();          // default constructor Node
        Node(const T &); // constructor whith parametors Node
    };

public:
    // canstructors
    BST();            // default constructor BST
    BST(const T &);   // constructor whith parametors BST
    BST(const BST &); // copy constructor BST
    BST(BST &&);      // move constructor BST
    virtual ~BST();   // destructor BST

public:
    // operator<<
    template <typename>
    friend std::ostream &operator<<(std::ostream &, const BST<T> &); // operator ostreame (operator<<)
public:
    BST &operator=(const BST<T> &); // copy operator=
    BST &operator=(BST<T> &&);      // move operator=
public:
    // member public functions
    Node *insert(Node *, const T &);          // insert
    void inorder(const Node *) const;         // inorder traversal
    void postorder(const Node *) const;       // postorder traversal
    void preorder(const Node *) const;        // preorder traversal
    void levelorder(Node *) const;            // levelorder traversal
    void find(const Node *, const T &) const; // find in tree
    void clear();                             // clear
    void deleteElement(const T &);            // delete element in tree
    Node *getRoot() const;                    // geter of my m_root

private:
    // member pointer
    Node *m_root;

protected:
    // member private function
    void __delete(Node *); // delete all tree
};

#include "BST.hpp"

#endif //_BINARY_SEARCH_TREE_!
