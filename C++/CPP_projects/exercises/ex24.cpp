#include<iostream>

void new_arr(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - rand() % 200;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    new_arr(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  new_arr(int*& ptr, const int& arr_size)
{
    int sum = 0;
    int* new_arr = new int[arr_size];

    for (int i = 0; i < arr_size; ++i)
    {
        if(ptr[i] > 0)
           sum += ptr[i];
    }

    for (int i = 0; i < arr_size; ++i)
    {
        new_arr[i] = sum - ptr[i];
    }

    delete[] ptr;
    ptr = new_arr;

}