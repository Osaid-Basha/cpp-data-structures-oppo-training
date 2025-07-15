#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"
using namespace std;

template <typename T>
class CircularLinkedList
{
private:
	Node<T>* tail; // point to last node
	int length;     // count of elements

public:
    // constructor
    CircularLinkedList() {
        tail = nullptr;
        length = 0;
    }

    // destructor to free all nodes
    ~CircularLinkedList() {
        while (!empty()) {
            pop();
        }
    }
    // check if list is empty
    bool empty() const {
        return length == 0;
    }
    // return size
    int size() const {
        return length;
    }
    // add value at end
    void push(T value) {
        // create new node
        Node<T>* newNode = new Node<T>(value); 

        // if list is empty
        if (tail == nullptr) {
            tail = newNode;
            tail->next = newNode; // point to itself
        }
        else {
            newNode->next = tail->next; // new points to head
            tail->next = newNode;
            tail = newNode; // update tail
        }

        length++;
    }
    // remove last element
    void pop() {
        if (empty()) return;

        // if only one element
        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
        }
        else {
            // find node before tail
            Node<T>* current = tail->next;
            while (current->next != tail) {
                current = current->next;
            }

            current->next = tail->next; // connect to head
            delete tail;
            tail = current;
        }

        length--;
    }
    // print all values
    void print() const {
        if (empty()) {
            cout << "List is empty" << endl;
            return;
        }

        CNode<T>* current = tail->next; // start from head
        cout << "Circular List: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        cout << endl;
    }
};

