#include<iostream>


void bigger(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 9;
    int* arr = new int[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 28 - 8;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    bigger(arr, size);

}

void  bigger(int*& ptr, const int& arr_size)
{
    int max = ptr[0];
    int i = 0;

    for (; i < arr_size; ++i)
    {
        if (max < ptr[i])
        {
            max = ptr[i];
        }
     
    }

    std::cout << "This is max valu in array " << max << std::endl;
}
