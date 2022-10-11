template <typename T>
void insertion_sort(T arr[], const int n)
{
    T key;
    int i;
    for(int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}