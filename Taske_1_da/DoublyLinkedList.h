#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
// create node to hold data and pointer to next and prev
class DNode {
public:
    T data;
    DNode<T>* next;
    DNode<T>* prev;

    // constructor
    DNode(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    DNode<T>* head; // first node
    DNode<T>* tail; // last node
    int length;     // count how many values in list

public:
    // constructor initialize empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // add value to end of list
    void push(T value) {
        // create new node
        DNode<T>* newNode = new DNode<T>(value);

        // if list is empty
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        // if list has values
        else {
            tail->next = newNode;  // connect tail to new node
            newNode->prev = tail;  // connect new node back to tail
            tail = newNode;        // move tail to new node
        }

        length++;
    }

    // remove value from end
    void pop() {
        // check if list is empty
        if (tail == nullptr) {
            return;
        }

        // save last node to delete
        DNode<T>* toDelete = tail;

        // move tail back
        tail = tail->prev;

        // if tail still exists
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        // if list became empty
        else {
            head = nullptr;
        }

        delete toDelete;
        length--;
    }

    // get value from index
    T get(int index) const {
        if (index < 0 || index >= length)
            throw out_of_range("Index out of range");

        DNode<T>* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    // change value at index
    void set(int index, T value) {
        if (index < 0 || index >= length)
            throw out_of_range("Index out of range");

        DNode<T>* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->data = value;
    }

    // get number of items in list
    int size() const {
        return length;
    }

    // print values from head to tail
    void printForward() const {
        DNode<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // print values from tail to head
    void printBackward() const {
        DNode<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // destructor to delete all nodes
    ~DoublyLinkedList() {
        DNode<T>* current = head;
        while (current != nullptr) {
            DNode<T>* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
        length = 0;
    }
};
