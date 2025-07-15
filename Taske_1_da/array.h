#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
	// Pointer to dynamically allocated array
	T* data;
	int capacity; // Total capacity of the array
	int length;   // Current number of elements

	// Resize the array when it's full
	void resize() {
		capacity *= 2;
		// Create new array with larger capacity
		T* newData = new T[capacity];
		// Copy existing elements to the new array
		for (int i = 0; i < length; i++) {
			newData[i] = data[i];
		}
		// Free the old array
		delete[] data;
		// Update data pointer to point to the new array
		data = newData;
	}

public:
	// Constructor: initialize array with default capacity
	Array() {
		capacity = 2;
		length = 0;
		data = new T[capacity];
	}

	// Destructor: free allocated memory
	~Array() {
		delete[] data;
	}

	// Add a new element to the end of the array
	void push(T Elem) {
		// Resize if array is full
		if (capacity == length) {
			resize();
		}
		data[length++] = Elem;
	}

	// Remove the last element from the array
	void pop() {
		// Check if array is not empty
		if (length > 0) {
			length--;
		}
	}

	// Get element at a specific index
	T get(int index) const {
		// Check for valid index
		if (index >= 0 && index < length) {
			return data[index];
		}
		else {
			// Throw exception if index is out of bounds
			throw out_of_range("Index out of range");
		}
	}

	// Set value at a specific index
	void set(int index, T value) {
		// Check for valid index
		if (index >= 0 && index < length) {
			data[index] = value;
		}
		else {
			// Throw exception if index is out of bounds
			throw out_of_range("Index out of range");
		}
	}

	// Return the number of elements in the array
	int size() const {
		return length;
	}

	// Print all elements in the array
	void print() const {
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

	// Clear all elements in the array
	void clear() {
		length = 0;
	}
};
