#include<iostream>

void count_and_valu(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 12;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 ;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    count_and_valu(arr, size);

}

void  count_and_valu(int*& ptr, const int& arr_size)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] < ptr[arr_size - 1])
        {
            ++count;
            sum += ptr[i];
        }
    }

    std::cout << "In the array have " << count << " elementov value of which is biger second value " << std::endl;
    std::cout << "Sum of this number is " << sum << std::endl;
}


