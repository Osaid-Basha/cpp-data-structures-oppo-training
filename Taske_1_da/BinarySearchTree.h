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





// Binary Search Tree class
template <typename T>
class BinarySearchTree {
private:
    TNode<T>* Root;
    int length;

public:
    // constructor
    BinarySearchTree() {
        Root = nullptr;
        length = 0;
    }

    // insert new node
    void insert(T value) {
        TNode<T>* newTNode = new TNode<T>();
        newTNode->data = value;

        if (!Root) {
            Root = newTNode; // if root is null
        }
        else {
            TNode<T>* p = nullptr;
            TNode<T>* c = Root;

            // search for correct position
            while (c) {
                p = c;
                if (value > c->data) {
                    c = c->right;
                }
                else {
                    c = c->left; 
                }
            }

            // insert node
            if (value > p->data) {
                p->right = newTNode;
            }
            else {
                p->left = newTNode;
            }
            newTNode->parent = p;
        }

        length++;
    }

    // inorder (Left - Node - Right)
    void print_LNR(TNode<T>* p) {
        if (!p) return;
        print_LNR(p->left);
        cout << p->data << " ";
        print_LNR(p->right);
    }

    // postorder (Right - Node - Left)
    void print_RNL(TNode<T>* p) {
        if (!p) return;
        print_RNL(p->right);
        cout << p->data << " ";
        print_RNL(p->left);
    }

    // preorder (Node - Left - Right)
    void print_NLR(TNode<T>* p) {
        if (!p) return;
        cout << p->data << " ";
        print_NLR(p->left);
        print_NLR(p->right);
    }

   

    // delete tree
    void clear(TNode<T>* p) {
        if (!p) return;
        clear(p->left);
        clear(p->right);
        delete p;
    }


	int size() {
		return length ;
	}

    // get root for external traversals
    TNode<T>* getRoot() {
        return Root;
    }
};
