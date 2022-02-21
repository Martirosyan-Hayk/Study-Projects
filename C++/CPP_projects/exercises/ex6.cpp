#include <iostream>

void even_or_odd(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 20;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    even_or_odd(arr, size);

  
}

void even_or_odd(int*& ptr, const int& arr_size)
{
    int even = 0;
    int odd = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (!(ptr[i] % 2))
        {
            ++even;
        }
        else if (ptr[i] % 2)
        {
            ++odd;
        }
    }
   
    if (even > odd)
        std::cout << "The even number count(" << even << ") is big odd numbers count (" << odd <<") " << std::endl;
    else if (even < odd)
        std::cout << "The odd number count (" << odd << ") is big even numbers count (" << even <<") " << std::endl;
    else
        std::cout << "The odd number count (" << odd << ") is equal even numbers count (" << even << ") " << std::endl;



}