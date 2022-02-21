#include<iostream>

void count(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 16;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    count(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  count(int*& ptr, const int& arr_size)
{
    int count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (!(ptr[i] % 3))
        {
            ptr[i] = 0;
            ++count;
        }
    }

    std::cout << "Changed number count is " << count << std::endl;
}
