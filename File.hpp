//
//  File.hpp
//  Assignment_1
//
//  Created by 孙浩 on 2017/12/1.
//  Copyright © 2017年 孙浩. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include <fstream>
#include "Environment.h"

typedef struct node{
    ElemType data;
    struct node *link;
}LNode, *LinkList;

int WriteFile(fstream & destFile);
int* ReadFile(fstream & destFile, int Get_Max, int NewArray[]);

void PrintArray(int Array[]);
void DeleteArray(int NewArray[], int SortedArray[]);

LinkList Creat (int n,int Array[]);
void InsertSort(LinkList & list,int n, int m);
void DELETELINK(LinkList &list);
void PrintList(LinkList list);

#endif /* File_hpp */
