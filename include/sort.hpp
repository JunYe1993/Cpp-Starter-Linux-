#pragma once

#include <iostream>

class SortMachine {
    public:
        virtual void sort (int arr[], size_t arrSize) { return; };
        void show (int arr[], size_t arrSize);
        void SelfTest ();
};

class QuickSort : public SortMachine {
    private:
        void swap (int * a, int * b);
        int  partition (int arr[], int low, int high);
        void quickSort (int arr[], int low, int high);

    public:
        void sort (int arr[], size_t arrSize);
};