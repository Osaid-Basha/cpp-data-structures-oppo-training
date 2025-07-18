#pragma once
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100; // maximum number of nodes

class BasicGraph {
private:
	vector<int> adj[MAX]; // array of adjacency lists
	int numNodes;

public:
	// constructor to set number of nodes
	BasicGraph(int n) {
		numNodes = n;
	}

	// add edge between two nodes
	void addEdge(int from, int to, bool directed = false) {
		adj[from].push_back(to); // add edge from → to

		if (!directed) {
			adj[to].push_back(from); // if undirected, add reverse edge
		}
	}

	// print adjacency list
	void print() {
		for (int i = 0; i < numNodes; i++) {
			cout << i << " = ";
			for (int neighbor : adj[i]) {
				cout << neighbor << " ";
			}
			cout << endl;
		}
	}
};
