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
#include "MyString/LearnString.hpp"
#include "Dynamic/DisSubArray.hpp"
#include "Tree.hpp"

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
//    //
//    int number[8] = {8,7,6,5,4,3,2,1};
//    
////    bubble_sort(number, 8);
//    
////    twoSum(number, 8, 15);
//    
//    shell_sort(number, 8);
//    
//    my_qsort(number, 0, 7);
//    
//    for (int i=0; i<8; i++) {
//        printf("%d\n",number[i]);
//    }
//    
//    char s[30] = "asdf,qwer";
//    
//    charReverse(s);
//    
//    int number2[8] = {389, 207, 155, 300, 299, 170, 158, 65};
//    int count[8] = {};
//    
//    maxDis(8, count, number2);
//    maxQueue(number2, 8);
//    findBoom();
    
    
    BinaryTreeNode *node = new BinaryTreeNode();
    
    node->m_nValue = 1;
    BinaryTreeNode *s1node = new BinaryTreeNode();
    s1node->m_nValue = 2;
    BinaryTreeNode *s2node = new BinaryTreeNode();
    s2node->m_nValue = 3;
    
    node->m_pLeft = s1node;
    node->m_pRight = s2node;
    
    reverseNode(node);
    
    printf("%d",node->m_nValue);
    printf("%d",node->m_pLeft->m_nValue);
    printf("%d",node->m_pRight->m_nValue);
    
    return 0;
}
