#include<iostream>

void max_and_min_index(float*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 16;
    float* arr = new float[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (float)rand() / (float)RAND_MAX;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    max_and_min_index(arr, size);


}

void  max_and_min_index(float*& ptr, const int& arr_size)
{
    float max_value = ptr[0];
    float min_value = ptr[0];
    int max_index = 0;
    int min_index = 0;

    for (int i = 1; i < arr_size; ++i)
    {
        if (max_value < ptr[i])
        {
            max_value = ptr[i];
            max_index = i;
        }
        else if (min_value > ptr[i])
        {
            min_value = ptr[i];
            min_index = i;
        }

    }

    std::cout << " Max value index in a array is " << max_index << std::endl;
    std::cout << " Min value index in a array is " << min_index << std::endl;

}