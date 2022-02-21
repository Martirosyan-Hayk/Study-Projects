#include<iostream>

void newarr(double*&, double&,const int&);


int main()
{
    srand(time(NULL));

    const int size = 10;
    double* arr = new double[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (double)rand() / (double)RAND_MAX;
        std::cout << arr[i] << " ";
    }
    double num;
    std::cout << std::endl <<"Enter the number " << std::endl;
    std::cin >> num;
    std::cout << std::endl;


    newarr(arr, num, size);

}

void  newarr(double*& ptr, double& key, const int& arr_size)
{
    double max = ptr[0];
    int index = 0;
    
    for (int i = 1; i < arr_size; ++i)
    {
        if (ptr[i] - key > max)
        {
            max = ptr[i];
            index = i;
        }
    }

    std::cout << "This is most remote of your enterd number " << std::endl;
    std::cout << "Number is " << max << " index is " << index << std::endl;


}
