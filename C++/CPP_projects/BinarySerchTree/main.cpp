#include "BST.h"
#include <iostream>


int main()
{

    BST<int> a;
    a.insert(a.getRoot(), 25);
    a.insert(a.getRoot(), 15);
    a.insert(a.getRoot(), 10);
    a.insert(a.getRoot(), 4);
    a.insert(a.getRoot(), 12);
    a.insert(a.getRoot(), 22);
    a.insert(a.getRoot(), 18);
    a.insert(a.getRoot(), 24);
    a.insert(a.getRoot(), 50);
    a.insert(a.getRoot(), 35);
    a.insert(a.getRoot(), 31);
    a.insert(a.getRoot(), 44);
    a.insert(a.getRoot(), 70);
    a.insert(a.getRoot(), 66);
    a.insert(a.getRoot(), 90);
    a.inorder(a.getRoot());
    std::cout << std::endl;
     a.levelorder(a.getRoot());
    std::cout << std::endl;
    a.preorder(a.getRoot());
     std::cout << std::endl;
     a.postorder(a.getRoot());
     std::cout << std::endl;
    a.serche(a.getRoot(), 70);
    a.deleteElement(25);
    std::cout << std::endl;
    std::cout << a << std::endl;
    
}
