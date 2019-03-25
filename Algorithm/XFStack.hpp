//
//  XFStack.hpp
//  Algorithm
//
//  Created by xiaoniu on 2018/12/25.
//  Copyright © 2018 com.learn. All rights reserved.
//

#ifndef XFStack_hpp
#define XFStack_hpp

#include <stdio.h>

template <typename T>
void push(T *obj) {
            
}

template <class T>
class XFStack {

    int length = 0;
    int use = 0;
    T data[100];
     
public:
    void push(T obj) {
         data[use+1] = obj;
    }
    
    void pop(T obj) {
        for (int i=0; i<use; i++) {
            T t = data[i];
            
            if (t == obj) {
                
            }
        }
    }
    
};

#endif /* XFStack_hpp */
