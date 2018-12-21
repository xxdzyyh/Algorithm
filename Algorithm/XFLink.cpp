//
//  XFLink.cpp
//  Algorithm
//
//  Created by xiaoniu on 2018/12/20.
//  Copyright © 2018 com.learn. All rights reserved.
//

#include "XFLink.hpp"

/**
 链表，由指针将若干个节点连接成链状结构。链表是一种动态数据结构，不需要像数组那要预先分配内存，空间效率比数组高。
 最简单的链表就是单节点的。
 
 <code>
    LinkNode *firstNode;
 </code>
 
 */
struct LinkNode {
    int value;
    LinkNode* nextNode;
};

void add(LinkNode **headNode,int value) {
    
    // 创建一个节点
    LinkNode *pNew = new LinkNode();
    
    pNew -> value = value;
    pNew -> nextNode = NULL;
    
    if (*headNode == NULL) {
        // 因为pNew是零时变量,出了作用域就会被释放，如果用headNode = pNew,headNode也会为空
        // 传个指针的指针
        *headNode = pNew;
    } else {
        
        LinkNode *pNode = *headNode;
        
        while (pNode -> nextNode != NULL) {
            pNode = pNode -> nextNode;
        }
        
        pNode -> nextNode = pNew;
    }
    
}

void test() {
    
}
