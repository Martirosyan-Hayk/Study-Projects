#include <iostream>
#include <vector>

int main()
{
    int size;
    std::cout << "enter size arrays ";
    std::cin >> size;

    int size1 = size + 1;

    int* arr = new int[size];
    int* arr1 = new int[size];
    int* res = new int[size1] {0};
    
    std::cout << "enter " << size << " numbers in first array";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    std::cout << std::endl;
    std::cout << "enter " << size << " numbers in secnd array";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr1[i];
    }
    int num;
    int mn = 0;
    int j = size1 - 1;
    for (int i = size - 1; i >= 0; --i)
    {
        num = arr[i] + arr1[i];
        if (num > 9)
        {
            res[j] = res[j] + (num % 10);
            mn = num / 10;
            res[j - 1] = res[j - 1] + mn;
            --j;
        }
        else
        {
            res[j] = num;
            --j;
        }
    }
    std::cout << std::endl;
    std::cout << "res ";
    if (res[0] == 0)
    {
        std::cout << " ";
        for (int i = 1; i < size1; ++i)
        {
            std::cout << res[i] << " ";
        }
    }
    else
    {
        for (int i = 0; i < size1; ++i)
        {
            std::cout << res[i] << " ";
        }
    }
    
    return 0;
}
