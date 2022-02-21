#include<iostream>

void big_numbers_count(float*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 15;
    float* arr = new float[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (float)rand() / (float)RAND_MAX;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    big_numbers_count(arr, size);


}

void  big_numbers_count(float*& ptr, const int& arr_size)
{
    int count = 0;

    for (int i = 1; i < arr_size; ++i)
    {
        if (ptr[i] > ptr[0])
            ++count;
      
    }

    std::cout << "The count number hwo big first number is " << count << std::endl;



}