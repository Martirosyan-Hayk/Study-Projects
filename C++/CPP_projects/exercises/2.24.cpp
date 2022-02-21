#include<iostream>


void new_arr(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 10;
    int* arr = new int[size];

    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 90 + 9;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    new_arr(arr, size);

}

void new_arr(int*& ptr, const int& size)
{
    
    int avg = 0;
    for (int i = 0; i < size; ++i)
    {
        avg += ptr[i];
    }

    std::cout << "This is new array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = avg - ptr[i];
        std::cout << ptr[i] << " ";
    }
}