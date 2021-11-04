#include "sort.hpp"

void SortMachine::show (int arr[], size_t arrSize)
{
    for (size_t i = 0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void SortMachine::SelfTest ()
{
    int arr[] = { 6, 5, 2, 4, 3, 1 };
    // int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
    size_t arrSize = sizeof(arr)/sizeof(int);
    SortMachine * mySortMachine;
    QuickSort myQuickSort;
    mySortMachine = &myQuickSort;
    
    mySortMachine->show(arr, arrSize);
    mySortMachine->sort(arr, arrSize);
    mySortMachine->show(arr, arrSize);
}

// A utility function to swap two elements
void QuickSort::swap (int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int QuickSort::partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int partitionIndex = low;

    for (int i = low; i < high; ++i) {
        if ( arr[i] < pivot ) {
            swap (&arr[partitionIndex], &arr[i]);
            ++partitionIndex;
        }
    }
    swap (&arr[high], &arr[partitionIndex]);
    return partitionIndex;
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void QuickSort::quickSort (int arr[], int low, int high)
{
    int mid;
    if (low < high) {
        mid = partition (arr, low, high);
        quickSort (arr, low, mid - 1);
        quickSort (arr, mid + 1, high);
    }
}

void QuickSort::sort (int arr[], size_t arrSize)
{
    quickSort (arr, 0, arrSize-1);
}