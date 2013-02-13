//
//  Tripe.h
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/8/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __DansTemplates__Tripe__
#define __DansTemplates__Tripe__

#include <iostream>

#include "Trie.h"
#include "Heap.h"
#include "StudentNode.h"
#include "TxtFile.h"


class Tripe {
    Heap<StudentNode> minHeap;
    Trie<StudentNode> nameLogger;
    StudentNode** curList;
    
public:
    // These are the the req'ed method sigs
    void insert(string name, int grade);
    void search(string findMatches);
    void findMin();
    void initialize(string filePath);
    
    //EC
    void deleteMin();
};

#endif /* defined(__DansTemplates__Tripe__) */
