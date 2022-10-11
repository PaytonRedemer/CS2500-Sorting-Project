#include "AlgorithmsSorts.h"
#include <cstdlib>
#include <iostream>

int main()
{
    srand(5);
    const int SIZE = 100;
    int arr[SIZE]; 

    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000 + 1;
        std::cout << arr[i] << std::endl;
    }

    std::cout << std::endl;
    insertion_sort(arr, SIZE);
    for(int i = 0; i < SIZE; i++)
        std::cout << arr[i] << std::endl;
}