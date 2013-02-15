//
//  TripeNode.cpp
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/8/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include "StudentNode.h"

int StudentNode::compare(StudentNode* isBigger){
//    cout << this->score - isBigger->score << endl;
    return (this->score - isBigger->score);
}

