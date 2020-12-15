#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insert(int newKey) {
    if(head == NULL) {
        head = new Node;
        head->key = newKey;
        head->next = NULL;
        return;
    }
    Node* a = new Node; 
    a->key = newKey;
    a->next = NULL;
    if(head->next == NULL) {
        head->next = a;
        return;
    }

    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = a;
}

Node* LinkedList::search(int searchKey) {
    Node* search = head;
    while(search != NULL && search->key != searchKey) {
        search = search->next;
    }
    return search;
}

void LinkedList::print() {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << "Value: " << ptr->key << " " << endl;
        ptr = ptr->next;
    }
}