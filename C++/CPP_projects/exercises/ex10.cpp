#include<iostream>

void negativ_numbers_avg(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 17;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000 - rand() % 1000;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    negativ_numbers_avg(arr, size);

   
}

void  negativ_numbers_avg(int*& ptr, const int& arr_size)
{
    int negativ_numbers_avg = 0;
    int count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] < 0)
        {
            negativ_numbers_avg += ptr[i];
            ++count;
        }
    }
    negativ_numbers_avg /= count;
    count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > negativ_numbers_avg)
        {
            ++count;
        }
    }

    std::cout << "count number hwo big avg negativ numbers " << count << std::endl;
}