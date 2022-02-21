template<typename T>
void merg(T*& ptr_in_arr, int& first, int& mid, int& last)
{
    T temp[size]{0};

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        if (ptr_in_arr[first1] < ptr_in_arr[first2])
        {
            temp[index] = ptr_in_arr[first1];
            ++first1;
        }
        else
        {
            temp[index] = ptr_in_arr[first2];
            ++first2;
        }
    }

    for (; first1 <= last1; ++first1, ++index)
    {
        temp[index] = ptr_in_arr[first1];
    }

    for (; first2 <= last2; ++first2, ++index)
    {
        temp[index] = ptr_in_arr[first2];
    }

    for (index = first; index <= last; ++index)
    {
        ptr_in_arr[index] = temp[index];
    }

}
template<typename T>
void merg_sort(T*& ptr_in_arr, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        merg_sort(ptr_in_arr, first, mid);
        merg_sort(ptr_in_arr, mid + 1, last);
        merg(ptr_in_arr, first, mid, last);
    }
}
