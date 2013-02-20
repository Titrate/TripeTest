//
//  TrieNode.h
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/8/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __DansTemplates__TrieNode__
#define __DansTemplates__TrieNode__

#include <iostream>

const int NUMCHILDREN = 26; // Number of letters in the alphabet.

template<class T>
class TrieNode {
    TrieNode<T>** children_pp;            // All the children
    int weight;         // A count of all the nodes beneath this one
    T* obj_p;          // Last node in tri points to an obj
    bool hasObjPtr;
    
public:
    TrieNode(T* obj_p = NULL){
        weight = 0;
        this->obj_p = obj_p;
        if (obj_p != NULL)
            hasObjPtr = true;
        else
            hasObjPtr = false;
        initChildren();
    }
    
    void incrementWeight(){this->weight += 1;}
    void decrementWeight(){this->weight -= 1;}
    
    T* getObj(){return this->obj_p;}
    
    bool hasObj(){return this->hasObjPtr;}
    
    TrieNode<T>* getChild(int ndx){return children_pp[ndx];}
    TrieNode<T>* addChild(int ndx);
    
    void setObj(T* obj){
        obj_p = obj;
        hasObjPtr = true;
    }

    void deleteObj(){
        hasObjPtr = false;
    }
    
    bool hasChildren(){
        return (weight > 0);
    }
    
private:
    void initChildren();
};
#endif /* defined(__DansTemplates__TrieNode__) */


/*
 * This method will create a new child node and fill it with the specified letter
 *
 * @return: Send back the newly created child
 */
template<class T>
TrieNode<T>* TrieNode<T>::addChild(int ndx){
    if (children_pp[ndx] == NULL)
//        std::cout << "You are here correctly" << std::endl;
        children_pp[ndx] = new TrieNode;
    weight += 1;
    return children_pp[ndx];
}

/*
 * This gets called when a child is added to this node. The list accomadates
 * 26 children. Children not in use get set to NULL
 */
template<class T>
void TrieNode<T>::initChildren(){
    children_pp = new TrieNode *[NUMCHILDREN];
    for (int i = 0; i < NUMCHILDREN; i++){
        children_pp[i] = NULL;
//        std::cout << children_pp[i] << std::endl;
    }
}



