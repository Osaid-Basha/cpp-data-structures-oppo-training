📚 Data Structures - Week Implementation

This repository contains the implementation of fundamental data structures using C++.Each data structure is well-documented, tested, and organized for clarity and future reference.

🧠 Data Structures Descriptions

1. Dynamic Array (array.h)

A dynamic array that automatically resizes when capacity is reached. Implemented from scratch using raw pointers.

Time Complexity:

Access: O(1)

Insert (end): O(1) amortized

Delete (end): O(1)

Resize: O(n)

Space Complexity: O(n)

2. Singly Linked List (singleLinkedList.h)

A linear structure where each node points to the next. Supports insertion, deletion, and access by index.

Time Complexity:

Insert (end): O(n)

Delete (end): O(n)

Access by index: O(n)

Space Complexity: O(n)

3. Stack using Array (StackArray.h)

LIFO structure backed by dynamic array. Fast push/pop at the top.

Time Complexity:

Push: O(1) (amortized)

Pop: O(1)

Peek: O(1)

Space Complexity: O(n)

4. Stack using Linked List (StackLinkedList.h)

LIFO stack implemented using singly linked list.

Time Complexity:

Push: O(1)

Pop: O(1)

Peek: O(1)

Space Complexity: O(n)

5. Queue using Array (QueueArray.h)

FIFO structure with circular array logic. Efficient enqueue/dequeue from both ends.

Time Complexity:

Enqueue: O(1)

Dequeue: O(1)

Front: O(1)

Space Complexity: O(n)

6. Queue using Linked List (QueueLinkedList.h)

Queue built using singly linked list, tracking front and rear.

Time Complexity:

Enqueue: O(1)

Dequeue: O(1)

Front: O(1)

Space Complexity: O(n)

7. Doubly Linked List (DoublyLinkedList.h)

Each node stores reference to both previous and next. Allows traversal in both directions.

Time Complexity:

Insert (end): O(1)

Delete (end): O(1)

Access by index: O(n)

Space Complexity: O(n)

8. Circular Linked List (CircularLinkedList.h)

Linked list where last node connects to the first, forming a cycle. Useful for round-robin tasks.

Time Complexity:

Insert: O(1)

Delete: O(1)

Traverse: O(n)

Space Complexity: O(n)

9. Binary Tree (BinaryTree.h)

General binary tree implementation with left and right children, and support for preorder, inorder, and postorder traversals.

Time Complexity:

Insert (specific position): O(1)

Traverse: O(n)

Space Complexity: O(n)

10. Binary Search Tree (BinarySearchTree.h)

A binary tree where the left child is smaller, and the right child is larger. Supports fast search and ordered traversal.

Time Complexity:

Insert: O(log n) average, O(n) worst-case

Traverse: O(n)

Space Complexity: O(n)

11. Hash Table (HashTable.h)

Implements a basic hash table with collision handling using chaining (linked lists). Supports insert, search, and delete operations.

Time Complexity:

Insert: O(1) average, O(n) worst-case

Search: O(1) average, O(n) worst-case

Delete: O(1) average, O(n) worst-case

Space Complexity: O(n)

12. Min Heap (MinHeap.h)

Implements a binary min heap using a dynamic array. Each parent node is less than its children.

Time Complexity:

Insert: O(log n)

Remove (min): O(log n)

Peek (min): O(1)

Space Complexity: O(n)

13. Basic Graph (BasicGraph.h)

Implements an adjacency list representation of an unweighted graph without using map or unordered_map. Supports adding edges and performing traversals.

Time Complexity:

Add Edge: O(1)

DFS/BFS: O(V + E)

Space Complexity: O(V + E)

14. Trie (Trie.h)

A tree-like data structure used for storing strings efficiently, especially useful for prefix-based queries.

Time Complexity:

Insert: O(length)

Search: O(length)

Space Complexity: O(n * alphabet_size)

15. Union-Find (Disjoint Set) (DisjointSet.h)

Implements disjoint-set with path compression and union by rank, ideal for grouping connected components.

Time Complexity:

Union: O(α(n))

Find: O(α(n))

Space Complexity: O(n)

16. Graph Traversals (DFS / BFS)

Implemented DFS() and BFS() traversal methods inside the BasicGraph.h file.

Time Complexity: O(V + E)

Space Complexity: O(V)

✅ Usage Example (Taske_1_da.cpp)

The file Taske_1_da.cpp includes demonstrations and test cases for:

Inserting and deleting values

Accessing and modifying elements

Printing current data

Traversing structures (DFS, BFS, preorder, etc.)

Exception handling for invalid input

▶️ How to Compile and Run

g++ Taske_1_da.cpp -o runme
./runme

📁 Folder Structure

.
├── array.h
├── singleLinkedList.h
├── StackArray.h
├── StackLinkedList.h
├── QueueArray.h
├── QueueLinkedList.h
├── DoublyLinkedList.h
├── CircularLinkedList.h
├── BinaryTree.h
├── BinarySearchTree.h
├── HashTable.h
├── MinHeap.h
├── BasicGraph.h
├── Trie.h
├── DisjointSet.h
├── Node.h
└── Taske_1_da.cpp

🔍 How to Run Tests

All test cases are located inside Taske_1_da.cpp

Simply compile and run as shown above

Output will display results for each structure and traversal

