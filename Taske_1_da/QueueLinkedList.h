#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"
using namespace std;


template <typename T>
class QueueLinkedList {
private:
	Node<T>* frontPtr; // pointer to first element
	Node<T>* rearPtr;  // pointer to last element
	int length;     // count how many elements

public:
	//constructor initialize queue
	QueueLinkedList() {
		frontPtr = nullptr;
		rearPtr = nullptr;
		length = 0;
	}

	//destructor to free memory
	~QueueLinkedList() {
		while (!empty()) {
			dequeue(); // remove every element
		}
	}

	//check if queue is empty
	bool empty() const {
		return length <= 0;
	}

	//get size of queue
	int size() const {
		return length;
	}

	//show first element
	int front() const {
		if (empty()) throw out_of_range("Queue is empty");
		return frontPtr->data;
	}

	//add value to end of queue
	void enqueue(int value) {
		//create new node to add
		Node<T>* newNode = new Node<T>(value);

		//if queue is empty, front and rear are same
		if (empty()) {
			frontPtr  = newNode;
			rearPtr   = newNode;
		}
		//if not empty, add to rear
		else {
			rearPtr->next = newNode;
			rearPtr = newNode;
		}

		length++;
	}

	//remove value from front
	void dequeue() {
		//check if queue is empty
		if (empty()) {
			cout << "Queue is empty\n";
			return;
		}

		//save old front to delete
		Node<T>* temp = frontPtr;
		frontPtr = frontPtr->next;	

		delete temp;
		length--;

		//if queue became empty after delete
		if (frontPtr == nullptr) {
			rearPtr = nullptr;
		}
	}

	//print all values in queue
	void print() const {
		Node<T>* current = frontPtr;
		cout << "Queue content: ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};
