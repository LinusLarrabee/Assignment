//
//  Binary Tree.cpp
//  BinaryTree
//
//  Created by 孙浩 on 2017/11/23.
//  Copyright © 2017年 孙浩. All rights reserved.
//

#include "Binary Tree.hpp"

BT defaultBinaryTree(){
    BT root = newBTNode(15);
    root->left = newBTNode(98);
    root->left ->left = newBTNode(20);
    root->left ->right = newBTNode(10);
    root->left ->left -> left =newBTNode(30);
    root->left ->left -> right =newBTNode(40);
    
    root->right = newBTNode(6);
    root->right ->left =newBTNode(45);
    root->right ->left -> right =newBTNode(60);
    root->right ->left -> right ->left =newBTNode(70);
    return(root);
}


BT newBTNode(int data) {
    BT BTNode = new(struct BTNode);    // "new" is like "malloc"
    BTNode->data = data;
    BTNode->left = NULL;
    BTNode->right = NULL;
    
    return(BTNode);
}

void printTree(BT BTNode) {
    if (BTNode == NULL)
        return;
    printTree(BTNode->left);
    printf("%d ", BTNode->data);
    printTree(BTNode->right);
}


void mirror(BT BTNode) {
    if (BTNode==NULL) {
        return;
    }
    else {
        BT temp;
        
        // do the subtrees
        mirror(BTNode->left);
        mirror(BTNode->right);
        
        // swap the pointers in this BTNode
        temp = BTNode->left;
        BTNode->left = BTNode->right;
        BTNode->right = temp;
    }
}


void DestroyBT(BT BTree){
    if(BTree != NULL){
        DestroyBT(BTree-> left);
        DestroyBT(BTree-> right);
        free(BTree);
    }
    BTree =NULL;
}

void visit (BT p){
    cout << p-> data << endl;
}

void leavesVisit (BT p){
    if(p->left == NULL && p-> right == NULL)
        cout<< p -> data <<endl;
}

//void build( ElemType A[], BT BTree){
//    for (int i = 0; i< 100; i++){
//        if (A[i] == 0)
//        {
//            BTree = NULL;
//        }
//        else
//        {
//            if (!(BTree = newBTNode(A[i])))
//                return;
//            build(&A[i],BTree->left);    //构造左子树
//            build(&A[i],BTree->right);    //构造右子树
//        }
//    }
//}

void layerOrder(BT BTree,int type){
    BT Queue[Max/10], p;
    int front, rear;
    if( BTree != NULL){
        Queue[0] = BTree;
        front = -1;
        rear = 0;
        while (front < rear){
            p = Queue[++front];
            switch (type) {
                case 0:
                    visit(p);
                    break;
                case 1:
                    leavesVisit(p);
                    break;
                default:
                    break;
            }
            if( p->left != NULL)
                Queue[++rear] = p->left;
            if( p->right != NULL)
                Queue[++rear] = p->right;
        }
    }
}

