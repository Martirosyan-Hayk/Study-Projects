template<typename T>
void swap(T& element1, T& element2)
{
    T tmp = element1;
    element1 = element2;
    element2 = tmp;
}

template<typename T>
void selection_sort(T*& ptr_in_arr, const int& size)
{
    for (int last = size - 1; last >= 1; --last)
    {
      
        int min_idx = last;
        for (int j = last - 1; j >= 0; --j)
        {
            if (ptr_in_arr[j] > ptr_in_arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(ptr_in_arr[min_idx], ptr_in_arr[last]);
       
    } 
}

