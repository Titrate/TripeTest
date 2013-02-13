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


class Tripe {
    Heap<StudentNode> minHeap;
    Trie<StudentNode> nameLogger;
    StudentNode** curList;
    
public:
    void insert(StudentNode node){
        minHeap.insert(node);
        nameLogger.insert(&node, node.getName());
    };
    
    StudentNode** find(string findMatches){
        return nameLogger.find(findMatches);
    }
    
    StudentNode* findMin(){
        return minHeap.getMin();
    }
};

#endif /* defined(__DansTemplates__Tripe__) */
