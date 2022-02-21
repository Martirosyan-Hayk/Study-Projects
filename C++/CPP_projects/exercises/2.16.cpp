#include<iostream>

void sum_numbers(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 10;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 -27;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    sum_numbers(arr, size);

}

void  sum_numbers(int*& ptr, const int& arr_size)
{
    int sum = 0;

    for (int i = 0; ptr[i] > 0 && i < arr_size; ++i)
    { 
            sum += ptr[i];
            if (ptr[i + 1] < 0)
                break;
    }

    std::cout << "This is sum nombers antil first negativ number " << sum << std::endl;


}
