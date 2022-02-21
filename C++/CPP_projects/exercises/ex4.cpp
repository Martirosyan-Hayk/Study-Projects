#include <iostream>

void first_in_bigger(int*&, const int&);

int main()
{
    srand(time(NULL));
    const int size = 10;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    first_in_bigger(arr, size);

    for (int i = 0; i < size; ++i)
    {
      
        std::cout << arr[i] << std::endl;
    }
}

void first_in_bigger(int*& ptr, const int& arr_size)
{
    int max_value = ptr[0];
    int index = 0;
    for (int i = 1; i < arr_size; ++i)
    {
        if (max_value < ptr[i])
        {
            max_value = ptr[i];
            index = i;
        }
    }
    int tmp = ptr[0];
    ptr[0] = ptr[index];
    ptr[index] = tmp;
   

}