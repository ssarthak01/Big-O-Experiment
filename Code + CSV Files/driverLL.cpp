#include "LinkedList.hpp"
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <typeinfo>
#include<stdlib.h>

using namespace std;

// void write_results(char* filename, float insert_times[], float search_times[], int n) {
//     ofstream outfile(filename, out);

//     for (int i = 0; i < n; i++) {
//         // write iteration data to results_file
//         outfile << 

//     }

//     outfile.close();
// }

int main() {
    // HashTable* table = new HashTable(10);
    // table->insert(6);
    // table->insert(7);
    // table->insert(10);
    // table->insert(20);
    // table->insert(14);
    // table->insert(44);
    // table->insert(44);
    
    // // table->insert(29);
    // // table->insert(8);
    // // table->insert(29);
    // // table->insert(29);
    // // table->insert(29);
    // cout << "Printing...." << endl;
    // table->printTable();

    // cout << "Found: " << table->search(44)->key << endl;
    // return 0;

    ifstream infile;
    ofstream outfile;
    ofstream outfile2;
    LinkedList ll;
    string line;
    // clock_t startTime,endTime;
    int testData[40000];
    float insertArr[400];
    float searchArr[400];

    //opening dataset A
    infile.open("dataSetA.csv");
    if(infile.fail()) {
        cout << "Failed to open file." << endl;
    }
    //reading in from dataset A
    int index = 0;
    while(getline(infile, line, ',')) {
        testData[index] = stoi(line);
        index++;
    }
    infile.close();

   //ofstream.open("LinkedListTiming.csv");


    //INSERT
    int x = 0;
    int size = 100;
    int insertIndex = 0;
    int randIndex = 0;
    int searchIndex = 0;
    while(x < 40000) {
        // INSERTING
        double total100InTime = 0;
        double total100SeTime = 0;
        for(int i = x; i < x+size; i++) {
            clock_t startTime = clock();
            ll.insert(testData[i]);
            clock_t endTime = clock();
            total100InTime += (endTime-startTime);
        }
        double execAvgTime = (total100InTime/(double)CLOCKS_PER_SEC) / 100;
        float timeInsert = ((float)execAvgTime);
        insertArr[insertIndex] = timeInsert;
        cout << "Insert Index: " << insertIndex<< " Insert Time: " <<insertArr[insertIndex] << endl;
        insertIndex++;

        //SEARCHING
        for(int j = 0; j < size; j++) {
            randIndex = rand()%(x+size); 
            //cout << randIndex << ", ";
            clock_t startTime = clock();
            ll.search(testData[randIndex]);
            clock_t endTime = clock();
            total100SeTime += (endTime-startTime);
        }
        double avgTimeSearch = (total100SeTime/(double)CLOCKS_PER_SEC) / 100;
        float timeSearch = ((float)avgTimeSearch);
        searchArr[searchIndex] = timeSearch;
        cout << "Search Index: " << searchIndex << " Search Time: " << searchArr[searchIndex] << endl;
        searchIndex++;

        //INCREMENT X BY 100
        x += 100;
    }
    
    outfile.open("LinkedListInsert.csv");
    for(int i = 0; i < 400; i++) {
        outfile << insertArr[i] << "\n";
    }
    outfile.close();

    outfile2.open("LinkedListSearch.csv");
    for(int i = 0; i < 400; i++) {
        outfile2 << searchArr[i] << "\n";
    }
    outfile2.close();

    cout << "-----DONE-----" << endl;
    // cout << endl << endl << endl <<"----------SEARCH-----------" << endl;
    
    //SEARCH
    // int y = 0;
    // int randIndex = 0;
    // int searchIndex = 0;
    // while(y < 40000) {
    //     double total100Time = 0;
    //     for(int i = 0; i < y+size; i++) {
    //         randIndex = rand()%(y+size); 
    //         clock_t startTime = clock();
    //         table->search(testData[randIndex]);
    //         clock_t endTime = clock();
    //         total100Time += (endTime-startTime);
    //     }
    //     double execAvgTime = (total100Time/(double)CLOCKS_PER_SEC) / 100;
    //     float timeSearch = ((float)execAvgTime);
    //     searchArr[searchIndex] = timeSearch;
    //     cout << "Index: " << searchIndex << " Time: " <<insertArr[searchIndex] << endl;
    //     searchIndex++;
    //     y += 100;
    // }

    return 0;
}
