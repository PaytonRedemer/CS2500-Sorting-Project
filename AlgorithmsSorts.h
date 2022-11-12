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
        int heap_size;

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

        // Purpose: Sort arr in ascending order
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        void insertion_sort();

        /*
            Merge Sort
        */

        void merge(const int p, const int q, const int r);

        void merge_sort(const int p, const int r);

        // TODO: Update docs for quicksort + partition
        /*
            Quick Sort
        */

        // Purpose: Helper function to assist quick_sort function
        // Precondition: 0 <= p <= n-1, 0 <= p <= n-1, arr is a non-empty array with sortable elements
        // Postcondition: ?
        int partition(const int p, const int r);

        // Purpose: Sort arr in ascending order using the quicksort algorithm
        // Precondition: 0 <= p <= n-1, 0 <= p <= n-1, arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        void quick_sort(const int p, const int r);

        /*
            Heap Sort
        */

        // Helper functions to return the index of the parent,left,or right node respective to i
        int parent(const int i);
        int left(const int i);
        int right(const int i);

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