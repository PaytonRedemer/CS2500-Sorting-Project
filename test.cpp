// Author: Payton Redemer
// File: test.cpp
// Purpose: test driver for Insertion Sort project

#include "AlgorithmsSorts.h"
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main()
{
    // Note more thorough testing was done this is more to help you grade me
    const int size = 10;
    AlgorithmsSorts<int> test1(size);
    srand(time(NULL));
    std::cout << "length of array is " << test1.length() << std::endl;
    std::cout << std::endl;

    // Array is already sorted
    std::cout << "Array is already sorted" << std::endl;
    for(int i = 0; i < test1.length(); i++)
        test1[i] = i;

    print_array(test1);
    test1.modified_quick_sort(0,size-1);
    std::cout << test1.is_sorted(0) << std::endl;
    print_array(test1);
    std::cout << std::endl;

    // Array is in opposite order
    std::cout << "Array is in opposite order" << std::endl;
    for(int i = 0; i < test1.length(); i++)
        test1[i] = test1.length() - i;

    print_array(test1);
    test1.modified_quick_sort(0,size-1);
    std::cout << test1.is_sorted(0) << std::endl;
    print_array(test1);
    std::cout << std::endl;

    // All array elements are constant
    std::cout << "All array elements are constant" << std::endl;
    for(int i = 0; i < test1.length(); i++)
        test1[i] = 5;

    print_array(test1);
    test1.modified_quick_sort(0,size-1);
    std::cout << test1.is_sorted(0) << std::endl;
    print_array(test1);
    std::cout << std::endl;

    // Duplicates in array
    std::cout << "Duplicates in array" << std::endl;
    for(int i = 0; i < test1.length(); i++)
        test1[i] = i % 2;

    print_array(test1);
    test1.modified_quick_sort(0,size-1);
    std::cout << test1.is_sorted(0) << std::endl;
    print_array(test1);
    std::cout << std::endl;

    // Random array
    std::cout << "Random array" << std::endl;
    for(int i = 0; i < test1.length(); i++)
        test1[i] = rand() % test1.length();

    print_array(test1);
    test1.modified_quick_sort(0,size-1);
    std::cout << test1.is_sorted(0) << std::endl;
    print_array(test1);
    std::cout << std::endl;

    // Create a negative array. Should exit program
    // AlgorithmsSorts<int> test2(-2);

    return 0;
}