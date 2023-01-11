// C++ program for Merge Sort
// This code is taken from https://www.geeksforgeeks.org/merge-sort/

#include <iostream>
#include <gtest/gtest.h>
#include "Utils.h"

class MergeSort : public testing::Test
{
    int *arr;
    int N;

    public:
        MergeSort()
        {
            N = 15;
            arr = new int[N];

            inputArray(arr);
        }
        ~MergeSort()
        {
            if(arr != nullptr) delete arr;
        }

        int* getArray();
        int getArraySize();
        void merge(int[], int const, int const, int const);
        void mergeSort(int[], int const, int const);      
};


int* MergeSort::getArray() { return this->arr; };
int MergeSort::getArraySize() { return N; }

void MergeSort::merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, 
         indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
    
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void MergeSort::mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

TEST_F(MergeSort, GivenAnArray_WhenSortedUsingMergeSort_ThenReturnSortedArray)
{
    mergeSort(getArray(), 0, getArraySize() - 1);
    
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