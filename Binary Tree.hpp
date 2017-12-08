//
//  Binary Tree.hpp
//  BinaryTree
//
//  Created by 孙浩 on 2017/11/23.
//  Copyright © 2017年 孙浩. All rights reserved.
//

#ifndef Binary_Tree_hpp
#define Binary_Tree_hpp

#include "Environment.h"

typedef struct BTNode{
    ElemType data;
    BTNode * left, *right;
}*BT;

struct BTNode* defaultBinaryTree();
struct BTNode* newBTNode(int data) ;

//void printTree(struct BTNode* BTNode);

void mirror(struct BTNode* BTNode);

void DestroyBT(BT BTree);

void layerOrder(BT BTree, int type);
void visit (BT p);
void leavesVisit (BT p);

void build( ElemType A[], BT BTree);

#endif /* Binary_Tree_hpp */
