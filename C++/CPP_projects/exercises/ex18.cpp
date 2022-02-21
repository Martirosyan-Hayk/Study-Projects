#include<iostream>

void count(float*&, const int&);

int main()
{
    srand(time_t(NULL));
    const int size = 12;
    float* arr = new float[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (float)rand() - (float)rand();
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    count(arr, size);
}

void  count(float*& ptr, const int& arr_size)
{
    float min = ptr[0];
    float max = ptr[0];

    for (int i = 1; i < arr_size; ++i)
    {
        if (max < ptr[i])
            max = ptr[i];
        else if (min > ptr[i])
            min = ptr[i];
    }

    std::cout << "the number intervals are [" << min << ";" << max << "]";
   
}
