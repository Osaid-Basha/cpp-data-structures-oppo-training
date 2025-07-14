#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
// Node class used in the linked list
class Node {
public:
    T data;
    Node<T>* next;

    // Constructor to initialize a node with a value
    Node(T value) {
        data = value;
        next = nullptr;
    }
};

