#include<iostream>

void sum_numbers(int*&, const int&);


int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];
    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        //arr[i] = rand() % 100 - 27;
        std::cin >> arr[i];
    }
    std::cout << std::endl;


    sum_numbers(arr, size);

}

void  sum_numbers(int*& ptr, const int& arr_size)
{
    int sum = 0;
    bool neg = true;
    int start = -1;
    int end = -1;
    for (int i = 0; i < arr_size; ++i)
    {
        sum += ptr[i];
        if (ptr[i] < 0 && neg)
        {
            neg = false;
            start = i + 1;
      
        }
        if (!neg && ptr[i] == 0)
        {
            end = i;
            break;
        }
    }

    std::cout << "This is sum numbers " << sum << std::endl;

    std::cout << "This is numbers anti first negativ and first zero " << std::endl;

    for (; start != end && start != -1 && end != -1; ++start)
    {
        std::cout << ptr[start] << " ";
    }
  


}
