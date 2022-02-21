#include<iostream>

void sum(float*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 17;
    float* arr = new float[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (float)rand() / (float)RAND_MAX;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    sum(arr, size);
}

void  sum(float*& ptr, const int& arr_size)
{
    float min = ptr[0];
    int index = 0;

    for (int i = 1; i < arr_size; ++i)
    {
        if (min > ptr[i])
        {
            min = ptr[i];
            index = i;
        }
    }
   
    std::cout << "Sum of minimum value and index " << min + index << std::endl;
}