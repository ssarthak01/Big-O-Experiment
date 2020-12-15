#include "BST.hpp"
#include <iostream>

using namespace std;

BST::BST() {
    root = NULL;
}

Node* insertHelper(Node* T, int key) {
    Node* newR = T;
    if(T == NULL) {
        Node* node = new Node;
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        newR = node;
        return newR;
    }
    else {
        if(key < T->key) {
            newR->left = insertHelper(T->left, key);
        }
        else if(key > T->key) {
            newR->right = insertHelper(T->right, key);
        }
        return newR;
    }
} 

void BST::insert(int key) {
   root = insertHelper(root,key);
}

Node* searchHelper(Node* n, int key) {
    if(n == NULL) {
        return NULL;
    }
    else if(n->key == key) {
        return n;
    }
    else if(n->key > key) {
        return searchHelper(n->left, key);
    }
    else if(n->key < key) {
        return searchHelper(n->right, key);
    }
}

void BST::search(int key) {
    Node* search = searchHelper(root, key);
    // if(search != 0) {
    //     cout << "Found: " << search->key << endl;
    // }
    // else {
    //     cout << "Not found." << endl;
    // }
}

void printHelp(Node* n) {
    if(n == 0) {
        return;
    }
    else {
        printHelp(n->left);
        cout << "Value: " << n->key << endl;
        printHelp(n->right);
    }
}

void BST::print() {
    if(root == 0) {
        cout << "Empty tree." << endl;
    }
    else {
        printHelp(root);
    }
}