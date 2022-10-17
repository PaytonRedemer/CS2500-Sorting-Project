// Author: Payton Redemer
// File: AlgorithmsSorts.hpp
// Purpose: Contains class functions for AlgorithmsSorts

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <new>

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