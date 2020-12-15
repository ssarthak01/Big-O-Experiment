#include "hashQP.hpp"
#include <iostream>
#include <cmath>

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
    //     cerr << "Key is already in use, DUPLICATE" << endl;
    // }
    else {
        numInsertCollision++;
        for(long int i = (index + 1) % tableSize; i <  tableSize; i = ((long int )(pow((i),2))) % tableSize) {
            // if( table[i] != NULL)
            //     cout  << index << " i is = " << i << ", Key: " << table[i]->key << endl;
            // else
            //     cout << "i is = " << i << endl;
            if(table[i] == NULL) {
                table[i] = newNode;
                //cout << "added index " << i << ", Value: " << newNode->key <<endl;
                break;
            }
            // if(table[i]->key == 47015) {
            //     cout << "key is 47015";
            //     return;
            // }
            else if(table[i]->key == key) {
                cerr << "DUPLICATE" << " \n";
                numInsertCollision++;
                return;
            }
            else {
                numInsertCollision++;;
            }
            //cout << "i is = " << i << endl;
        }
        return;
    }
}

Node* HashTable::search(int key) {
    //cout << "In Search key : " << key << endl;
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
        for(long int i = (index + 1)%tableSize; i <  tableSize; i = ((long int)((pow(i,2)))) % tableSize) {
            // if( table[i] != NULL)
            //     cout << index << " i is = " << i << ", Key: " << table[i]->key << endl;
            // else
            //     cout << "i is = " << i << endl;
            if(table[i]->key == key) { // if we find the node that has the key return it
                cout << "FOUND" << endl;
                return table[i];
            }
            else {
                cout << "COOLI" << endl;
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

