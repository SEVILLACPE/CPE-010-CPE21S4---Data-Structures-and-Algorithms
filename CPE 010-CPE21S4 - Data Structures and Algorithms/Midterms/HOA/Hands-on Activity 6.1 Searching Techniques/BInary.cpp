#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo.h"

const int max_size = 50;

int main()
{

    //BINARY SEARCH 
    std::cout << "\n\n===== BINARY SEARCH =====\n";

    // generate a sorted list for the array:
    int dataset2[max_size];
    for (int i = 0; i < max_size; i++)
    {
        dataset2[i] = i;
        std::cout << dataset2[i] << " ";
    }
    std::cout << "\n";

    binarySearchArr(11, dataset2, max_size);
    binarySearchArr(11111, dataset2, max_size);
}
