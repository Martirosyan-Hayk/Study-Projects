#include<iostream>

void sort(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 12;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000 - rand() % 500;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    sort(arr, size);

    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

}

void  sort(int*& ptr, const int& arr_size)
{
    bool sorted = false;

    for (int i = 1; (i < arr_size) && !sorted; ++i)
    {
        sorted = true;
        for (int index = 0; index < arr_size - i; ++index)
        {
            int next_index = index + 1;
            if (ptr[index] < ptr[next_index])
            {
                int tmp = ptr[index];
                ptr[index] = ptr[next_index];
                ptr[next_index] = tmp;
                sorted = false;
            }
        }
    }

    std::cout << "add maximum number and minimum number " << ptr[0] + ptr[arr_size - 1] << std::endl;
}