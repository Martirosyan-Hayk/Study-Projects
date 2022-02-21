#include<iostream>

void remainder(int*&, const int&);


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


    remainder(arr, size);

}

void  remainder(int*& ptr, const int& arr_size)
{
    int remainder = 0;
    int sum_odd_numbers = 0;
    int sum_even_numbers = 0;
    for (int i = 0; i < arr_size; ++i)
    {
        if (!(i % 2))
        {
            sum_even_numbers += ptr[i];
        }
        else
        {
            sum_odd_numbers += ptr[i];
        }
      
    }
    std::cout << "This is remainder of sub sum number ";
    std::cout << sum_even_numbers % sum_odd_numbers << ::std::endl;
}