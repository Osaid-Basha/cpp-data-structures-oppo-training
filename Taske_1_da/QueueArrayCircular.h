
#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class QueueArrayCircular
{
private:
    T* a;
    int Maxcapacity;
    int length, frontIndex, rear;

public:
    // constructor
    QueueArrayCircular() {
        // initial value
        Maxcapacity = 10;
        length = 0;
        frontIndex = 0;
        rear = 0;
        a = new  T[Maxcapacity];
    }

    // destructor
    ~QueueArrayCircular() {
        if (a != nullptr) delete[] a;
        a = nullptr;
    }

    // check if queue is empty
    bool empty() const { return length <= 0; }

    // return size of queue
    int size() const { return length; }

    // return first value in queue
    int frontValue() const {
        if (empty()) throw out_of_range("Queue is empty");
        return a[frontIndex];
    }

    // check if queue is full
    bool full() const { return length >= Maxcapacity; }

    // add value to queue
    void enqueue(T value) {
        if (!full()) {
            a[rear] = value;
            rear = (rear + 1) % Maxcapacity;
            length++;
        }
        else {
            cout << "Queue is full\n";
        }
    }

    // remove value from front of queue
    void dequeue() {
        if (!empty()) {
            frontIndex = (frontIndex + 1) % Maxcapacity;
            length--;
        }
        else {
            cout << "Queue is empty\n";
        }
    }

    // print all values in queue
    void print() const {
        cout << "Queue content: ";
        for (int i = 0, x = frontIndex; i < length; i++) {
            cout << a[x] << " ";
            x = (x + 1) % Maxcapacity;
        }
        cout << endl;
    }
};
