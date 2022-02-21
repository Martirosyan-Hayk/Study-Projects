#include<iostream>

void sum_numbers(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 10;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - 27;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    sum_numbers(arr, size);

}

void  sum_numbers(int*& ptr, const int& arr_size)
{
    int count = 0;

    for (int i = 1; i < arr_size - 1; ++i)
    {
        if (ptr[i - 1] > ptr[i] && ptr[i + 1] > ptr[i])
            ++count;

    }

    std::cout << "This is sum nombers antil first negativ number " << count << std::endl;

}
