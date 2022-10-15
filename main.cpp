// Author: Payton Redemer
// File: main.cpp
// Purpose: main driver for Project 1

#include "AlgorithmsSorts.h"
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main()
{
    srand(time(NULL));

    const int n = 10;
    AlgorithmsSorts<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = i;
    }


    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << std::endl;
    }


    // int inputs[] = {10, 1000, 10000, 100000, 200000};
    // for(int i = 0; i < 6; i++)
    // {
    //     time_insertion_sort(inputs[i]);
    //     std::cout << std::endl;
    // }
}