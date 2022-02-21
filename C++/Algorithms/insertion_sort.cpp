template<typename T>
void insertion_sort(T*& ptr_in_arr, const int& size)
{
    for (int i = 1; i < size; ++i)
    {
        int j = i - 1;
        T key = ptr_in_arr[i];
        while (ptr_in_arr[j] > key && j >= 0)
        {         
            ptr_in_arr[j + 1] = ptr_in_arr[j];
            --j;
        }
        ptr_in_arr[j + 1] = key;
    }
}

