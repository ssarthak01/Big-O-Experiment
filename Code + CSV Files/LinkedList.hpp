#pragma once
#include <iostream>

using namespace std;

struct Node {
    int key; 
    Node* next;
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList();
        void insert(int newKey);
        Node* search(int searchKey);
        void print();
};
