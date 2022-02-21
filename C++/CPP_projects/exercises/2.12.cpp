#include<iostream>
#include<cmath>

void merge_two_array(double*&, const int&);
int sort_ascending(double*&, const int&);

int main()
{
    srand(time(NULL));

    const int size = 12;
    double* arr = new double[size];
    std::cout << "Numbers of array one " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (double)rand() / (double)RAND_MAX;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    merge_two_array(arr, size);

}

void  merge_two_array(double*& ptr, const int& arr_size)
{
    int cou = sort_ascending(ptr, arr_size);



    std::cout << "This is sort of that array " << std::endl;

    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << ptr[i] << "  ";
    }

    std::cout << std::endl << "This is permutations in a sotr " << cou << std::endl;


}

int sort_ascending(double*& ptr, const int& size)
{
    int count = 0;
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted; ++pass)
    {
        sorted = true;
        for (int index = 0; index < size - pass; ++index)
        {
            int next_index = index + 1;
            if (ptr[index] < ptr[next_index])
            {
                double tmp = ptr[index];
                ptr[index] = ptr[next_index];
                ptr[next_index] = tmp;
                ++count;
                sorted = false;
            }
        }
    }
    return count;
}

