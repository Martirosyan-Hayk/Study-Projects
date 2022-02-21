#include<iostream>

void new_array(int*&, int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 10 ;
    int* arr = new int[size];
    int* arr2 = new int[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Numbers of array two " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = rand() % 100;
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    new_array(arr, arr2, size);

}

void  new_array(int*& ptr, int*& ptr2, const int& arr_size)
{
    int* newarr = new int[10];

    for (int i = 0; i < arr_size; ++i)
    {
        if(!(i % 2))
            newarr[i] = ptr[i + 1];
        else
            newarr[i] = ptr2[i - 1];
    }
 
    std::cout << "This is merg of two array " << std::endl;
    
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << newarr[i] << " ";

    }
}