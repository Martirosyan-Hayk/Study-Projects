#include<iostream>

void new_arr(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 17;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - rand() % 100;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    new_arr(arr, size);
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  new_arr(int*& ptr, const int& arr_size)
{
    int avg_pos_num = 0;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > 0)
        {
            avg_pos_num += ptr[i];
            ++count;
        }
    }
    avg_pos_num /= count;
    count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > avg_pos_num)
        {
            sum += ptr[i];
            ++count;
        }
    }

    std::cout << "Count " << count << " sum of numbers " << sum << std::endl;
}