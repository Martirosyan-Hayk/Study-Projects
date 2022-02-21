#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class BST
{
private:
    /* member struct */
    struct Node
    {
        T m_data;
        Node *m_left;
        Node *m_right;
        Node();          /* default constructor Node */
        Node(const T &); /* constructor whith parametors Node */
    };

public:
    /* canstructors */
    BST();          /* default constructor BST */
    BST(const T &); /* constructor whith parametors BST */
    ~BST();         /* destructor BST */

public:
    /* operator<< */
    template <typename>
    friend std::ostream &operator<<(std::ostream &, const BST<T> &); /* operator ostreame (operator<<) */

public:
    /* member public functions */
    Node *insert(Node *, const T &);            /* insert */
    void inorder(const Node *) const;           /* inorder traversal */
    void postorder(const Node *) const;         /* postorder traversal */
    void preorder(const Node *) const;          /* preorder traversal */ 
    void levelorder(Node *) const;              /* levelorder traversal */
    void serche(const Node *, const T &) const; /* serche in tree */
    void clear();                               /* clear */
    void deleteElement(const T &);              /* delete element in tree */
    Node *getRoot() const;                      /* geter of my m_root */

private:
    /* member pointer */
    Node *m_root;

private:
    /* member private function */
    void __delete(Node *); /* delete all tree */
};

#include "BST.hpp"

#endif /* _BINARY_SEARCH_TREE_! */
