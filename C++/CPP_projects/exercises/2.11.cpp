#include<iostream>
#include<cmath>

void new_array(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 9;
    int* arr = new int[size];
    
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 99 +9;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    
    std::cout << std::endl;

    new_array(arr, size);

}

void  new_array(int*& ptr, const int& arr_size)
{
    int sum = 0;
    for (int i = 0; i < arr_size; ++i)
    {
        sum += ptr[i];
    }

    std::cout << "This is new array " << std::endl;

    for (int i = 0; i < arr_size; ++i)
    {
        ptr[i] = sum;
        std::cout << ptr[i] << "  ";
    }


}
