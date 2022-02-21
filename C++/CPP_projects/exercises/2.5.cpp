#include<iostream>

void dublikat(int*&, int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 10;
    int* X = new int[size];
    int* Y = new int[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        X[i] = rand() % 99;
        std::cout << X[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Numbers of array two " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        Y[i] = rand() % 99;
        std::cout << Y[i] << " ";
    }
    std::cout << std::endl;

    dublikat(X, Y, size);

}

void  dublikat(int*& ptr_X, int*& ptr_Y, const int& arr_size)
{

    
    int* newarr = new int[arr_size * 2];
    int count = 0;
    for (int i = 0; i < arr_size; i++)
    {
        
        for (int j = 0; j < arr_size; j++)
            if (ptr_X[j] == ptr_Y[i])
            {
                newarr[count++] = ptr_Y[i];
                break;
            }
    }

    for (int j = 0; j < count; ++j)
    {
        std::cout << newarr[j] << " ";
    }

}
