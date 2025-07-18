#pragma once

#include <string>
class TrieNode {
public:
	bool isEnd;            // true if end of word
	TrieNode* children[26]; // array of 26 letters (a to z)

	// constructor
	TrieNode() {
		isEnd = false;
		for (int i = 0; i < 26; i++)
			children[i] = nullptr;
	}
};


using namespace std;

class Trie {
private:
	TrieNode* root;

public:
	// constructor
	Trie() {
		root = new TrieNode();
	}

	// insert word into trie
	void insert(const string& word) {
		TrieNode* node = root;
		for (char c : word) {
			int index = c - 'a'; // convert char to index (0 - 25)
			if (node->children[index] == nullptr)
				node->children[index] = new TrieNode();
			node = node->children[index];
		}
		node->isEnd = true;
	}

	// search full word
	bool search(const string& word) {
		TrieNode* node = root;
		for (char c : word) {
			int index = c - 'a';
			if (node->children[index] == nullptr)
				return false;
			node = node->children[index];
		}
		return node->isEnd;
	}

	// check if any word starts with prefix
	bool startsWith(const string& prefix) {
		TrieNode* node = root;
		for (char c : prefix) {
			int index = c - 'a';
			if (node->children[index] == nullptr)
				return false;
			node = node->children[index];
		}
		return true;
	}
};
