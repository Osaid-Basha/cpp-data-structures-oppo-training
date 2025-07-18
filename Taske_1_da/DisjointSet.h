#pragma once
#include <iostream>
using namespace std;

class DisjointSet {
private:
	int* parent; // array to store parent of each element
	int* rank;   // array to store rank (depth) of each tree
	int size;

public:
	// constructor
	DisjointSet(int n) {
		size = n;
		parent = new int[n];
		rank = new int[n];

		// initialize: every node is its own parent
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	// destructor
	~DisjointSet() {
		delete[] parent;
		delete[] rank;
	}

	// find root of element (with path compression)
	int find(int x) {
		// if x is not its own parent, find root and compress path
		if (parent[x] != x)
			parent[x] = find(parent[x]);
		return parent[x];
	}

	// unite two sets
	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);

		// already in same set
		if (rootX == rootY)
			return;

		// attach smaller rank tree under root of higher rank
		if (rank[rootX] < rank[rootY]) {
			parent[rootX] = rootY;
		}
		else if (rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		else {
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}

	// check if two elements are connected
	bool connected(int x, int y) {
		return find(x) == find(y);
	}

	// print parent array
	void printParents() {
		cout << "Parent array: ";
		for (int i = 0; i < size; i++)
			cout << parent[i] << " ";
		cout << endl;
	}
};
