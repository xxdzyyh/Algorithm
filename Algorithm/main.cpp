//
//  main.cpp
//  Algorithm
//
//  Created by xiaoniu on 2018/12/20.
//  Copyright © 2018 com.learn. All rights reserved.
//

#include <iostream>
#include "Demo.hpp"
#include "XFPoint.hpp"
#include "XFLink.hpp"
#include "StringReplace.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "InsertSort.hpp"

int main(int argc, const char * argv[]) {

//    testXFMutableArray();
//    testPoint4();
//    testSwap();
//    testLink();

//    char string[100] = "we are happy";
//    
//    replace(string, 100);
//    
//    printf("%s\n",string);

    //
    int number[8] = {8,7,6,5,4,3,2,1};
    
//    bubble_sort(number, 8);
    
//    twoSum(number, 8, 15);
    
    shell_sort(number, 8);
    
    my_qsort(number, 0, 7);
    
    for (int i=0; i<8; i++) {
        printf("%d\n",number[i]);
    }
    
    return 0;
}
