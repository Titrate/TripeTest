//
//  TripeNode.cpp
//  DansTemplates
//
//  Created by Daniel Guimaraes on 2/8/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include "StudentNode.h"

int StudentNode::compare(StudentNode isBigger){
    if (this->score > isBigger.score)
        return 1;
    if (this->score < isBigger.score)
        return -1;
    return 0;
}
