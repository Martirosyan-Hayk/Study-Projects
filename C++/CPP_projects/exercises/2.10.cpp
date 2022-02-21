#include<iostream>
#include<cmath>

void merge_two_array(int*&, double*&, const int&);
void sort_ascending(double*&, const int&);
void sort_descending(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];
    double* arr2 = new double[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - 29;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Numbers of array two " << std::endl;
    for (int i = 0; i <= size; ++i)
    {
        if (cos(arr[i]) > 0)
        {
            arr2[i] = pow(arr[i], 3) - 7.5;
        }
        else
        {
            arr2[i] = pow(arr[i], 2) - pow((5 * 2,71), sin(arr[i]));
        }
        std::cout << arr2[i - 1] << " ";
    }
    std::cout << std::endl;

    merge_two_array(arr, arr2, size);

}

void  merge_two_array(int*& ptr, double*& ptr2, const int& arr_size)
{

    sort_descending(ptr, arr_size);
    sort_ascending(ptr2, arr_size);

    int size = arr_size * 2;
    double* newarr = new double[size - 4];
    int j = 0;
    for (int i = 0; i < arr_size; i+=2)
    {
        newarr[j] = ptr[i];
        ++j;
    }

    for (int i = 0; i < arr_size; i+=2)
    {
        newarr[j] = ptr2[i];
        ++j;
    }

  

    std::cout << "This is sort of two array " << std::endl;

    for (int i = 0; i < size - 4; ++i)
    {
        std::cout << newarr[i] << "  ";
    }


}

void sort_ascending(double*& ptr, const int& size)
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
                double tmp = ptr[index];
                ptr[index] = ptr[next_index];
                ptr[next_index] = tmp;
                sorted = false;
            }
        }
    }
}

void sort_descending(int*& ptr, const int& size)
{
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted; ++pass)
    {
        sorted = true;
        for (int index = 0; index < size - pass; ++index)
        {
            int next_index = index + 1;
            if (ptr[index] < ptr[next_index])
            {
                int tmp = ptr[index];
                ptr[index] = ptr[next_index];
                ptr[next_index] = tmp;
                sorted = false;
            }
        }
    }
}