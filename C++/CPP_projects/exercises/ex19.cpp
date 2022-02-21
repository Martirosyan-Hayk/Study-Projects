#include<iostream>

void count(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 19;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000 - rand() % 200;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    count(arr, size);
}

void  count(int*& ptr, const int& arr_size)
{
    bool min = false;
    int sum_numbers = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] < 0)
        {
            min = true;
            break;
        }
        sum_numbers += ptr[i];     
    }

    if (!min)
    {
        std::cout << "The negativ number is not found " << std::endl;
    }
    else
    {
        std::cout << "Sum of number to first negativ number " << sum_numbers << std::endl;
    }

}
