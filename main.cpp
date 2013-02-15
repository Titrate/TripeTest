//
//  main.cpp
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/3/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include <iostream>
#include "tripe.h"
#include "studentnode.h"
#include "myfile.h"
//#include "Heap.h"
//#include "Trie.h"

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
    
    myTripe.deleteMin();
    myTripe.findMin();
    
    string file = "/Users/titrate/Workspace/cpp/DansTemplates/DansTemplates/pa2_test.txt";
    
    myTripe.initialize(file);
    myTripe.initialize(file);

    cout << "Search w" << endl;
    myTripe.search("w");
    cout << "Search b" << endl;
    myTripe.search("b");
    cout << "List and remove nodes in order" << endl;
    while (! myTripe.empty()){
        myTripe.findMin();
        myTripe.deleteMin();
    }
    
    myTripe.findMin();
    
    cout << "Add new nodes, search for them, remove and list them" << endl;
    myTripe.insert("stevenwilson", 45);
    myTripe.insert("stevenowens", 5);
    myTripe.insert("stellacliven", 102);
    myTripe.search("st");
    myTripe.findMin();
    myTripe.deleteMin();
    myTripe.findMin();
    myTripe.deleteMin();
    myTripe.findMin();
    myTripe.deleteMin();
    
    return EXIT_SUCCESS;
}

