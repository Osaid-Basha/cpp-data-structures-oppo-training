#pragma once
#include <iostream>
using namespace std;

// create node
template <typename T>
class BNode {
public:
    T data;
    BNode<T>* left;
    BNode<T>* right;

    // default constructor
    BNode() {
        data = 0;
        left = right = nullptr;
    }
};

// Binary Tree class
template <typename T>
class BinaryTree {
private:
    BNode<T>* Root;

public:
    // constructor
    BinaryTree() {
        Root = nullptr;
    }

    // create root
    void createRoot(T value) {
        if (!Root) {
            Root = new BNode<T>();
            Root->data = value;
        }
        else {
            cout << "Root already exists\n";
        }
    }

    // add left child
    void addLeft(BNode<T>* node, T value) {
        if (!node->left) {
            node->left = new BNode<T>();
            node->left->data = value;
        }
        else {
            cout << "Left child already exists\n";
        }
    }

    // add right child
    void addRight(BNode<T>* node, T value) {
        if (!node->right) {
            node->right = new BNode<T>();
            node->right->data = value;
        }
        else {
            cout << "Right child already exists\n";
        }
    }

    // inorder traversal (Left - Node - Right)
    void inorder(BNode<T>* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // preorder traversal (Node - Left - Right)
    void preorder(BNode<T>* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // postorder traversal (Left - Right - Node)
    void postorder(BNode<T>* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // print all traversals
    void print() {
        cout << "Inorder: ";
        inorder(Root);
        cout << endl;

        cout << "Preorder: ";
        preorder(Root);
        cout << endl;

        cout << "Postorder: ";
        postorder(Root);
        cout << endl;
    }

    // return root for external access
    BNode<T>* getRoot() {
        return Root;
    }
};
