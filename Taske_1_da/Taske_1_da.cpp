// Taske_1_da.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept> //for out_of_range
using namespace std;
#include "Node.h"
#include "array.h"
#include "linkedlist.h"
#include "StackArray.h"
#include "StackLinkedList.h"

int main()
{	
	//----------------------------------------Dynamic Arrays------------------------------------------
	//create object 
	Array<int> arr;
	//add value in buttom to top
	arr.push(10);
	arr.push(20);
	arr.push(30);
	//print value
	arr.print(); // 10 20 30
	//delete the last value in top 
	arr.pop();

	arr.print(); // 10 20

	arr.set(1, 99);//set the value
	
	cout << "Element at index 1: " << arr.get(1) << endl;
	//use try for to exception
	try {
		cout << arr.get(10); 

	}
	//out_of_range:When trying to access a location outside the array boundaries
	catch (const out_of_range& e) {
		cout << "Error: " << e.what() << endl;
	}
	
	arr.print();
	cout << "Size: " << arr.size() << endl;

	//----------------------------------------Singly Linked List------------------------------------------

	 // create object from linked list
	LinkedList<int> list;

	// add values to the list
	list.push(10);
	list.push(20);
	list.push(30);

	// print values
	cout << "Values in list:" << endl;
	list.print(); // 10 20 30

	// get value at index 1
	cout << "Value at index 1: " << list.get(1) << endl;

	// change value at index 2
	list.set(2, 40);

	// print again after change
	cout << "After set new value:" << endl;
	list.print(); //10 20 40

	// remove last value
	list.pop();

	// print after pop
	cout << "After pop:" << endl;
	list.print(); //10 20

	// show size
	cout << "Size: " << list.size() << endl;



	//----------------------------------------StackArray------------------------------------------

	// create object of stack array
	StackArray<int> s1;

	// push values
	s1.push(10);
	s1.push(20);
	s1.push(30);

	// print all values
	s1.print(); // 30 20 10

	// show top value
	cout << "Top value: " << s1.peek() << endl; // 30

	// pop the top
	s1.pop();

	// print again
	s1.print(); // 20 10

	cout << "Size: " << s1.size() << endl;
	cout << "Empty? " << (s1.isEmpty() ? "Yes" : "No") << endl;

	//----------------------------------------StackLinkedList------------------------------------------
	// create object of stack linked list
	StackLinkedList<int> s2;

	// push values
	s2.push(10);
	s2.push(20);
	s2.push(30);

	// print values
	s2.print(); // 30 20 10

	// show top value
	cout << "Top value: " << s2.peek() << endl; // 30

	// pop top value
	s2.pop();

	// print again
	s2.print(); //20 10

	cout << "Size: " << s2.size() << endl;
	cout << "Empty? " << (s2.isEmpty() ? "Yes" : "No") << endl;

 
}

