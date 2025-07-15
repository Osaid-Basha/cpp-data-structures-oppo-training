#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class QueueArray {
private:
    T* a;                // array to hold values
    int Maxcapacity;     // maximum size of queue
    int length;          // how many values now
    int frontIndex;      // front location
    int rear;            // rear location (next insert)

public:
    // constructor
    QueueArray() {
        Maxcapacity = 10;
        length = 0;
        frontIndex = 0;
        rear = 0;
        a = new T[Maxcapacity];
    }

    // destructor
    ~QueueArray() {
        if (a != nullptr) delete[] a;
        a = nullptr;
    }

    // check if empty
    bool empty() const {
        return length == 0;
    }

    // check if full
    bool full() const {
        return rear >= Maxcapacity;
    }

    // return size
    int size() const {
        return length;
    }

    // return first value
    T frontValue() const {
        if (empty()) throw out_of_range("Queue is empty");
        return a[frontIndex];
    }

    // add value to queue
    void enqueue(T value) {
        if (full()) {
            cout << "Queue is full\n";
            return;
        }
        a[rear++] = value;
        length++;
    }

    // remove from front
    void dequeue() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        frontIndex++;
        length--;
    }

    // print all values
    void print() const {
        cout << "Queue content: ";
        for (int i = frontIndex; i < rear; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
