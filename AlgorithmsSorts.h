// Author: Payton Redemer
// File: AlgorithmsSorts.h
// Purpose: Class definition for AlgorithmsSorts

#ifndef ALGORITHMSSORTS_H
#define ALGORITHMSSORTS_H

template <typename T>
class AlgorithmsSorts
{
    private:
        T *arr = nullptr;
        int n;

    public:
        // Constructor
        AlgorithmsSorts(const int size);
        
        // Deconstructor
        ~AlgorithmsSorts();

        // Allow access to arr with bracket operators
        T & operator[](const int i);

        // Purpose: Sort arr in ascending order
        // Precondition: arr is a non-empty with sortable elements
        // Postcondition: arr is sorted in ascending order
        void insertion_sort();

        // Purpose: Time sorting algorithm
        // Precondition: n > 0
        // Postcondition: Prints execution time of sort
        void time_insertion_sort(const int n);

        // Purpose: Test insertion sort's precondition, postcondition, and invariant through asserts
        // Precondition: arr is a non-empty with sortable elements
        // Postcondition: arr is sorted in ascending order
        void assert_insertion_sort();
};

#include "AlgorithmsSorts.hpp"

#endif