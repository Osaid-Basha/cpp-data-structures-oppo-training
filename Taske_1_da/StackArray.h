#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class StackArray {
private:
    T* data;        // array to store stack values
    int top;        // index of top value
    int capacity;   // size of array

    // double the array if it's full
    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i <= top; i++) {
            newData[i] = data[i]; // copy old data
        }
        delete[] data;  // delete old array
        data = newData; // update pointer
    }

public:
    // constructor to set initial values
    StackArray() {
        capacity = 2;
        data = new T[capacity];
        top = -1;
    }

    // destructor to free memory
    ~StackArray() {
        delete[] data;
    }

    // add value to top
    void push(T value) {
        if (top + 1 == capacity) {
            resize(); // if full then resize
        }
        data[++top] = value;
    }

    // remove top value
    void pop() {
        if (top >= 0) {
            top--;
        }
    }

    // show top value
    T peek() const {
        if (top == -1) {
            throw out_of_range("Stack is empty");
        }
        return data[top];
    }

    // check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // return how many values
    int size() const {
        return top + 1;
    }

    // print values from top to bottom
    void print() const {
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
