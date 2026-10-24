#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <iostream>
using namespace std;

template <typename T>
int routineSmallest(T arr[], int start, int maxSize) {
    int pos = start;
    for (int j = start + 1; j < maxSize; j++) {
        if (arr[j] < arr[pos])
            pos = j;
    }
    return pos;
}

template <typename T>
void selectionSort(T arr[], int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        int POS = routineSmallest(arr, i, maxSize);
        swap(arr[i], arr[POS]);
    }
}

#endif