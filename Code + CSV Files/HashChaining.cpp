#include "hash.hpp"
#include <iostream>

using namespace std;

//tableSize = 40009;


node* HashTable::createNode(int key, node* next) {
    node* n = new node;
    n->key = key;
    n->next = next;
    return n;
}

HashTable::HashTable(int bsize) {
    numInsertCollision = 0;
    numSearchCollision = 0;
    tableSize = bsize;
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; i++) {
        table[i] = NULL;
    }
}

unsigned int HashTable::hashFunction(int key) {
    return (key % tableSize);
}

bool HashTable::insertItem(int key) {
    int index = hashFunction(key);
    node* newNode = createNode(key, NULL); //create a new node
    if(table[index] == NULL) {  // when hash is not hastable
        table[index] = newNode;
    }
    else {
        node* tempHead = table[index]; ///get the linkList at that has index;
        node *curr;
        int count=0;
        for(curr=tempHead; curr->next != NULL;curr = curr->next); 
        // {
        //     count++;
        //     cout << "Insert count: " << count << endl;
        // };
        curr->next = newNode;
        numInsertCollision++;
    }
    return true;
}

void HashTable::printTable() {
    //node* curr;
    for(int i = 0; i < tableSize; i++) {
        cout << "Index: " << i ;
        node* ptr = table[i];
        if(ptr == NULL) {
            cout << endl;
        } 
        else {
            while(ptr != NULL) {
                cout << ", Value: " << ptr->key ;
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
}

int HashTable::getNumOfInsertCollision() {
    return numInsertCollision;
}

node* HashTable::searchItem(int key) {
    node* found = NULL;
    int index = hashFunction(key);
   
    node* currHead = table[index];
    int count = 0;
    //cout << "Serch index:" << index << " " << currHead->key << endl;
    while(currHead->next != NULL ) {   
        //cout << "Search count: " << count << "numSearchCollision :" << numSearchCollision << endl;
        if(currHead->key == key) {
            found = currHead;
            break;
        } 
        else {
            numSearchCollision++;
            
            currHead = currHead->next;
        }
        count++;
    }
    return found;
}

int HashTable::getNumOfSearchCollision() {
    return numSearchCollision;
    //cout << "test " << endl;
}