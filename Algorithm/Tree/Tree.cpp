//
//  Tree.cpp
//  Algorithm
//
//  Created by xiaoniu on 2019/4/9.
//  Copyright © 2019 com.learn. All rights reserved.
//

#include "Tree.hpp"


struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//BinaryTreeNode *rebuildTree(int* preorder,int* inorder,int length) {
//    
//    if (preorder == nullptr || inorder == nullptr || length <= 0) {
//        return nullptr;
//    }
//    
//    
//}

BinaryTreeNode *rebuildCore(int* startPreoder,int *endPreorder,int* startInorder,int* endInorder) {
        
    int rootValue = startPreoder[0];
    
    BinaryTreeNode *root = new BinaryTreeNode();
    
    root -> m_nValue = rootValue;
    root -> m_pLeft = root -> m_pRight = nullptr;
    
    if (startPreoder == endPreorder) {
        if (startInorder == endInorder && *startPreoder == *startInorder) {
            return root;
        } else {
            // invalid input
            return nullptr;
        }
    }
    
    int *rootInorder = startInorder;
    
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }
    
    int leftLength = (int)(rootInorder - startInorder);
    int* leftPredoerEnd = startPreoder+leftLength;
    
    if (leftLength >0) {
        root -> m_pLeft = rebuildCore(startPreoder+1, leftPredoerEnd, startInorder, rootInorder-1);
    }
    
    if (leftLength < endPreorder-startPreoder) {
        root -> m_pRight = rebuildCore(leftPredoerEnd+1, endPreorder, rootInorder+1, endInorder);
    }
    
    return nullptr;
}
