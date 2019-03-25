//
//  InsertSort.cpp
//  Algorithm
//
//  Created by xiaoniu on 2019/3/25.
//  Copyright © 2019 com.learn. All rights reserved.
//

#include "InsertSort.hpp"

void insert_sort(int a[],int length) {
    
    /**
     
     0 - 有序 - i - 无序 - length-1
     
     每次从无序区取一个插入到有序曲。
     
     这和日常生活中整理扑克牌很像。
     
     */
    
    for (int i=1; i<length; i++) {
        
        for (int j=0; j<i; j++) {
            
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void shell_sort(int a[],int length) {
    
    int d = length / 2;
    
    while (d>=1) {
        
        // 分层d组
        for (int i=0; i<d; i++) {
            
            for (int j=i+d;j<length;j=j+d) {
                for (int k=i; k<j; k=k+d) {
                    
                    if (a[j] < a[k]) {
                        int temp = a[j];
                        a[j] = a[k];
                        a[k] = temp;
                    }
                }
            }
        }
        
        d = d/2;
    }
    
}
