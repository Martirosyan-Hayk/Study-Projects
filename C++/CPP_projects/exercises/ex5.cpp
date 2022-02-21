#include <iostream>

void max_in_min(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 9;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    max_in_min(arr, size);

    for (int i = 0; i < size; ++i)
    {

        std::cout << arr[i] << std::endl;
    }
}

void max_in_min(int*& ptr, const int& arr_size)
{
    int max_value = ptr[0];
    int min_value = ptr[0];
    int max_index = 0;
    int min_index = 0;
    int i = 1;

    for (; i < arr_size; ++i)
    {
        if (max_value < ptr[i])
        {
            max_value = ptr[i];
            max_index = i;
        }
        else if (min_value > ptr[i])
        {
            min_value = ptr[i];
            min_index = i;
        }
    }
    int tmp = max_value;
    ptr[max_index] = ptr[min_index];
    ptr[min_index] = tmp;
}