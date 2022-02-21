#include<iostream>

void sort_two_array(int*&, int*&, const int&);
void sort(int*&, const int&);

int main()
{
    srand(time(NULL));
   
    const int size = 9;
    int* arr = new int[size];
    int* arr2 = new int[size - 2];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 - 18;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Numbers of array two " << std::endl;
    for (int i = 0; i < size - 2; ++i)
    {
        arr2[i] = rand() % 99 - 18;
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    sort_two_array(arr, arr2, size);
 
}

void  sort_two_array(int*& ptr, int*& ptr2, const int& arr_size)
{
 
    int size = (arr_size + arr_size) - 2;
    int* newarr = new int[size];
    int j = 0;
    for (int i = 0; i < arr_size; ++i)
    {
        newarr[j] = ptr[i];
        j++;
    }

    for (int i = 0; i < arr_size - 2; ++i)
    {
        newarr[j] = ptr2[i];
        j++;
    }

    sort(newarr, size);

    std::cout << "This is sort of two array " << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::cout << newarr[i] << "  ";
    }
   

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
}