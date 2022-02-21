#include<iostream>

void new_arr(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 19;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - rand() % 100;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    new_arr(arr, size);
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  new_arr(int*& ptr, const int& arr_size)
{
    int  max = ptr[0];
    

    for (int i = 0; i < arr_size; ++i)
    {
        if (max < ptr[i])
        {
            max = ptr[i];
        }
    }

    for (int i = 0; i < arr_size; ++i)
    {
        if (!(ptr[i] % 2))
        {
            ptr[i] = max;
        }
    }
  
    std::cout << "The highest value element is placed instead of even numbers " << std::endl;
}