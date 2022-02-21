#include <iostream>

void new_array_arithmetic_average(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 12;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

     new_array_arithmetic_average(arr, size);

    for (int i = 0; i < size; ++i)
    {
        if (i == 5)
        {
            std::cout << "arithmetic average of array ";
        }
        std::cout << arr[i] << std::endl; 
    }
}

void new_array_arithmetic_average(int*& ptr, const int& arr_size)
{
    int arithmetic_average = 0;

    int* new_arr = new int[arr_size];

    for (int i = 0; i < arr_size; ++i)
    {
        new_arr[i] = ptr[i];
        arithmetic_average += ptr[i];
    }
 
    new_arr[5] = (arithmetic_average / arr_size);
    delete[] ptr;
    ptr = new_arr;
 
}