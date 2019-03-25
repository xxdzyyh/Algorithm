//
//  BubbleSort.cpp
//  Algorithm
//
//  Created by xiaoniu on 2019/3/8.
//  Copyright © 2019 com.learn. All rights reserved.
//

#include "BubbleSort.hpp"

void bubble_sort(int a[],int length) {
    for (int j=length-1; j>0; j--) {
        for (int i=0; i < j; i++) {
            if ( a[i] > a[i+1] ) {
                a[i] = a[i] + a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] = a[i] - a[i+1];
            }
        }
    }
}
