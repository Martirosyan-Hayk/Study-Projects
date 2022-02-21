#include<iostream>

void max_and_min_difference(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 15;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000 - rand() % 500;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    max_and_min_difference(arr, size);

}

void  max_and_min_difference(int*& ptr, const int& arr_size)
{
    int max_value = ptr[0];
    int min_value = ptr[0];

    for (int i = 0; i < arr_size; ++i)
    {
        if (max_value < ptr[i])
            max_value = ptr[i];
   
        else if (min_value > ptr[i])
            min_value = ptr[i];
       
    }

    std::cout << "add maximum number and minimum number " << max_value + min_value << std::endl;
    std::cout << "difference maximum number and minimum number " << max_value - min_value << std::endl;

}