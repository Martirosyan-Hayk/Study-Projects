#include<iostream>


void zero(int*&, int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 12;
    int* arr = new int[size];
    int* arr2 = new int[size];
    std::cout << "Numbers of first array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 20 -6;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Numbers of second array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = rand() % 20 -6;
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    zero(arr, arr2, size);

}

void zero(int*& ptr,int*& ptr2, const int& size)
{
    for (int i = 0; i < size; ++i)
    {

        for (int j = 0; j < size; ++j)
        {
           
            if (ptr[i] == ptr2[j])
            {
                ptr[i] = 0;
            }
        }
    }

    std::cout << "This is new array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << ptr[i] << " ";
    }
}
