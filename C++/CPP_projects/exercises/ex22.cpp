#include<iostream>

void sort(int*&, const int&);

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

    sort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  sort(int*& ptr, const int& arr_size)
{
    int* newarr = new int[arr_size];

    for (int i = 0; i < arr_size ; ++i)
    {
        newarr[i] = ptr[arr_size - 1 - i];
    }

    delete[] ptr;
    ptr = newarr;

    std::cout << "The array is opposite " << std::endl;

}