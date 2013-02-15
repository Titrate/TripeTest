//
//  Tripe.cpp
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/8/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include "tripe.h"


/*
 * Create a new student node with given data, insert into trie and heap
 *
 * This implementation is not satifying. I should create the node here and
 * give both the heap and trie the address. However, the heap allocates memory
 * as needed. This is an expensive way to load the heap. I'm very dissatisfied.
 * I do not want to pour lots of time in to fix this though.
 */
void Tripe::insert(string name, int grade){
    StudentNode tempNode = StudentNode(name, grade);
    StudentNode* heapObj_p = minHeap.insert(tempNode);
    nameLogger.insert(heapObj_p, name);
}

/*
 * Find all matches and print them
 */
void Tripe::search(string findMatches){
    StudentNode** list = nameLogger.find(findMatches);
    int count = 0;
    while (list[count] != NULL){
        cout << list[count]->getName() <<
        "\t" << list[count]->getScore() << endl;
        count += 1;
    }
}

/*
 * Print min value
 */
void Tripe::findMin(){
    if (! minHeap.empty()){
        StudentNode* min = minHeap.getMin();
        if (min != NULL)
            cout << min->getName() << "\t" << min->getScore() << endl;
    }
}

/*
 * Load a file of name grade pairs (separated with '\t') into the tripe
 */
void Tripe::initialize(string filePath){
    if (minHeap.empty()){
        MyFile file;
        string** fileData = new string *[1000];
        
        int filesize = file.readDataToString(filePath, fileData);
        
        string name;
        string score;
        unsigned long splitSpot;
        
        for (int j = 0; j < filesize; j++){
            splitSpot = fileData[j]->find("\t");
            if (splitSpot != string::npos){
                name = fileData[j]->substr(0, splitSpot);
                score = fileData[j]->substr(splitSpot+1);
                insert(name, atoi(score.c_str()));
            }
        }
        delete[] fileData;
    }
}

/*
 * This is extra credit
 * Delete min, easy for heap, Less easy in Trie (not difficult though)
 */
void Tripe::deleteMin(){
    if (! minHeap.empty()){
        StudentNode* deleted = minHeap.deleteMin();
        nameLogger.deleteName(deleted->getName());
    }
}

