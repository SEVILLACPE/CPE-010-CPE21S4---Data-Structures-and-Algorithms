#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>

// NODE STRUCT & HELPER
template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
Node<T> *new_node(T value)
{
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next = nullptr;
    return temp;
}

// LINEAR SEARCH — ARRAY
template <typename T>
void linearSearchArr(int maxSize, T dataFind, T data[])
{
    int i = 0;
    while (i < maxSize)
    {
        if (dataFind == data[i])
        {
            std::cout << "Searching is successful!\n";
            return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful!\n";
}

// BINARY SEARCH — ARRAY (YOUR VERSION)
template <typename T>
void binarySearchArr(T dataFind, T data[], int maxSize)
{
    int low = 0, up = maxSize - 1;
    int middle;

    while (low <= up)
    {
        middle = (low + up) / 2;

        if (dataFind == data[middle])
        {
            std::cout << "Searching is successful!\n";
            return;
        }
        else if (dataFind < data[middle])
        {
            up = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    std::cout << "Searching is unsuccessful!\n";
}

// LINEAR SEARCH — LINKED LIST
template <typename T>
void linearSearchLL(Node<T> *node, T dataFind)
{
    while (node != nullptr)
    {
        if (node->data == dataFind)
        {
            std::cout << "Searching is successful!\n";
            return;
        }
        node = node->next;
    }
    std::cout << "Searching is unsuccessful!\n";
}

// CREATE A HELPER FUNCTION TO GET THE MIDDLE
template <typename T>
Node<T> *getMiddle(Node<T> *start, Node<T> *last)
{

    // use two pointers
    // slow moves one node at a time
    // fast moves two at a time
    Node<T> *slow = start;
    Node<T> *fast = start;

    // create a loop until fast reaches the end or
    // reaches the last node of the current search range
    while (fast != last && fast->next != last)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T> *start, T dataFind)
{

    Node<T> *last = nullptr;

    while (start != last)
    {

        // middle element
        Node<T> *middle = getMiddle(start, last);

        if (middle->data == dataFind)
        {
            std::cout << "the data was found. \n";
            return;
        }
        else if (middle->data > dataFind)
        {
            last = middle;
        }
        else
        {
            start = middle->next;
        }
    }

    std::cout << "Search element was not found\n";
}

#endif