#include<iostream>

void new_array(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 8;
    int* arr = new int[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 90 +9;
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;


    new_array(arr, size);

}

void  new_array(int*& ptr, const int& arr_size)
{
    int* newarr = new int[arr_size];

    for (int i = 0; i < arr_size; ++i)
    {
        newarr[i] = ptr[i] % 10;
    }

    std::cout << "This is new array " << std::endl;
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << newarr[i] << "  ";
    }
    
}