#include<iostream>

void mul_min(double*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 16;
    double* arr = new double[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (double)rand() / (double)RAND_MAX;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    mul_min(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  mul_min(double*& ptr, const int& arr_size)
{
    double min = ptr[0];
    int in = 0;
    for (int i = 0; i < arr_size; ++i)
    {
        if (min > ptr[i])
        {
            min = ptr[i];
            in = i;
        }
    }
    min *= 3;

    double tmp = ptr[arr_size - 1];
    ptr[arr_size - 1] = min;
    ptr[in] = tmp;

    std::cout << "Minimum valu are " << min << ":The number hase move with the last element " << std::endl;
}