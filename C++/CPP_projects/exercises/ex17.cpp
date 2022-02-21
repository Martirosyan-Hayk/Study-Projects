#include<iostream>


void count(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 15;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 20 - rand() % 15;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    count(arr, size);
}

void  count(int*& ptr, const int& arr_size)
{

    int negativ = 1;
    int no_negativ = 1;
    int zero = 0;

    for (int i = 1; i < arr_size; ++i)
    {
        if (ptr[i] < 0)
            ++negativ;
        else if (ptr[i] > 0)
            no_negativ *= ptr[i];
        else if (ptr[i] == 0)
            ++zero;
    }

    std::cout << "In array have " << negativ << " negativ elements, ";
    std::cout << zero << " zero and mul of positive numbers " << no_negativ << std::endl;
}
