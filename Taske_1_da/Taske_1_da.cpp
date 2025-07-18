// Taske_1_da.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept> //for out_of_range
using namespace std;
#include "Node.h"
#include "array.h"
#include "singleLinkedList.h"
#include "StackArray.h"
#include "StackLinkedList.h"
#include "QueueArray.h"
#include "QueueLinkedList.h"
#include "DoublyLinkedList.h"
#include "QueueArrayCircular.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "HashArray.h"
#include "Heap.h"
#include "BasicGraph.h"
#include "Trie.h"
#include "DisjointSet.h"
#include "Graph.h"
int main()
{	
	cout << "----------------------------------------Dynamic Arrays------------------------------------------" << endl;
	
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
	
	
	cout << "----------------------------------------Singly Linked List------------------------------------------" << endl;
	 // create object from linked list
	singleLinkedList<int> list;

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



	
	cout << "----------------------------------------StackArray------------------------------------------" << endl;
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

	cout << "----------------------------------------StackLinkedList------------------------------------------" << endl;
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

	cout << "----------------------------------------queue array------------------------------------------"<<endl;
 
	// Create queue object
	QueueArray<int> q;

	// Enqueue elements
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	// Print the queue
	q.print(); // Output: Queue content: 10 20 30

	// Show front element
	try {
		cout << "Front: " << q.frontValue() <<endl; // Output: 10
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}

	// Dequeue an element
	q.dequeue();

	// Print after dequeue
	q.print(); // Output: Queue content: 20 30

	// Enqueue more elements
	q.enqueue(40);
	q.enqueue(50);

	// Print again
	q.print(); // Output: Queue content: 20 30 40 50

	// Show size
	cout << "Size: " << q.size() << endl;

	// Try dequeueing all to test empty case
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue(); // Now queue should be empty

	// Test front on empty queue
	try {
		cout << "Front: " << q.frontValue() << endl;
	}
	catch (const out_of_range& e) {
		cout << "Exception: " << e.what() << endl; // Should print error
	}
	cout << "----------------------------------------queue array circular------------------------------------------" << endl;

	// Create queue object
	QueueArrayCircular<int> q2;
	

	// Enqueue elements
	q2.enqueue(10);
	q2.enqueue(20);
	q2.enqueue(30);

	// Print the queue
	q2.print(); // Output: Queue content: 10 20 30

	// Show front element
	try {
		cout << "Front: " << q2.frontValue() << endl; // Output: 10
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}

	// Dequeue an element
	q2.dequeue();

	// Print after dequeue
	q2.print(); // Output: Queue content: 20 30

	// Enqueue more elements
	q2.enqueue(40);
	q2.enqueue(50);

	// Print again
	q2.print(); // Output: Queue content: 20 30 40 50

	// Show size
	cout << "Size: " << q.size() << endl;

	// Try dequeueing all to test empty case
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue(); // Now queue should be empty

	// Test front on empty queue
	try {
		cout << "Front: " << q2.frontValue() << endl;
	}
	catch (const out_of_range& e) {
		cout << "Exception: " << e.what() << endl; // Should print error
	}
	cout << "----------------------------------------queue linked List------------------------------------------" << endl;
	//create object from queue
	QueueLinkedList<int> s;

	//add values (enqueue)
	s.enqueue(10);
	s.enqueue(20);
	s.enqueue(30);

	//print all values
	s.print(); // Queue content: 10 20 30

	//remove one value from front
	s.dequeue();

	//print again
	s.print(); // Queue content: 20 30

	//show the front value
	cout << "Front value: " << s.front() << endl; // 20

	//show size
	cout << "Size: " << s.size() << endl; // 2
	s.dequeue();
	s.dequeue();
	//check if empty
	// Test front on empty queue
	try {
		cout << "Front: " << s.front() << endl;
	}
	catch (const out_of_range& e) {
		cout << "Exception: " << e.what() << endl; // Should print error
	}
	cout << "----------------------------------------Doubly Linked List------------------------------------------" << endl;
	//create object from doubly linked list
	DoublyLinkedList<int> dlist;

	//add values
	dlist.push(10);
	dlist.push(20);
	dlist.push(30);

	//print all values forward
	cout << "Print forward:";
	dlist.printForward(); // 10 20 30

	//print all values backward
	cout << "Print backward:" ;
	dlist.printBackward(); // 30 20 10

	//get value at index 1
	cout << "Value at index 1: " << dlist.get(1) << endl; // 20

	//change value at index 1
	dlist.set(1, 99);

	//print after change
	cout << "After set new value:" ;
	dlist.printForward(); // 10 99 30

	//remove last value
	dlist.pop();

	//print after pop
	cout << "After pop:" ;
	dlist.printForward(); // 10 99

	//show size
	cout << "Size: " << dlist.size() << endl; // 2

	//try to get value out of range
	try {
		cout << dlist.get(10) << endl;
	}
	catch (const out_of_range& e) {
		cout << "Exception: " << e.what() << endl;
	}

	cout << "----------------------------------------Binary Search Tree------------------------------------------" << endl;
	// Create a binary search tree
	BinarySearchTree<int> bst;
	// Insert values into the BST
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(10);
	bst.insert(25);
	// Print the BST in-order
	cout << "In-order traversal of BST: ";

	cout <<endl << "print_LNR: ";
	bst.print_LNR(bst.getRoot()); // Should print: 10 20 25 30 40
	cout << endl;
	cout << "print_NLR: ";
	bst.print_RNL(bst.getRoot()); // Should print: 40 30 25 20 10
	cout << endl;
	cout << "print_NLR: ";
	bst.print_NLR(bst.getRoot()); // Should print: 30 20 10 25 40
	cout << endl;
	// Show size of the BST
	cout << "Size of BST: " << bst.size() << endl; // Should print 5

	bst.insert(20); 

	cout << endl << "print_LNR: ";
	bst.print_LNR(bst.getRoot()); // Should print: 10 20 25 30 40
	cout << endl;


	cout << "----------------------------------------Binary Tree------------------------------------------" << endl;

	// create object of Binary Tree
	BinaryTree<int> tree;

	// create root node
	tree.createRoot(10);
	BNode<int>* root = tree.getRoot();

	// add left and right children to root
	tree.addLeft(root, 5);
	tree.addRight(root, 15);

	// add children to the left subtree
	tree.addLeft(root->left, 2);
	tree.addRight(root->left, 7);

	// add children to the right subtree
	tree.addLeft(root->right, 12);
	tree.addRight(root->right, 20);

	// print all traversals
	cout << "Inorder: ";
	tree.inorder(tree.getRoot()); // Output: 2 5 7 10 12 15 20
	cout << endl;

	cout << "Preorder: ";
	tree.preorder(tree.getRoot()); // Output: 10 5 2 7 15 12 20
	cout << endl;

	cout << "Postorder: ";
	tree.postorder(tree.getRoot()); // Output: 2 7 5 12 20 15 10
	cout << endl;
	cout << "----------------------------------------Hash Array------------------------------------------" << endl;


	// Create a HashArray object
	HashArray<int> h;

	// Insert values
	h.insert(10);
	h.insert(22);
	h.insert(3);

	// Print all elements
	h.print();

	// Remove a value
	h.remove(22);

	// Print after removal
	cout << "After removing 22:" << endl;
	h.print();

	// Find the index of a value
	int index = h.find(10);
	cout << "Index of 10: " << index << endl;

	// Show current size
	cout << "Size: " << h.size() << endl;

	cout << "----------------------------------------Hash linked list------------------------------------------" << endl;

	// create object of hash table
	HashArray<int> m;

	// insert values
	m.insert(10);  // insert 10
	m.insert(17);  // insert 17 → same index as 10 (collision)
	m.insert(3);   // insert 3 → different index
	m.insert(24);  // insert 24 → collision with 10 & 17

	// print all values
	cout << "Table content after inserts:" << endl;
	m.print(); // print linked lists in each bucket

	// try inserting duplicate
	cout << "Trying to insert duplicate (17):" << endl;
	bool result = m.insert(17); // already exists
	cout << (result ? "Inserted" : "Already exists") << endl;

	// insert more values
	m.insert(5);
	m.insert(12);

	// print again
	cout << "Table content after more inserts:" << endl;
	m.print();

	// show size
	cout << "Size: " << m.size() << endl;

	cout << "----------------------------------------Min Heap------------------------------------------" << endl;

	// create MinHeap object
	MinHeap<int> heap;

	// insert values
	heap.insert(30);
	heap.insert(20);
	heap.insert(40);
	heap.insert(10);

	// print current heap
	cout << "Heap elements: ";
	heap.print(); // should show: 10 20 40 30 or similar structure

	// get minimum value
	cout << "Min value: " << heap.getMin() << endl;

	// remove min
	heap.removeMin();

	// print after removal
	cout << "After removing min: ";
	heap.print();

	// insert more
	heap.insert(5);
	heap.insert(35);

	// print again
	cout << "After inserting 5 and 35: ";
	heap.print();

	// size
	cout << "Size: " << heap.getSize() << endl;

	cout << "----------------------------------------Basic Graph------------------------------------------" << endl;

	// create object with 6 nodes (0 to 5)
	BasicGraph g(6);

	// add edges
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	// print adjacency list
	cout << "Graph content:" << endl;
	g.print();
	cout << "----------------------------------------Trie Structure------------------------------------------" << endl;

	// Create object of Trie
	Trie trie;

	// Add words to trie
	trie.insert("cat");
	trie.insert("car");
	trie.insert("dog");

	// Search for full words
	cout << "Search for 'cat': " << (trie.search("cat") ? "Found" : "Not Found") << endl;
	cout << "Search for 'can': " << (trie.search("can") ? "Found" : "Not Found") << endl;

	// Check if any word starts with given prefix
	cout << "Starts with 'ca': " << (trie.startsWith("ca") ? "Yes" : "No") << endl;
	cout << "Starts with 'do': " << (trie.startsWith("do") ? "Yes" : "No") << endl;
	cout << "Starts with 'z': " << (trie.startsWith("z") ? "Yes" : "No") << endl;
	cout << "------------------------------------------Union-Find (Disjoint Set)------------------------------------------" << endl;

	// create object with 6 elements (0 to 5)
	DisjointSet ds(6);

	// unite some pairs
	ds.unite(0, 1); // connect 0 and 1
	ds.unite(2, 3); // connect 2 and 3
	ds.unite(4, 5); // connect 4 and 5
	ds.unite(2, 4); // merge set(2,3) with set(4,5)

	// check connections
	cout << "Are 0 and 1 connected? " << (ds.connected(0, 1) ? "Yes" : "No") << endl;
	cout << "Are 1 and 2 connected? " << (ds.connected(1, 2) ? "Yes" : "No") << endl;
	cout << "Are 3 and 5 connected? " << (ds.connected(3, 5) ? "Yes" : "No") << endl;

	// print parent array
	ds.printParents();
	cout << "------------- Graph without map -------------" << endl;

	// create graph using letters
	Graph<string> v;

	// add edges
	v.addEdge("A", "B");
	v.addEdge("A", "C");
	v.addEdge("B", "D");
	v.addEdge("C", "E");
	v.addEdge("D", "F");
	v.addEdge("E", "F");

	// print graph
	v.print();

	// DFS and BFS
	v.DFS("A");
	v.BFS("A");

}

