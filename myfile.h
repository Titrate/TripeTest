//
//  FileOps.h
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/7/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __DansTemplates__FileOps__
#define __DansTemplates__FileOps__

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class MyFile {
    FILE file;
    string** dataAry;   // Stores loaded data
    int count;          // counts loaded data
    
public:
    MyFile(){
        count = 0;
    }
    ~MyFile(){
        for (int i = 0; i < count; i++)
            delete dataAry[i];
    }
    int readDataToString(string fileName, string** dataAry);
    void writeDataToFile(string fileName, string** dataRecord);
};

#endif /* defined(__DansTemplates__FileOps__) */

