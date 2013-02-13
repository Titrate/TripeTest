//
//  FileOps.cpp
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/7/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include "FileOps.h"

int TxtFile::readDataToString(string filePath, string **dataAry){
    string* line;
    ifstream file;
    int count = 0;
    
    //Surround in try catch block and send back a meaningful message
    file.open(filePath); 
    if (file.is_open())
        while(!file.eof()) {
            line = new string;
            getline(file, *line);
            dataAry[count] = line;
            count += 1;
        }
    else
        cout << "Error opening file, Make sure full path is included" << endl;
    return count;
}
