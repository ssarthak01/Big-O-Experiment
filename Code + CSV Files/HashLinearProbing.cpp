#include "hashLP.hpp"
#include <iostream>

using namespace std;

HashTable::HashTable(int bsize) {
    numInsertCollision = 0;
    numSearchCollision = 0;
    tableSize = bsize;
    table = new Node*[tableSize];
    for(int i = 0; i < tableSize; i++) {
        table[i] = NULL;
    }
}

Node* HashTable::createNode(int key) {
    Node* n = new Node;
    n->key = key;
    return n;
}

unsigned int HashTable::hashFunction(int key) {
    return (key % tableSize);
}

void HashTable::insert(int key) {
    numInsertCollision = 0;
    Node* newNode = createNode(key);
    int index = hashFunction(key);
    if(table[index] == NULL) { // when index is empty 
        table[index] = newNode; // set empty spot to new node
        //cout << "added index " << index << ", Value: " << newNode->key <<endl;
    }
    // else if(table[index]->key == key) {
    //     cout << "CHECK" << " \n";
    // }
    else {
        numInsertCollision++;
        for(int i = (index + 1) % tableSize; i < tableSize; i = (i+1) % tableSize) {
            //cout << "i is = " << i << endl;
            if(table[i] == NULL) {
                table[i] = newNode;
                //cout << "added index " << i << ", Value: " << newNode->key <<endl;
                break;
            }
            else if(table[i]->key == key) {
                 numInsertCollision++;
                //cout << "DUPLICATE" << " \n";
                break;
            }
            else {
                numInsertCollision++;
            }
        }
    }
}

Node* HashTable::search(int key) {
    numSearchCollision = 0;
    int index = hashFunction(key);
    //if empty spot return null
    if(table[index] == NULL) {
        return NULL;
    }
    //if at the index we find the key
    else if(table[index]->key == key) {
        return table[index];
    }
    else { // have to linear probe if we can't find it
        numSearchCollision++;
        for(int i = (index + 1) % tableSize; i < tableSize; i = (i+1)%tableSize) {
            if(table[i]->key == key) { // if we find the node that has the key return it
                return table[i];
            }  else {
                numSearchCollision++;
            }
            // else if(table[i]->key == NULL) { //if we encounter empty spot
            //     return NULL;
            // }
        }
        return NULL;
    }
}

int HashTable::getNumInsertCollision() {
    return numInsertCollision;
}
int HashTable::getNumSearchCollision() {
    return numSearchCollision;
}

void HashTable::printTable() {
    for(int i = 0; i < tableSize; i++) {
        if(table[i] != NULL) {
            cout << "Index: " << i << ", Value: " << table[i]->key << endl;
        }
        else {
            cout << "Index: " << i << ", Value: " << "EMPTY" << endl;
        }
    }
}

