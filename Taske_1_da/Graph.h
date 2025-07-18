#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Graph {
private:
	vector<T> nodes;                 // list of nodes (labels)
	vector<vector<int>> adjList;     // adjacency list using indices

	// helper: find index of node, or return -1 if not found
	int getIndex(T value) {
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i] == value)
				return i;
		}
		return -1;
	}

	// helper: add node if it doesn't exist
	int ensureNode(T value) {
		int index = getIndex(value);
		if (index == -1) {
			nodes.push_back(value);
			adjList.push_back(vector<int>());
			return nodes.size() - 1;
		}
		return index;
	}

public:
	// add edge between u and v (undirected)
	void addEdge(T u, T v) {
		int i = ensureNode(u);
		int j = ensureNode(v);
		adjList[i].push_back(j);
		adjList[j].push_back(i); // undirected
	}

	// print adjacency list
	void print() {
		cout << "Adjacency List:\n";
		for (int i = 0; i < nodes.size(); i++) {
			cout << nodes[i] << ": ";
			for (int j : adjList[i]) {
				cout << nodes[j] << " ";
			}
			cout << endl;
		}
	}

	// DFS (Depth First Search)
	void DFS(T start) {
		int s = getIndex(start);
		if (s == -1) return;

		vector<bool> visited(nodes.size(), false);
		cout << "DFS from " << start << ": ";
		dfsHelper(s, visited);
		cout << endl;
	}

	void dfsHelper(int index, vector<bool>& visited) {
		visited[index] = true;
		cout << nodes[index] << " ";

		for (int neighbor : adjList[index]) {
			if (!visited[neighbor])
				dfsHelper(neighbor, visited);
		}
	}

	// BFS (Breadth First Search)
	void BFS(T start) {
		int s = getIndex(start);
		if (s == -1) return;

		vector<bool> visited(nodes.size(), false);
		queue<int> q;

		q.push(s);
		visited[s] = true;

		cout << "BFS from " << start << ": ";

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			cout << nodes[current] << " ";

			for (int neighbor : adjList[current]) {
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					q.push(neighbor);
				}
			}
		}
		cout << endl;
	}
};
