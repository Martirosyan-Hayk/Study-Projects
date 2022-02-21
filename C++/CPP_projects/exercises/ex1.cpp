#include <iostream>

int count_even_numbers(int*, const int&);

int main()
{
    srand(time(NULL));
   const int size = 14;
    int arr[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000 + 1;
    }

    std::cout << count_even_numbers(arr, size);
}

int count_even_numbers(int* ptr, const int& arr_size)
{
    int count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (!(ptr[i] % 2))
        {
            ++count;
        }
    }

    return count;

}