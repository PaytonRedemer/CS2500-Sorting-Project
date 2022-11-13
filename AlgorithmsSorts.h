// Author: Payton Redemer
// File: AlgorithmsSorts.h
// Purpose: Class definition for AlgorithmsSorts

#ifndef ALGORITHMSSORTS_H
#define ALGORITHMSSORTS_H

#include <ostream>
template <typename T>
class AlgorithmsSorts
{
    private:
        T *arr = nullptr;
        int n;
        int heap_size; // needed for heap sort

    public:
        // Constructor
        // size must be greater than zero
        AlgorithmsSorts(const int size);
        
        // Deconstructor
        ~AlgorithmsSorts();

        // Returns size of AlgorithmsSorts object
        int length() const;

        // Allow access to arr with bracket operators
        T & operator[](const int i);

        /*
            Insertion Sort
        */

        // Purpose: Sort arr in ascending order using the insertion sort algorithm
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        void insertion_sort();

        /*
            Merge Sort
        */

        void merge(const int p, const int q, const int r);

        // Purpose: Sort arr in ascending order using the mergesort algorithm
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        void merge_sort(const int p, const int r);

        /*
            Quick Sort
        */

        // Purpose: Helper function to assist quick_sort function
        // Precondition: 0 <= p <= n-1, 0 <= p <= n-1, arr is a non-empty array with sortable elements
        // Postcondition: The element at r is now at the correct index if arr is sorted
        int partition(const int p, const int r);

        // Purpose: Sort arr in ascending order using the quicksort algorithm
        // Precondition: 0 <= p <= n-1, 0 <= p <= n-1, arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order and is a permutation of the original items
        void quick_sort(const int p, const int r);

        /*
            Heap Sort
        */

        // Purpose: Convert arr so that subtree rooted at i obeys the max-heap property
        // Precondition: arr[i+1,i+2,...,n] are roots of valid heaps
        // Postcondition: arr[i,i+1,i+2,...,n] are roots of valid heaps
        void max_heapify(const int i);

        // Purpose: Convert arr into a max heap
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is a valid heap
        void build_max_heap();

        // Purpose: Sort arr in ascending order using the heapsort algorithm
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        void heap_sort();

        /*
            Timing functions
        */
        
        // Purpose: Time insertion sort algorithm
        // Precondition: n > 0
        // Postcondition: Prints execution time of sort
        void time_insertion_sort(const int n);


        // Purpose: Time merge sort algorithm
        // Precondition: n > 0
        // Postcondition: Prints execution time of sort
        void time_merge_sort(const int n);

        
        // Purpose: Time quick sort algorithm
        // Precondition: n > 0
        // Postcondition: Prints execution time of sort
        void time_quick_sort(const int n);
        
        // Purpose: Time heap sort algorithm
        // Precondition: n > 0
        // Postcondition: Prints execution time of sort
        void time_heap_sort(const int n);

        // Purpose: Check if an array up to element n is sorted
        // Precondition: n > 0
        // Postcondition: Returns if sub-array is sorted
        bool is_sorted(const int n);

        // Print an AlgorithmsSorts object
        // Mostly just for testing
        void print_array(AlgorithmsSorts<T> & algo);
};

#include "AlgorithmsSorts.hpp"

#endif