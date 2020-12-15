#ifndef HASHLP_HPP
#define HASHLP_HPP
#include <string>
using namespace std;

struct Node {
    int key;
};

class HashTable {
    Node** table;
    long numInsertCollision;
    int numSearchCollision;
    Node* createNode(int key);
    int tableSize;

public: 
    HashTable(int bSize);
    void insert(int key);
    unsigned int hashFunction(int key);
    void printTable();
    int getNumInsertCollision();
    int getNumSearchCollision();
    Node* search(int key);

};

#endif