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
        AlgorithmsSorts(const int size);
        ~AlgorithmsSorts();

        T & operator[](const int i);

        void insertion_sort();
        void time_insertion_sort(const int n);
        void assert_insertion_sort(T arr[], const int n);
};

#include "AlgorithmsSorts.hpp"

#endif