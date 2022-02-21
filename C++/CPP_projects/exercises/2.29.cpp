#include<iostream>

void remainder(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    remainder(arr, size);

}

void  remainder(int*& ptr, const int& arr_size)
{
    int avg = 0;
    int sum_odd_numbers = 0;
    int sum_even_numbers = 0;
    for (int i = 0; i < arr_size; ++i)
    {
        avg += ptr[i];
    }
    avg /= (arr_size - 1);

    std::cout << "Percentage of elements in avg: avg = " << avg << std::endl;
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << "Index of element: " << i << " : Percentage of elements in avg: " <<  ptr[i] % avg << " :" << std::endl;
    }
}