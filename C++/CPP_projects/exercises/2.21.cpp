#include<iostream>

void newarr(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 14;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 10;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    newarr(arr, size);

}

void  newarr(int*& ptr, const int& arr_size)
{
    
    int* new_arr = new int[arr_size];
    int count = 0;
    int count2 = 0;
    for (int i = 0; i < arr_size ; ++i)
    { 
        for (int j = 0; j < arr_size; ++j)
        {
            if (ptr[i] == ptr[j])
            {
                ++count;
            }
        }
        if (count < 3)
        {
            new_arr[count2] = ptr[i];
            ++count2;
        }
        count = 0;
    }

    for (int j = 0; j < count2; ++j)
    {
        std::cout << new_arr[j] << " ";
    }
}

