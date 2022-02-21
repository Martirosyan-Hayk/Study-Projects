#include<iostream>

void sort(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 10;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - 32;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    sort(arr, size);

}

void sort(int*& ptr, const int& size)
{
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted; ++pass)
    {
        sorted = true;
        for (int index = 0; index < size - pass; ++index)
        {
            int next_index = index + 1;
            if (ptr[index] > ptr[next_index])
            {
                int tmp = ptr[index];
                ptr[index] = ptr[next_index];
                ptr[next_index] = tmp;
                sorted = false;
            }
        }
    }

    std::cout << "This is new sortid array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << ptr[i] << " ";
    }
}