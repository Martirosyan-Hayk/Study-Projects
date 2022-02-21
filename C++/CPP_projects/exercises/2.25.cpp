#include<iostream>


void sort(int*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 15;
    int* arr = new int[size];

    std::cout << "Numbers of array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 90 - 32;
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
    int indexpos = 0;

    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] > 0)
        {
            indexpos = i;
            break;
        }
    }

    for (int i = indexpos ; i < size; ++i)
    {
        for (int index = indexpos; index < size ; ++index)
        {
            int next_index = index + 1;
            if (ptr[index] < ptr[next_index])
            {
                int tmp = ptr[index];
                ptr[index] = ptr[next_index];
                ptr[next_index] = tmp;
                
            }
        }
    }

    std::cout << "This is new sortid array " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << ptr[i] << " ";
    }
}
