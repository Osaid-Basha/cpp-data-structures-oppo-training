#pragma once
#include <iostream>
using namespace std;

// Node structure for linked list
template <typename T>
class Node {
public:
	T value;        // value stored
	Node* next;     // pointer to next node

	// constructor
	Node(T val) {
		value = val;
		next = nullptr;
	}
};

// Hash table using separate chaining (linked list)
template <typename T>
class HashArray {
private:
	Node<T>** table;    // array of linked list heads
	int capacity;       // total number of buckets
	int length;         // number of stored elements

	// hash function to get index
	int h(const T& x) {
		return x % capacity;
	}

public:
	// constructor to initialize table
	HashArray(int cap = 7) {
		capacity = cap;
		length = 0;
		table = new Node<T>*[capacity];
		for (int i = 0; i < capacity; i++) {
			table[i] = nullptr; // set all buckets to empty
		}
	}

	// destructor to free memory
	~HashArray() {
		for (int i = 0; i < capacity; i++) {
			Node<T>* current = table[i];
			while (current) {
				Node<T>* temp = current;
				current = current->next;
				delete temp;
			}
		}
		delete[] table;
	}

	// insert value into hash table
	bool insert(const T& x) {
		int index = h(x); // get index
		Node<T>* current = table[index];

		// check if value already exists
		while (current) {
			if (current->value == x) return false; // duplicate
			current = current->next;
		}

		// insert at beginning
		Node<T>* newNode = new Node<T>(x);
		newNode->next = table[index];
		table[index] = newNode;
		length++;
		return true;
	}

	// find value in table
	bool find(const T& x) {
		int index = h(x);
		Node<T>* current = table[index];
		while (current) {
			if (current->value == x) return true;
			current = current->next;
		}
		return false;
	}

	// remove value from table
	bool remove(const T& x) {
		int index = h(x);
		Node<T>* current = table[index];
		Node<T>* prev = nullptr;

		while (current) {
			if (current->value == x) {
				if (prev == nullptr)
					table[index] = current->next; // delete first node
				else
					prev->next = current->next;   // skip current node
				delete current;
				length--;
				return true;
			}
			prev = current;
			current = current->next;
		}
		return false; // not found
	}

	// print full table
	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << i << ": ";
			Node<T>* current = table[i];
			while (current) {
				cout << current->value << " -> ";
				current = current->next;
			}
			cout << "null" << endl;
		}
	}

	// get number of elements
	int size() const {
		return length;
	}
};
