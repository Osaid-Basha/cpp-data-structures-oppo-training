#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"
using namespace std;



template <typename T>
class singleLinkedList {
private:
    Node<T>* head; // Pointer to the first node
    int length;    // Number of elements in the list

public:
    // Constructor to initialize an empty list
    singleLinkedList() {
        head = nullptr;
        length = 0;
    }

    // Add a new value at the end of the list
    void push(T value) {
        // Create a new node to hold the value
        Node<T>* newLink = new Node<T>(value);

        // If the list is empty, new node becomes the head
        if (head == nullptr) {
            head = newLink;
        }
        // Otherwise, traverse to the last node and link the new node
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newLink;
        }

        length++;
    }

    // Remove the last element from the list
    void pop() {
        // If the list is empty, there's nothing to remove
        if (head == nullptr) {
            return;
        }

        // If there's only one element, delete it and reset head
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        // Otherwise, traverse to the second-to-last node and delete the last node
        else {
            Node<T>* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }

        length--;
    }

    // Return the value at a specific index
    T get(int index) const {
        // Check if index is within bounds
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }

        // Traverse the list to the desired index
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Set a new value at a specific index
    void set(int index, T value) {
        // Check if index is within bounds
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }

        // Traverse the list to the desired index
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = value;
    }

    // Return the number of elements in the list
    int size() const {
        return length;
    }

    // Print all elements in the list
    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << "   ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free all nodes in the list
    ~singleLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        length = 0;
    }
};
