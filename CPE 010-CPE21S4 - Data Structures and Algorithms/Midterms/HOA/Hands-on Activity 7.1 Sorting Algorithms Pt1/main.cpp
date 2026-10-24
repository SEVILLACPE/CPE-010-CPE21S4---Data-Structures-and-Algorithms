#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main(){

    //create an array with unsorted list with 100 maximum size
    int unsortedArr[maxSize];

    //use time (0) as seed for random values
    srand(time(0));

    //populate the array with random values
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() %5 +1;
    }

    displayArr(unsortedArr);

    // std::cout<<"\n\n Bubble Sort testing: \n";
    // bubbleSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    // std::cout<<"\n\n selectionSort testing: \n";
    // selectionSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    std::cout<<"\n\n insertionSort testing: \n";
    insertionSort2(unsortedArr, maxSize);
    displayArr(unsortedArr);

}

void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}