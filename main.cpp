// Author: Payton Redemer
// File: main.cpp
// Purpose: main driver for Insertion Sort project

#include "AlgorithmsSorts.h"
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main()
{
    srand(time(NULL));
    int inputs[] = {10, 100,1000, 10000, 100000, 200000, 500000, 1000000};
    int size = 8;

    std::cout << "Merge sort:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        time_merge_sort(inputs[i]);
        std::cout << std::endl;
    }

    std::cout << "Quick sort:" << std::endl;
    for(int i = 0; i < 5; i++)
    {
        time_quick_sort(inputs[i]);
        std::cout << std::endl;
    }

    std::cout << "Heap sort:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        time_heap_sort(inputs[i]);
        std::cout << std::endl;
    }


    std::cout << "Modified Quick sort:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        time_modified_quick_sort(inputs[i]);
        std::cout << std::endl;
    }
    
    return 0;
}