#include<iostream>

void new_arr(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - rand() % 100;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    new_arr(arr, size);

}

void  new_arr(int*& ptr, const int& arr_size)
{
    long long mul_pos = 1;
    long long mul_neg = 1;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > 0)
            mul_pos *= ptr[i];
        else
            mul_neg += ptr[i];
    }

    std::cout << "Difference mul negativ numbers (" << mul_neg << ") and mul positiv nambers(";
    std::cout << mul_pos << ") is a " << mul_neg - mul_pos << std::endl;

}