#include <iostream>
#include <map>
#include "errorCode.hpp"
#include "class.hpp"

extern "C" 
{
    #include "include/hello.h"
}

int main()
{
    // printGreeting();
    int arr[] = { 6, 5, 2, 4, 3, 1 };
    // int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
    size_t arrSize = sizeof(arr)/sizeof(int);
    SortMachine * mySortMachine;
    QuickSort myQuickSort;
    mySortMachine = &myQuickSort;
    
    mySortMachine->show(arr, arrSize);
    mySortMachine->sort(arr, arrSize);
    mySortMachine->show(arr, arrSize);

    return 0;
}  