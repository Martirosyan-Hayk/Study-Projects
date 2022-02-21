#include<iostream>
#include <cmath>

void diferenc(double*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 16;
    double* arr = new double[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 28 -5.18f;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    diferenc(arr, size);

}

void  diferenc(double*& ptr, const int& arr_size)
{
    double sum_of_even_index_num = 0.0;
    double sum_sub_3 = 0.0;

  
    for (int i = 0; i < arr_size; ++i)
    {
        if (!(i % 2))
            sum_of_even_index_num += ptr[i];
        else if (!(i % 3))
            sum_sub_3 += ptr[i];
    }

    std::cout << "This is diferenc sun of even index numbers and sum of index hwo is sub in 3 " << sum_of_even_index_num / sum_sub_3 << std::endl;
}
