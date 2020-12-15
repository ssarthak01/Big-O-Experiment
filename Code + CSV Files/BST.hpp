#pragma once
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

class BST {
    private:
        Node* root;
    public:
        BST();
        void insert(int key);
        void search(int key);
        void print();
};