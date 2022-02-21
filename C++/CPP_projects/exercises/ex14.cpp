#include<iostream>

void replacement(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 17;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    replacement(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  replacement(int*& ptr, const int& arr_size)
{
    int sum_of_odd_numbers = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] % 2)
            sum_of_odd_numbers += ptr[i];
    }

    for (int i = 0; i < arr_size; ++i)
    {
        if (!(ptr[i] % 3))
            ptr[i] = sum_of_odd_numbers;
    }

}