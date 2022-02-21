#include<iostream>


void renge_max_and_min(float*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 12;
    float* arr = new float[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (float)rand() / (float)RAND_MAX;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    renge_max_and_min(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  renge_max_and_min(float*& ptr, const int& arr_size)
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

    std::cout << "maximum to minimum have " << (max_index > min_index ? (max_index - min_index) : (min_index - max_index));
    std::cout << " element" << std::endl;

}
