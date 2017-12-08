//
//  main.cpp
//  Assignment_1
//
//  Created by 孙浩 on 2017/11/30.
//  Copyright © 2017年 孙浩. All rights reserved.
//

#include <iostream>
#include "File.hpp"
#include "Binary Tree.hpp"
#define Process_Num 400

int Possession_1(){
    fstream destFile;
    int b = WriteFile(destFile);
    cout <<endl;
    
    ElemType NewArray[Max];
    int *a = ReadFile(destFile,Process_Num ,NewArray);
    
    if (!(a && b))
        return 0;
    
    PrintArray(a);
    DeleteArray(NewArray, a);
    
    LinkList List = Creat (Process_Num, NewArray);
    InsertSort(List, 0, Process_Num -1 );
    PrintList(List);
    DELETELINK(List);
    return 0;
};

void Possession_2(){
    struct BTNode *BTree = defaultBinaryTree();
    layerOrder(BTree,1);
    layerOrder(BTree,0);
    mirror(BTree);
    DestroyBT(BTree);
};
int main(){
    cout << Possession_1()<<endl;
    Possession_2();
}

