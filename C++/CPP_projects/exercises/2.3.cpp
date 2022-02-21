#include<iostream>

void sum(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 17;
    int* arr = new int[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 90 + 9;
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;


    sum(arr, size);

}

void  sum(int*& ptr, const int& arr_size)
{
    long long sum_numbers = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        sum_numbers += ptr[i];
    }

    std::cout << "This is sum of numbers in the array " << sum_numbers << std::endl;
  
}