#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;



template <typename T>
class StackLinkedList {
private:
    Node<T>* top; // pointer to top
    int length;   // how many elements

public:
    // constructor
    StackLinkedList() {
        top = nullptr;
        length = 0;
    }

    // destructor to delete all nodes
    ~StackLinkedList() {
        while (top != nullptr) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // add new value to top
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        length++;
    }

    // remove top value
    void pop() {
        if (top == nullptr) return;

        Node<T>* temp = top;
        top = top->next;
        delete temp;
        length--;
    }

    // return top value
    T peek() const {
        if (top == nullptr) {
            throw out_of_range("Stack is empty");
        }
        return top->data;
    }

    // check if empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // return size
    int size() const {
        return length;
    }

    // print from top to bottom
    void print() const {
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
