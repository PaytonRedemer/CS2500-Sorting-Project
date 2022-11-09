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

        // Purpose: Sort arr in ascending order
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        void insertion_sort();

        // TODO: Update docs for quicksort + partition
        // Purpose: Sort arr in ascending order
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        int partition(const int p, const int r);

        // Purpose: Sort arr in ascending order
        // Precondition: arr is a non-empty array with sortable elements
        // Postcondition: arr is sorted in ascending order
        void quick_sort(const int p, const int r);

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