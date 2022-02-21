#include<iostream>

void count_even_number(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 14;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000 - rand() % 500;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    count_even_number(arr, size);


}

void  count_even_number(int*& ptr, const int& arr_size)
{
    int add_numbers = 0;
    int count = 0;

    for (int i = 0; i < arr_size; ++i)
    {
        if (ptr[i] > 0 && !(ptr[i] % 2))
        {
            add_numbers += ptr[i];
            ++count;
        }
    }

    std::cout << "count no negativ numbers is " << count << " add of this number is " << add_numbers << std::endl;
}