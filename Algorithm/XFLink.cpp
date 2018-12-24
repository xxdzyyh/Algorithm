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
    
    ~LinkNode() {
        printf("~LinkNode\n");
    }
};


void log(LinkNode *link) {
    if (link == NULL) {
        return;
    }
    printf("%d,",link -> value);
    while (link -> nextNode) {
        printf("%d,",link -> nextNode -> value);
        link = link -> nextNode;
    }
    printf("\n");
}

void errorAdd(LinkNode* headNode,int value) {
    
    // 创建一个节点
    // pNeW分配在栈上面，LinkNode实例在堆上面
    LinkNode *pNew = new LinkNode();
    
    pNew -> value = value;
    pNew -> nextNode = NULL;
    
    // 如果headNode = NULL需要重新赋
    if (headNode == NULL) {
        // 修改形参的值不会影响到实参
        /**
            temp         first  head pNew   head
            
            LinkNode      a1    a1    a4      a4
            
            a1            a2    a3    a5      a2
         */
        // 虽然这里设置了，但是外界的first还是NULL
        headNode = pNew;
        
        log(headNode);
        
    } else {
        LinkNode *pNode = headNode;
        
        while (pNode -> nextNode != NULL) {
            pNode = pNode -> nextNode;
        }
        
        pNode -> nextNode = pNew;
    }
}

void add(LinkNode **headNode,int value) {
    
    // 创建一个节点
    // pNeW分配在栈上面，LinkNode实例在堆上面
    LinkNode *pNew = new LinkNode();
    
    pNew -> value = value;
    pNew -> nextNode = NULL;
    
    if (*headNode == NULL) {
        /**
         temp         first  head pNew    first
         
         LinkNode      a1    a2    a4      a4
         
         a1            a2    a3    a5      a2
         */
        *headNode = pNew;
        
        log(*headNode);
    } else {
        
        LinkNode *pNode = *headNode;
        
        while (pNode -> nextNode != NULL) {
            pNode = pNode -> nextNode;
        }
        
        pNode -> nextNode = pNew;
    }
}



void testLink() {
    
//    LinkNode *first = new LinkNode();
 
//    first -> value = 1;
    
    LinkNode *first = NULL;
    
    log(first);
    
    add(&first, 2);
    
    log(first);
}
