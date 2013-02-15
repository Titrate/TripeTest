//
//  HeapTree.h
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/3/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __DansTemplates__HeapTree__
#define __DansTemplates__HeapTree__

#include <iostream>

const int ARYSIZE = 50000;
const int ROOT = 1;

using namespace std;

/*
 * This class is a teplate for a heap. It can be used to do a heap sort or just
 * store the kind of data you want to store in a heap.
 */

template <class T>
class Heap {
    
    void** heapAry_pp;      // This is a memory segment for data storage
    int maxArySize;         // This tells us how much memory we can hold
    int size;               // This is the actively monitored heap memory
    bool min;               // This tells us the order of our storage
    
public:
    
    // Make a heap with a data set, good for sorting
    Heap<T>(T dataAry[]=NULL, int size = 0){
        this->size = size;                              // Set inital size
        int* temp_p = new int;                          // to load slot zero of array
        *temp_p = size;
        if (ARYSIZE > 2*size){
            heapAry_pp = new void *[ARYSIZE];
            maxArySize = ARYSIZE;
        }else{
            heapAry_pp = new void *[2*size];            // Memory allocation
            maxArySize = 2*size;
        }
        heapAry_pp[0] = (int*)temp_p;                   // Store count of total allocated memory in first cell
        handleData(dataAry);
    }
    
    // Standard deconstructor for removing stuff from the heap
    ~Heap<T>(){
        if (size > 0){
            for (int i = 1; i <  *(int*)heapAry_pp[0]; i++)
                delete (T*) heapAry_pp[i];
            delete (int*) heapAry_pp[0];
        }
    }
    
    T* insert(T item);                // Insert item into memory
    void insert(T* item);
    T* deleteMin();                     // Remove head item
    T* getMin(){return (T*) heapAry_pp[ROOT];}
    int empty(){
        if (size > 0)
            return 0;
        else
            return 1;
    }
    
private:
    void handleData(T* data);           // This handles the data array passed in from the user
    void heapify();                     // This is called by handledata
    void percolateDown(int ndx);        // This will push a node down in the heap
    void percolateUp(int ndx);          // Like donw, the just oposite direction
    void swap(int ndx1, int ndx2);      // Swap two pointers
    int checkChildren(int ndx);         // Return ndx of smallest node in group
    void resize();                      // Resize if we grow too big.

};

#endif /* defined(__DansTemplates__HeapTree__) */



template<class T>
void Heap<T>::resize(){
    maxArySize *= 2;                                // Set new max size
    void** tempAry_pp = new void*[maxArySize];      // Allocate space for new larger array
    for (int i = 0; i <= size; i++){
        tempAry_pp[i] = (T*)heapAry_pp[i];          // Copy pointers
    }
    delete heapAry_pp;                              // Free memory from old array (not the elements
    heapAry_pp = tempAry_pp;                        // Set heapary to new ary
}

template<class T>
T* Heap<T>::insert(T item){
    T* temp_p;
    if (size == maxArySize){                 // We need to allocate memory for storage
        resize();
    }
    if (size >= *(int*)heapAry_pp[0]){      // We need to allocate memroy for a new object
        temp_p = new T;
        heapAry_pp[size + 1] = (T*) temp_p;
        *(int*)heapAry_pp[0] += 1;
    }else{                                  // Use already allocated memory
        temp_p = (T*)heapAry_pp[size + 1];
    }
    *temp_p = item;
    size += 1;
    percolateUp(size);
    return temp_p;
}

/*
 * Technically I should handle the eventuallity of overflowing my size
 * This method is just kinda worthless though. I need to add a lot to handle
 * this. I cannot free memory I did not create yet if I use this my code tries
 * to free memory it cannot.
 */
//template<class T>
//void Heap<T>::insert(T* item){
//    heapAry_pp[size + 1] = item;
//    size += 1;                      // update size
//    *(int*)heapAry_pp[0] += 1;      // update size of managed memory
//}

