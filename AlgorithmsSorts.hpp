#include <chrono>
#include <cstdlib>
#include <iostream>


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

void time_insertion_sort(const int n)
{
    int arr[n];
    std::chrono::steady_clock::time_point begin, end; // declare variables for timing sorts
    std::cout << "For n = " << n << std::endl;


    // Best case for insertion sort
    // input array is already sorted
    for(int i = 0; i < n; i++)
        arr[i] = i;
    
    begin = std::chrono::steady_clock::now();
    insertion_sort(arr,n);
    end = std::chrono::steady_clock::now();
    std::cout << "Best case: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    
    
    // Worst case for insertion sort
    // input array is sorted in the opposite intended sort
    for(int i = 0; i < n; i++)
        arr[i] = n - i;
    
    begin = std::chrono::steady_clock::now();
    insertion_sort(arr,n);
    end = std::chrono::steady_clock::now();
    std::cout << "Worst case: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    // "Average case" for insertion sort
    // average is hard to quantify our average case will be a random array
    for(int i = 0; i < n; i++)
        arr[i] = rand() % n;
    
    begin = std::chrono::steady_clock::now();
    insertion_sort(arr,n);
    end = std::chrono::steady_clock::now();
    std::cout << "Average case: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}