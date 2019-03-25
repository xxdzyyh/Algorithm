//
//  Complexity.cpp
//  Algorithm
//
//  Created by xiaoniu on 2019/3/11.
//  Copyright © 2019 com.learn. All rights reserved.
//

#include "Complexity.hpp"

int sum(int arr[],int n) { //        执行次数
    int i,total=0;         //           1
    for (i=0; i<n; i++) {  //          n+1
        total += arr[i];   //           n
    }                      //          ------
    return total;          //           1
}                          //          2n+3


#define N 100

void add(int a[N][N],int b[N][N],int c[N][N],int n) {  //      执行次数
    int i,j;                                           //         1
    for (i=0; i<n; i++) {                              //         n+1
        for (j=0; j<n; j++) {                          //         n*(n+1)
            c[i][j]=a[i][j]+b[i][j];                   //         n*n
        }                                              //         --------------
    }                                                  //         2n*n + 2n + 2
}
