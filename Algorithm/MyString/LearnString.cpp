//
//  LearnString.cpp
//  Algorithm
//
//  Created by xiaoniu on 2019/4/22.
//  Copyright © 2019 com.learn. All rights reserved.
//

#include "LearnString.hpp"
#include <string.h>

void charReverse(char string[]) {
    char* begin = string;
    char* end = begin + strlen(string) - 1;
    
    printf("\n");
    printf("%d\n",sizeof(begin));
    
    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        
        begin++;
        end--;
    }
    
    printf("%s", string);
}
