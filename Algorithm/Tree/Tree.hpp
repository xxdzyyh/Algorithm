//
//  Tree.hpp
//  Algorithm
//
//  Created by xiaoniu on 2019/4/9.
//  Copyright © 2019 com.learn. All rights reserved.
//
/**
          10
 
        6         14

      4    8   12    16
 
 前、中、后序遍历是针对根节点来说的。
 
 前序遍历：先访问根节点，再访问左子节点，最后访问右子节点。 10，6，4，8，14，12，16
 中序遍历：先访问左子节点，再访问根节点，最后访问右子节点。 4，6，8，10，12，14，16
 后序遍历：先访问左子节点，再访问右子节点，最后访问根节点。 4，8，6，12，16，14，10 
 
 宽度优先遍历：先访问树的第一层节点，再访问树的第二层节点...一直到访问最下面一层节点。在同一层节点中，以从左到右的顺序依次访问。y
 
 iOS中树结构也是普遍存在的，比如 视图树,所以说不要没有用过树。

 */


#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void reverseNode(BinaryTreeNode *originNode);

#endif /* Tree_hpp */
