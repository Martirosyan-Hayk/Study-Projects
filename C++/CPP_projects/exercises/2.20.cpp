#include<iostream>

void sequences(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - 27;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    sequences(arr, size);

}

void  sequences(int*& ptr, const int& arr_size)
{
    std::cout << "This is indexs of sequences number " << std::endl;
    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > ptr[i + 1])
        {
            std::cout << i << " ";
            ++i;
            while (ptr[i] > ptr[i + 1])
            {
                std::cout << i << " ";
                ++i;
            }
        }
    }
}