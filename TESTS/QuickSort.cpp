// C++ program for Merge Sort
// This code is taken from https://www.geeksforgeeks.org/quick-sort/

#include <iostream>
#include <gtest/gtest.h>
#include "Utils.h"

class QuickSort : public testing::Test
{
    int *arr;
    int N;

    public:
        QuickSort()
        {
            N = 15;
            arr = new int[N];

            inputArray(arr);
        }
        ~QuickSort()
        {
            if(arr != nullptr) delete arr;
        }

        int* getArray();
        int getArraySize();
        int partition(int[], int, int);
        void quickSort(int[], int, int);
};


int* QuickSort::getArray() { return this->arr; };
int QuickSort::getArraySize() { return N; }
  
int QuickSort::partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low- 1); 
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort::quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


TEST_F(QuickSort, GivenAnArray_WhenSortedUsingQuickSort_ThenReturnSortedArray)
{
    quickSort(getArray(), 0, getArraySize() - 1);
    
    int *arr = getArray();

    int sortedArr[getArraySize()];
    sortedArray(sortedArr);

    if(arr != nullptr)
    {
        for(int i = 0; i < getArraySize(); i++)
        {
            ASSERT_EQ(arr[i], sortedArr[i]);
            //std::cout << "(" << arr[i] << "," << sortedArr[i] << ")" << std::endl;
        }
    }
}