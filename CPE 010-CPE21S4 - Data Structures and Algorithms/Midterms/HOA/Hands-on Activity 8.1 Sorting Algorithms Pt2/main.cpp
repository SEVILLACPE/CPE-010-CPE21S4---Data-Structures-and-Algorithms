#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "sorting_algorithms.h"
using namespace std;

int main() {
    srand(time(0));
    const int SIZE = 100;

    vector<int> original(SIZE);
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 1000;
    }

    cout << "===== UNSORTED ARRAY =====\n";
    printArray(original);
    cout << "\n";

    vector<int> shellArr = original;
    cout << "===== SHELL SORT =====\n";
    shellSort(shellArr, SIZE);
    printArray(shellArr);
    cout << "\n";

    vector<int> mergeArr = original;
    cout << "===== MERGE SORT =====\n";
    mergeSort(mergeArr, 0, SIZE - 1);
    printArray(mergeArr);
    cout << "\n";

    vector<int> quickArr = original;
    cout << "===== QUICK SORT =====\n";
    quickSort(quickArr, 0, SIZE - 1);
    printArray(quickArr);
    cout << "\n";

    return 0;
}