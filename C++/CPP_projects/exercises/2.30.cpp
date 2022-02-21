#include<iostream>

void max_value(int*&, int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];
    int* arr2 = new int[size];
    std::cout << "Numbers of first array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Numbers of second array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = rand() % 100;
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;


    max_value(arr, arr2, size);

}

void  max_value(int*& ptr, int*& ptr2, const int& arr_size)
{
    int max_index_arr = 0;
    int max_index_arr2 = 0;
    for (int i = 1; i < arr_size; ++i)
    {
        if (ptr[max_index_arr] < ptr[i])
        {
            max_index_arr = i;
        }
        if (ptr2[max_index_arr2] < ptr2[i])
        {
            max_index_arr2 = i;
        }
    }
    int tmp = ptr[max_index_arr];
    ptr[max_index_arr] = ptr2[max_index_arr2];
    ptr2[max_index_arr2] = tmp;
   

    std::cout << "This is new first array " << std::endl;
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl << "This is new second array " << std::endl;
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << ptr2[i] << " ";
    }
    std::cout << std::endl;
}