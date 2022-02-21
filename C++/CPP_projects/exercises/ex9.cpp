#include<iostream>

void new_array(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 15;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    new_array(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  new_array(int*& ptr, const int& arr_size)
{
    int avg = 0;
    

    for (int i = 0; i < arr_size; ++i)
    {
        avg += ptr[i];
    }
    avg /= arr_size;

    for (int i = 0; i < arr_size; ++i)
    {
        ptr[i] = avg - ptr[i];
    }

}