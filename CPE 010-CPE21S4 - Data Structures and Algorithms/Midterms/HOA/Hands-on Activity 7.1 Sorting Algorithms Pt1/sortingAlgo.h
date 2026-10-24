#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <iostream>
using namespace std;

template<typename T>
void bubbleSort(T arr[], int maxSize){
    for(int i = 0; i < maxSize; i++){
        for(int j = i + 1; j < maxSize; j++){
            if(arr[i] > arr[j]){
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template<typename T>
int routineSmallest(T arr[], int k, int maxSize){
    int position;
    int smallestElem = arr[k];
    position = k;

    for(int j = k + 1; j < maxSize; j++){
        if(arr[j] < smallestElem){
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], int maxSize){
    int POS;
    for(int i = 0; i < maxSize; i++){
        POS = routineSmallest(arr, i, maxSize);
        std::swap(arr[i], arr[POS]);
    }
}

template<typename T>
void insertionSort2(T arr[], int maxSize){
    int k, j, temp;
    while (k < maxSize){
        temp = arr[k];
        
        // The rest follows your structure — complete version below
        for (j = k - 1; j >= 0 && temp < arr[j]; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
        k++;
    }
}

#endif