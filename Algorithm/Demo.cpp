//
//  Demo.cpp
//  Algorithm
//
//  Created by xiaoniu on 2018/12/20.
//  Copyright © 2018 com.learn. All rights reserved.
//

#include "Demo.hpp"
#include "XFMutableArray.cpp"

void testXFMutableArray() {
    
    XFMutableArray mArray = XFMutableArray(1);
    
    mArray.add(1);
    mArray.log();
    mArray.add(2);
    mArray.log();
    mArray.add(3);
    mArray.log();
    mArray.add(4);
    mArray.log();
    mArray.add(5);
    mArray.log();
    mArray.add(6);
    mArray.log();
    mArray.add(7);
    mArray.log();
    
    mArray.remove(4);
    mArray.log();
    mArray.remove(3);
    mArray.log();
    mArray.remove(2);
    mArray.log();
    mArray.remove(1);
    mArray.log();
    mArray.remove(0);
    mArray.log();
    
}
