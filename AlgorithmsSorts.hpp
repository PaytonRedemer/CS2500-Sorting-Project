// Author: Payton Redemer
// File: AlgorithmsSorts.hpp
// Purpose: Contains class functions for AlgorithmsSorts

#include "AlgorithmsSorts.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <new>
#include <type_traits>
#include <math.h>
#include <climits>

#define DEBUG 1 // Debug variable for asserts in insertion sort. 1 = DEBUG, 0 = No DEBUG

template <typename T>
AlgorithmsSorts<T>::AlgorithmsSorts(const int size)
{
    try
    {
        // Check if array size > 0
        if(size <= 0)
            throw std::bad_array_new_length();
        n = size;
        heap_size = size;
        arr = new T[size];
    }

    catch(const std::bad_array_new_length & e)
    {
        std::cout << "Invalid array size. Must be non-zero positive integer!" << std::endl;
        exit(1);
    }
}

template <typename T>
AlgorithmsSorts<T>::~AlgorithmsSorts()
{
    delete[] arr;
}

template <typename T>
int AlgorithmsSorts<T>::length() const
{
    return n;
}

template <typename T>
T & AlgorithmsSorts<T>::operator[](const int i)
{
    return arr[i];
}

// Change DEBUG variable at top for assertions
template <typename T>
void AlgorithmsSorts<T>::insertion_sort()
{
    T key;
    int i;
    
    // Checking Precondition
    #if DEBUG == 1
        assert(n > 0);
    #endif
    for(int j = 1; j < n; j++)
    {
        // Checking invariant
        #if DEBUG == 1
            assert(this->is_sorted(j));
        #endif

        key = arr[j];
        // Insert A[j] into the sorted sequence A[0..j − 1]
        i = j - 1;
        while(i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;

        // Checking invariant
        #if DEBUG == 1
            assert(this->is_sorted(j));
        #endif
    }
    // Checking Postcondition
    #if DEBUG == 1
        assert(this->is_sorted(n));
    #endif
}

template <typename T>
void AlgorithmsSorts<T>::merge(const int p, const int q, const int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    T L[n1 + 1];
    T R[n2 + 1];

    for(int i = 0; i < n1; i++)
        L[i] = arr[p + i];

    for(int j = 0; j < n1; j++)
        R[j] = arr[q + j + 1];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for(int k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i = i + 1;
        }
        else
        {
            arr[k] = R[j];
            j = j + 1;
        }
    }
}

template <typename T>
void AlgorithmsSorts<T>::merge_sort(const int p, const int r)
{
    int q;
    if(p < r)
    {
        q = floor((p + r) / 2);
        merge_sort(p,q);
        merge_sort(q+1,r);
        merge(p,q,r);
        
    }
}

template <typename T>
int AlgorithmsSorts<T>::partition(const int p, const int r)
{
    T x = arr[r];
    int i = p - 1;
    for(int j = p; j < r; j++) // j < r -1 maybe
    {
        if(arr[j] <= x)
        {
            i = i + 1;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[i+1],arr[r]);
    return i + 1;
}

template <typename T>
void AlgorithmsSorts<T>::quick_sort(const int p, const int r)
{
    if(p < r)
    {
        int q = this->partition(p,r);
        this->quick_sort(p,q-1);
        this->quick_sort(q+1,r);
    }

}

int parent(const int i)
{
    return floor(i / 2);
}
int left(const int i)
{
    return 2 * i;
}

int right(const int i)
{
    return (2 * i) + 1;
}


template <typename T>
void AlgorithmsSorts<T>::max_heapify(const int i)
{
    int l = left(i);
    int r = right(i);
    int largest;
    
    if(l <= heap_size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r <= heap_size && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i)
    {
        std::swap(arr[i],arr[largest]);
        max_heapify(largest);
    }
}


template <typename T>
void AlgorithmsSorts<T>::build_max_heap()
{
    heap_size = n;
    for(int i = floor(n/2); i > 0; i--)
        max_heapify(i);
}

template <typename T>
void AlgorithmsSorts<T>::heap_sort()
{
    this->build_max_heap();
    for(int i = n; i > 1; i--)
    {
        std::swap(arr[1], arr[i]);
        heap_size = heap_size - 1;
        max_heapify(1);
    }
}

void time_insertion_sort(const int n)
{
    AlgorithmsSorts<int> arr(n); 
    std::chrono::steady_clock::time_point begin, end; // declare variables for timing sorts
    std::cout << "For n = " << n << std::endl;


    // Best case for insertion sort
    // input array is already sorted
    for(int i = 0; i < n; i++)
        arr[i] = i;
    
    begin = std::chrono::steady_clock::now();
    arr.insertion_sort();
    end = std::chrono::steady_clock::now();
    std::cout << "Best case: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "ns" << std::endl;
    
    
    // Worst case for insertion sort
    // input array is sorted in the opposite intended sort
    for(int i = 0; i < n; i++)
        arr[i] = n - i;
    
    begin = std::chrono::steady_clock::now();
    arr.insertion_sort();
    end = std::chrono::steady_clock::now();
    std::cout << "Worst case: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "ns" << std::endl;

    // "Average case" for insertion sort
    // average is hard to quantify our average case will be a random array
    for(int i = 0; i < n; i++)
        arr[i] = rand() % n;
    
    begin = std::chrono::steady_clock::now();
    arr.insertion_sort();
    end = std::chrono::steady_clock::now();
    std::cout << "Average case: " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "ns" << std::endl;
}

template <typename T>
bool AlgorithmsSorts<T>::is_sorted(const int n)
{
    bool sorted = true;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i - 1])
        {
            sorted = false;
            break;
        }
    }
    return sorted;
}

template <typename T>
void print_array(AlgorithmsSorts<T> & algo)
{
    for(int i = 0; i < algo.length(); i++)
    {
        std::cout << algo[i] << " ";
    }
    std::cout << std::endl;
}