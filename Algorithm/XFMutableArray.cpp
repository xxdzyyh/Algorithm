//
//  XFMutableArray.cpp
//  Algorithm
//
//  Created by xiaoniu on 2018/12/20.
//  Copyright © 2018 com.learn. All rights reserved.
//
#include "stdio.h"

class XFMutableArray {
    
    // 数组总长度
    int length = 0;
    // 数组已经使用的长度
    int use = 0;
    
    // 不可变数组指针
    int* mArray;
    
public:
    
    XFMutableArray(int cap) {
        if (cap < 4) {
            cap = 4;
        }
        
        length = cap;
        mArray = new int[cap];
    };
    
    
    void grow() {
        int l = length + (length>>1);
        int* growArray = new int[l];
        
        for (int i=0; i<use; i++) {
            growArray[i] = mArray[i];
        }
        
        delete [] mArray;
        
        length = l;
        mArray = growArray;
    }
    
    void add(int i) {
        
        if (use+1 < length) {
            // 直接添加
            mArray[use] = i;
            use++;
        } else if (use+1 == length) {
            // 空间已被用完
            grow();
            add(i);
        }
    }
    
    void remove(int index) {
        if (index == use -1) {
            // 无需移动
            mArray[index] = 0;
            use--;
        } else {
            for (int i=index; i<use; i++) {
                // 往前移动
                mArray[i] = mArray[i+1];
            }
            use--;
        }
        
        if (use <= length/4) {
            // 保留1/2的空间，这样可以继续添加元素
            narrow();
        }
    }
    
    void narrow() {
        int l = length/2;
        int *narrowArray = new int[l];
        for (int i=0; i<use; i++) {
            narrowArray[i] = mArray[i];
        }
        
        delete [] mArray;
        length = l;
        mArray = narrowArray;
    }
    
    void log() {
        for (int i=0; i<use; i++) {
            printf("%d,",mArray[i]);
        }
        printf("use=%d length=%d \n",use,length);
    }
};

