#include "Utils.h"

void printArray(int arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << endl;
}

void inputArray(int input[])
{
    int array[] = {12, 11, 13, 5, 6, 7, 15, 10, 9, 4, 8, 2, 3, 1, 14};
    for(int i = 0; i < 15; i++)
    {
        input[i] = array[i];
    }
}

void sortedArray(int input[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};   
    for(int i = 0; i < 15; i++)
    {
        input[i] = array[i];
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}