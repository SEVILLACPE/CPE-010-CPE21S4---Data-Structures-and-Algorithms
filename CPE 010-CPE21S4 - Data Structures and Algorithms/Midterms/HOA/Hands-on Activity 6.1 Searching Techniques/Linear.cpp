#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo.h"

const int max_size = 50;

int main()
{
    
    //LINEAR SEARCH 
    
    std::cout << "===== LINEAR SEARCH =====\n";
    int dataset[max_size];
    srand(time(0));

    for (int i = 0; i < max_size; i++)
    {
        dataset[i] = rand() % 100;
        std::cout << dataset[i] << " ";
    }
    std::cout << "\n";

    int choice;
    std::cout << "Enter number to search: ";
    std::cin >> choice;
    linearSearchArr(max_size, choice, dataset);
}