template<class T>
void Heap<T>::percolateUp(int ndx){
    while (ndx/2 > 0){
        if ((*(T*)heapAry_pp[ndx]).compare((T*)heapAry_pp[ndx/2]) < 0){
            swap(ndx, ndx/2);
            ndx /= 2;
        }else
            ndx = 0;
    }
}

template<>
inline void Heap<int>::percolateUp(int ndx){
    while (ndx/2 > 0){                                          // While we have a parent node
        if (*(int*)heapAry_pp[ndx] < *(int*)heapAry_pp[ndx/2]){     // If parent is smaller than ndx
            swap(ndx, ndx/2);                                   // Swap
            ndx /= 2;                                           // Send back next ndx to check
        }else
            ndx = 0;                                            //end loop
    }
}

template<class T>
T* Heap<T>::deleteMin(){
    if (size > 0){
        T* temp_p = (T*)heapAry_pp[ROOT];       // Keep reference to "deleted" node
        swap(ROOT, size);                       // Swap first and last elements
        size -= 1;                              // Reduce size to match
        percolateDown(ROOT);                    // Push new root down to its right position
        return temp_p;
    }
    return NULL;
}

template<class T>
void Heap<T>::handleData(T* data_p){
    T* temp_p;                                  // Temp node for insert into array
    for (int i = 1; i <= size; i++){
        temp_p = new T;                         // Grab heap space
        *temp_p = data_p[i - 1];                // Put data into new memory loc
        heapAry_pp[i] = (T*) temp_p;            // Put memory reference in memory array
    }
    heapify();                                  // Fix heap invariant
}

template<class T>
void Heap<T>::heapify(){                        // Start at lowest level parent and work backwards
    for (int i = size/2; i > 0; i--)
        percolateDown(i);                       // Push parent down
}

template<class T>
void Heap<T>::percolateDown(int ndx){
    while (ndx * 2 <= size){                    // While we have children
        ndx = checkChildren(ndx);               // Get new ndx to check
    }
}

template<class T>
int Heap<T>::checkChildren(int ndx){
    if (ndx*2 == size){ // See the int version for info
        if (((T*)heapAry_pp[ndx])->compare((T*)heapAry_pp[ndx*2])>0){
            swap(ndx, ndx*2);
            return (ndx*2);
        }
    } else if (((T*)heapAry_pp[ndx*2])->compare((T*)heapAry_pp[ndx*2+1])<0){
        if (((T*)heapAry_pp[ndx])->compare((T*)heapAry_pp[ndx*2])>1){
            swap(ndx, ndx*2);
            return (ndx*2);
        }
    } else {
        if (((T*)heapAry_pp[ndx])->compare((T*)heapAry_pp[ndx*2+1]) > 0){
            swap(ndx, ndx*2+1);
            return (ndx*2+1);
        }
    }
    return size;
}

template<>
inline int Heap<int>::checkChildren(int ndx){
    if (ndx*2 == size){                                             // Parent has one child
        if (*(int*)heapAry_pp[ndx] > *(int*)heapAry_pp[ndx*2]){         // Parent smaller than child
            swap(ndx, ndx*2);                                       // Swap
            return (ndx*2);                                         // Send back next ndx to check
        }
    } else if (*(int*)heapAry_pp[ndx*2] < *(int*)heapAry_pp[ndx*2+1]){  // Left child is smaller
        if (*(int*)heapAry_pp[ndx] > *(int*)heapAry_pp[ndx*2]){         // Check parent vs smaller child
            swap(ndx, ndx*2);                                       // Swap
            return (ndx*2);                                         // Send back new ndx to check
        }
    } else {                                                        // Right child is smaller, same steps as above
        if (*(int*)heapAry_pp[ndx] > *(int*)heapAry_pp[ndx*2+1]){
            swap(ndx, ndx*2+1);
            return (ndx*2+1);
        }
    }
    return size;                                                    // Kill percolate loop
}

template<class T>
void Heap<T>::swap(int ndx1, int ndx2){
    T* temp_p = (T*)heapAry_pp[ndx1];
    heapAry_pp[ndx1] = (T*) heapAry_pp[ndx2];
    heapAry_pp[ndx2] = (T*) temp_p;
}
