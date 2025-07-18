#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

// Min Heap using array (template)
template <typename T>
class MinHeap {
private:
	T* data;        // dynamic array to store heap elements
	int size;       // number of elements in heap
	int capacity;   // total capacity of the array

	// get index of parent
	int parent(int i) { return (i - 1) / 2; }

	// get index of left child
	int left(int i) { return 2 * i + 1; }

	// get index of right child
	int right(int i) { return 2 * i + 2; }

	// resize array when full
	void resize() {
		capacity *= 2;
		T* newData = new T[capacity];
		for (int i = 0; i < size; i++)
			newData[i] = data[i];
		delete[] data;
		data = newData;
	}

	// move element up to fix heap property
	void heapifyUp(int i) {
		while (i > 0 && data[i] < data[parent(i)]) {
			swap(data[i], data[parent(i)]);
			i = parent(i);
		}
	}

	// move element down to fix heap property
	void heapifyDown(int i) {
		int smallest = i;
		int l = left(i);
		int r = right(i);

		if (l < size && data[l] < data[smallest])
			smallest = l;
		if (r < size && data[r] < data[smallest])
			smallest = r;

		if (smallest != i) {
			swap(data[i], data[smallest]);
			heapifyDown(smallest);
		}
	}

public:
	// constructor
	MinHeap(int cap = 10) {
		capacity = cap;
		size = 0;
		data = new T[capacity];
	}

	// destructor
	~MinHeap() {
		delete[] data;
	}

	// insert new value into heap
	void insert(T value) {
		if (size == capacity)
			resize(); // increase capacity
		data[size] = value; // add to end
		heapifyUp(size);    // fix heap upward
		size++;
	}

	// get minimum element
	T getMin() const {
		if (size == 0)
			throw out_of_range("Heap is empty");
		return data[0];
	}

	// remove minimum element
	void removeMin() {
		if (size == 0)
			throw out_of_range("Heap is empty");
		data[0] = data[size - 1]; // move last to root
		size--;
		heapifyDown(0);          // fix heap downward
	}

	// get current size
	int getSize() const {
		return size;
	}

	// check if empty
	bool isEmpty() const {
		return size == 0;
	}

	// print heap elements
	void print() const {
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
		cout << endl;
	}
};
