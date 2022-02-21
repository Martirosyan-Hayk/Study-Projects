#include <iostream>

int big_number_count_of_arithmetic_average(int*&, const int&);

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

    std::cout << "There are " << big_number_count_of_arithmetic_average(arr, size) << " elements in the array that are bigger than the arithmetic average" << std::endl;
}

int big_number_count_of_arithmetic_average(int*& ptr, const int& arr_size)
{
    int arithmetic_average = 0;
    int count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        arithmetic_average += ptr[i];
    }

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > arithmetic_average / arr_size)
        {
            ++count;
        }
    }

    return count;
}