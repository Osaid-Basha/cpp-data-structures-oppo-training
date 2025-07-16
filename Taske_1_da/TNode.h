#pragma once
#include <iostream>
using namespace std;
// create node
template <typename T>
class TNode {
public:
    T data;
    TNode<T>* left;
    TNode<T>* right;
    TNode<T>* parent;

    // default constructor
    TNode() {
        data = T();
        left = right = parent = nullptr;
    }
};

