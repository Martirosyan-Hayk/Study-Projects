#include<iostream>

void count(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 14;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    count(arr, size);

}

void  count(int*& ptr, const int& arr_size)
{
    int count_even_index = 0;
    long long mul_odd_numbers = 1;

    for (int i = 0; i < arr_size; ++i)
    {
        if (!(ptr[i] % 2))
            count_even_index += i;
        else
            mul_odd_numbers *= ptr[i];
    }
    
    std::cout << "Sum of even numbers index are " << count_even_index << std::endl;
    std::cout << "Mul of odd numbers are " << mul_odd_numbers << std::endl;

}