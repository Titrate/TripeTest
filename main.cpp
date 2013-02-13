//
//  main.cpp
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/3/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include <iostream>
#include "Tripe.h"
#include "StudentNode.h"
#include "FileOps.h"

using namespace std;

/*
 * This is the main for testing the heap
 */

//int main(int argc, const char * argv[])
//{
//    // Test the heap logic.
////    bool done = false;
//    
//    string a = "ghi";
//    string b = "lmj";
//    string c = "ske";
//    string d = "zie";
//    string e = "wrr";
//    string f = "def";
//
//    int myIntAry[] = {12521, 2452 , 2345, -2432, 134223,13432};
//    
//    Heap<int> myHeap= Heap<int>( myIntAry, 6);            // The heap to test
//
//    Heap<string> myHeap1;            // The heap to test
//    
//    myHeap1.insert(a);
//    myHeap1.insert(b);
//    myHeap1.insert(c);
//    myHeap1.insert(d);
//    myHeap1.insert(e);
//    myHeap1.insert(f);
//                                            
//    for (int i = 0; i < 6; i++) {
//        cout << *myHeap.deleteMin() << endl;
//    }
//    
//    for (int i = 0; i < 6; i++) {
//        cout << *myHeap1.deleteMin() << endl;
//    }
//    
//    return EXIT_SUCCESS;
//}

//int main(int argc, const char * argv[]){
//    Trie<string> testTrie;
//    string** results;
//    
//    string a = "ghi";
//    string b = "ghj";
//    string c = "gh";
//    string c = "ske";
//    string d = "zie";
//    string e = "wrr";
//    string f = "def";
//    
//    testTrie.insert(&a, a);
//    testTrie.insert(&b, b);
//    results = testTrie.find(c);
//    
//    int ndx = 0;
//    while (results[ndx] != NULL){
//        cout << *results[ndx] << endl;
//        ndx += 1;
//    }
//    
//    return EXIT_SUCCESS;
//}

int main(int argc, const char * argv[]){
    Tripe myTripe;
    
    StudentNode mariam;
    StudentNode mark;
    StudentNode mallocs;
    
    StudentNode** list;
    StudentNode* minEntry;
    
    string** fileData = new string *[100];
    
    TxtFile file;
    
    int filesize = file.readDataToString("/Users/titrate/Workspace/cpp/DansTemplates/student.txt", fileData);
    
    cout << filesize << endl;
    
    for (int i =0; i < filesize; i++)
        cout << *fileData[i] << endl;
    
    string name;
    string score;
    unsigned long splitSpot;
    
    for (int j = 0; j < filesize; j++){
        splitSpot = fileData[j]->find("\t");
        name = fileData[j]->substr(0, splitSpot);
        score = fileData[j]->substr(splitSpot+1j);
        cout << name << ":" << score << endl;
    }
    
    mariam.setName("MariamLamifi");
    mariam.setScore(97);
    
    mark.setName("MarkMullin");
    mark.setScore(45);
    
    mallocs.setName("Malloc");
    mallocs.setScore(10);
    
    
    myTripe.insert(mariam);
    myTripe.insert(mark);
    myTripe.insert(mallocs);
    
    list = myTripe.find("ma");
    
    int count = 0;
    while (list[count] != NULL){
        cout << list[count]->getName() << endl;
        cout << list[count]->getScore() << endl;
        count += 1;
    }
    
    
    list = myTripe.find("be");
    
    count = 0;
    while (list[count] != NULL){
        cout << list[count]->getName() << endl;
        cout << list[count]->getScore() << endl;
        count += 1;
    }
    
    minEntry = myTripe.findMin();
    
    cout << minEntry->getName() << endl;
    cout << minEntry->getScore() << endl;
    
    return EXIT_SUCCESS;
}

