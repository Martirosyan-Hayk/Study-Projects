#include<iostream>

void newarr(double*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 14;
    double* arr = new double[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (double)rand() / (double)RAND_MAX;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    newarr(arr, size);

}

void  newarr(double*& ptr, const int& arr_size)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < arr_size / 2; ++i)
    {
        ptr[i] = ptr[arr_size - i - 1];
        ++count;
    }
    std::cout << "This is new array " << std::endl;

    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << ptr[i] << "  ";
    }
    std::cout << "This is permutations " << count << std::endl;
}
