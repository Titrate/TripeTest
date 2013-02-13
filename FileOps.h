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

class TxtFile {
    FILE file;
public:
    int readDataToString(string fileName, string** dataAry);
    void writeDataToFile(string fileName, string** dataRecord);
};

#endif /* defined(__DansTemplates__FileOps__) */

