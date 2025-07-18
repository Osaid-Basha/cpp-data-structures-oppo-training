#pragma once
#include <iostream>
using namespace std;
template <typename T>
class HashArray;
// Generic Hash Table using Open Addressing (Linear Probing)
template <typename T>
class Bucket {
private:
	T elem;        // Element stored in this bucket
	int status;    // 0 = empty, 1 = used, -1 = deleted

	// Give full access to HashArray class
	friend class HashArray<T>;

public:
	// Constructor: set bucket to empty
	Bucket() {
		status = 0;
	}
};

template <typename T>
class HashArray {
	Bucket<T>* hash;  // Pointer to array of buckets
	int length;       // Current number of stored elements
	int capacity;     // Total capacity of hash table

	// Hash function: calculate index using modulo
	int h(const T& x) {
		return x % capacity; // (Works well for int type)
	}

public:
	// Constructor: initialize hash table with default capacity
	HashArray(int cap = 7) {
		capacity = cap;
		hash = new Bucket<T>[capacity];
		length = 0;
	}

	// Destructor: free the hash table memory
	~HashArray() {
		if (hash)
			delete[] hash;
		hash = nullptr;
		length = 0;
	}

	// Insert a new element into the hash table
	bool insert(const T& x) {
		int b = h(x); // Get base index
		// If the bucket is empty or deleted, insert here
		if (hash[b].status == 0 || hash[b].status == -1) {
			hash[b].status = 1;
			hash[b].elem = x;
			length++;
			return true;
		}
		// Linear probing: search for an empty spot
		for (int i = (b + 1) % capacity; i != b; i = (i + 1) % capacity) {
			if (hash[i].status == 0 || hash[i].status == -1) {
				hash[i].status = 1;
				hash[i].elem = x;
				length++;
				return true;
			}
		}
		return false; // Table is full
	}

	// Find the index of an element in the hash table
	int find(const T& x) {
		int b = h(x); // Start search at base index
		for (int i = b; hash[i].status != 0; i = (i + 1) % capacity) {
			if (hash[i].status == 1 && hash[i].elem == x)
				return i; // Found
			if (i == (b - 1 + capacity) % capacity) break; // Full loop, stop
		}
		return -1; // Not found
	}

	// Remove an element from the hash table
	bool remove(const T& x) {
		int loc = find(x); // Get location of element
		if (loc == -1)
			return false; // Not found
		hash[loc].status = -1; // Mark as deleted
		length--;
		return true;
	}

	// Print the current contents of the hash table
	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << i << ": ";
			if (hash[i].status == 1)
				cout << hash[i].elem;     // Element present
			else
				cout << "empty";          // Empty or deleted
			cout << endl;
		}
	}

	// Return current number of elements in the table
	int size() const {
		return length;
	}

	// Clear all elements (reset length and mark all as empty)
	void clear() {
		for (int i = 0; i < capacity; i++) {
			hash[i].status = 0;
		}
		length = 0;
	}
};
