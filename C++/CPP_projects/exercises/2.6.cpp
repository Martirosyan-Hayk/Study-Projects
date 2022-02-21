#include<iostream>
#include <cmath>

void new_arr(double*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 12;
    double* arr = new double[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = pow(i,2)-(2.0*i)+(19.3*cos(i)) ;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

      new_arr(arr, size);

}

void  new_arr(double*& ptr, const int& arr_size)
{
    double avg = 0;
    double* newarr = new double[arr_size];

    for (int i = 0; i < arr_size; ++i)
    {
        avg += ptr[i];
    }
    avg = avg / (arr_size - 1.0);

    int j = 0;
    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] < avg)
        {
            newarr[j] = ptr[i];
            ++j;
        }
    }

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > avg)
        {
            newarr[j] = ptr[i];
            ++j;
        }
    }
    std::cout << avg;
    std::cout << "This is new array " << std::endl;
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << newarr[i] << " ";
    }
}
