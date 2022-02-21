#include <iostream>
#include "Forward_list.h"


int main()
{

    Forward_list<int> fl(8);
    //fl.push_front(1);
    fl.push_back(7);
    fl.push_back(8);
    fl.push_back(2);

    Forward_list<int> f2;
    //f2.pop_front();

    std::cout << fl << std::endl;

    if (f2 != fl)
    {
        std::cout << "yes";
    }

    std::cout << "iterators " << std::endl;

    for (Forward_list<int>::Iterator iterator = fl.begin(); iterator != fl.end(); iterator++)
    {
        std::cout << *iterator << " ";

    }

    return 0;
}
