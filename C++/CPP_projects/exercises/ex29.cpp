#include<iostream>

void sub(float*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 18;
    float* arr = new float[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 18 + (-10.1588f);
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    sub(arr, size);

}

void  sub(float*& ptr, const int& arr_size)
{
    double mul = 1;
    double sum = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > 0)
            mul *= ptr[i];
        else
            sum += -ptr[i];
    }

    std::cout << "mul pasitiv sub sum negativ numbers is " << mul / sum;
}