//
//  TripeNode.h
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/8/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __DansTemplates__TripeNode__
#define __DansTemplates__TripeNode__

#include <iostream>

using namespace std;

class StudentNode {
    int score;
    string name;
public:
    StudentNode(string name = "NONAME", int score=0){
        this->name = name;
        this->score = score;
    }
    
    string getName(){return name;}
    void setName(string name){this->name = name;}
    
    int getScore(){return score;}
    void setScore(int score){this->score = score;}
    int compare(StudentNode* isBigger){return (this->score - isBigger->score);}
};

#endif /* defined(__DansTemplates__TripeNode__) */


