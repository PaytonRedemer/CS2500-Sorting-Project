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
    int inputs[] = {10, 100,1000, 10000, 100000, 200000, 500000};

    for(int i = 0; i < 7; i++)
    {
        time_quick_sort(inputs[i]);
        std::cout << std::endl;
    }
}