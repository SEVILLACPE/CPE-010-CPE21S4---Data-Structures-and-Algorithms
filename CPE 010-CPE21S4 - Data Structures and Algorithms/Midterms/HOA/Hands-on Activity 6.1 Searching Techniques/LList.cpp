#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo.h"

const int max_size = 50;

int main()
{

    //LINKED LIST "JULLIAN"    
    std::cout << "\n===== LINKED LIST SEARCH =====\n";

    Node<char> *name1 = new_node('J');
    Node<char> *name2 = new_node('U');
    Node<char> *name3 = new_node('L');
    Node<char> *name4 = new_node('L');
    Node<char> *name5 = new_node('I');
    Node<char> *name6 = new_node('A');
    Node<char> *name7 = new_node('N');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = nullptr;

    char letter;
    std::cout << "Enter letter to search in JULLIAN: ";
    std::cin >> letter;
    linearSearchLL(name1, letter);

    return 0;
}