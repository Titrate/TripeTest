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
#include "TxtFile.h"

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
    string file = "/Users/titrate/Workspace/cpp/DansTemplates/pa2_test.txt";
    
    myTripe.initialize(file);
    myTripe.search("jo");
    myTripe.search("ma");
    myTripe.search("e");
    myTripe.search("d");
    myTripe.findMin();
    
    return EXIT_SUCCESS;
}

