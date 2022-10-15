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
    int inputs[] = {10, 1000, 10000, 100000, 200000};

    for(int i = 0; i < 6; i++)
    {
        time_insertion_sort(inputs[i]);
        std::cout << std::endl;
    }
}