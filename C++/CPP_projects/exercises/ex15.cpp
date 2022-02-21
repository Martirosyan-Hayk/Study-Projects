#include<iostream>

void sort(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 17;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    sort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void  sort(int*& ptr, const int& arr_size)
{
    
    for (int i = 0; i < arr_size; ++i)
    {
        for (int i = 0; i < arr_size; ++i)
        {
            if (i < 7)
            {
                if (ptr[i] > ptr[i + 1])
                {
                    int tmp = ptr[i];
                    ptr[i] = ptr[i + 1];
                    ptr[i + 1] = tmp;
                }
            }
            else if (i > 7)
            {
                if (ptr[i] < ptr[i + 1])
                {
                    int tmp = ptr[i];
                    ptr[i] = ptr[i + 1];
                    ptr[i + 1] = tmp;
                }
            }

        }
    }

} 
