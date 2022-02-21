#include <iostream>
#include"List.h"


int main()
{
    List<int> ls(1);
    ls.push_back(4);
    ls.push_back(-1);
    ls.push_back(7);
    ls.push_back(5);

    std::cout << ls << std::endl;

  

    std::cout << "iterators " << std::endl;

    for (List<int>::Iterator iterator = ls.begin(); iterator != ls.end(); ++iterator)
    {
        std::cout << *iterator << " ";

    }

    List<int>::Iterator iterator = ls.begin();
    *iterator = 5;
    std::cout << ls;
    return 0;
}
