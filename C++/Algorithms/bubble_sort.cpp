template<typename T>
void swap(T& element1, T& element2)
{
    T tmp = element1;
    element1 = element2;
    element2 = tmp;
}

template<typename T>
void bubble_sort(T*& ptr_in_arr, const int& size)
{
    bool sorted = false;

    for (int pass = 1; (pass < size) && !sorted; ++pass)
    {
        sorted = true;
        for (int index = 0; index < size - pass; ++index)
        {
            int next_index = index + 1;
            if (ptr_in_arr[index] > ptr_in_arr[next_index])
            {
                swap(ptr_in_arr[index], ptr_in_arr[next_index]);
                sorted = false;
            }
        }
    }
}

