template <typename T>
int Partition(T*& arr, int& start, int& end)
{
	T pivod = arr[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; ++j)
	{
		if (arr[j] <= pivod)
		{
			i += 1;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[end]);
	return i + 1;
}

template <typename T>
void QuickSort(T*& arr, int start, int end)
{
	if (start < end)
	{
		int pivod = Partition(arr, start, end);
		QuickSort(arr, start, pivod - 1);
		QuickSort(arr, pivod + 1, end);
	}
}		
