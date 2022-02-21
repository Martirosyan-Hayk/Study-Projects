#include<iostream>

void newarr(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 11;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - 50;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    newarr(arr, size);

}

void  newarr(int*& ptr, const int& arr_size)
{
    int sum = 0;
  
    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] < 0 && ptr[i] % 2)
        {
            sum += ptr[i];
        }

    }
    std::cout << "This is new array " << std::endl;

    for (int i = 0; i < arr_size; ++i)
    {
        if (!(i % 3))
        {
            ptr[i] = sum;
        }
        std::cout << ptr[i] << "  ";
    }

}
