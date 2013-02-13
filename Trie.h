//
//  Trie.h
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/8/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __DansTemplates__Trie__
#define __DansTemplates__Trie__

#include <iostream>
#include "TrieNode.h"

using namespace std;

const int MAXRESULTS = 5000;

template<class T>
class Trie {
    TrieNode<T>* root;
    T** foundObjs;
    
public:
    Trie<T>(){
        root = new TrieNode<T>;
        foundObjs = new T *[MAXRESULTS];
    }
    T** find(string toFind);
    void insert(T* obj, string name);
    TrieNode<T>* followString(string toFollow);
    void xplorSubPaths(TrieNode<T>* node, int& insertNdx);
};

#endif /* defined(__DansTemplates__Trie__) */

template<class T>
void Trie<T>::insert(T* obj, string name){
    int insertNdx;          // The index to insert into the nodes child arrray
    char curLetter;         // The current letter being inserted
    TrieNode<T>* curNode = root;   // The node we are inserting into
    for (int i = 0; i < name.length(); i++){
        curLetter = tolower(name[i]);
        insertNdx = curLetter - 'a';
        curNode = curNode->addChild(insertNdx);
    }
    curNode->setObj(obj);
}

template<class T>
T** Trie<T>::find(string toFind){
    int insertNdx = 0;
    TrieNode<T>* start;
    start = followString(toFind);
    if (start != NULL)
        xplorSubPaths(start, insertNdx);
    foundObjs[insertNdx] = NULL;
    return foundObjs;
}

template<class T>
TrieNode<T>* Trie<T>::followString(string toFollow){
    TrieNode<T>* temp = root;
    int ndx;
    for (int i = 0; i < toFollow.length(); i++){
        ndx = tolower(toFollow[i]) - 'a';
        temp = temp->getChild(ndx);
        if (temp == NULL)
            return temp;
    }
    return temp;
}

template<class T>
void Trie<T>::xplorSubPaths(TrieNode<T>* node, int& insertNdx){
    TrieNode<T>* nextChild;
//    cout << node << endl;
    
    if (node->hasObj()){
        foundObjs[insertNdx] = node->getObj();
        insertNdx += 1;
    }
    
    if (node->hasChildren()){
        // find next child
        // xplore child
        for(int i = 0; i < 26; i++){
            nextChild = node->getChild(i);
            if (nextChild != NULL)
                xplorSubPaths(nextChild, insertNdx);
        }
    }
    
}


