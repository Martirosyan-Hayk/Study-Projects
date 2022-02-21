#include<iostream>


void formui(int*&, int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 10;
    int* arr_X = new int[size];
    int* arr_Y = new int[size];
    std::cout << "Numbers of first array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr_X[i] = rand() % 7 + 1;
        std::cout << arr_X[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Numbers of second array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr_Y[i] = pow(arr_X[i], 2) + 0.3;
        std::cout << arr_Y[i] << " ";
    }
    std::cout << std::endl;

    formui(arr_X, arr_Y, size);

}

void formui(int*& ptr_X,int*& ptr_Y, const int& size)
{
    int mul_even_index = 1;
    int mul_odd_index = 1;
    int P = 0;

    for (int i = 0; i < size; ++i)
    {
        if (!(i % 2))
        {
            mul_even_index = mul_even_index * ptr_X[i] * ptr_Y[i];
        }
        else
        {
            mul_odd_index = mul_odd_index * ptr_X[i] * ptr_Y[i];
        }
    }
  
    P = mul_odd_index % mul_even_index;
    std::cout << "This is P; P = x1y1 * x3y3* ... * x9y9 / x0y0 * x2y2* ... *x8y8 " << std::endl;
    std::cout << "The remainder of sub is " << P << std::endl;
  
}