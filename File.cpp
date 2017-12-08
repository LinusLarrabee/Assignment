//
//  File.cpp
//  Assignment_1
//
//  Created by 孙浩 on 2017/12/1.
//  Copyright © 2017年 孙浩. All rights reserved.
//

#include "File.hpp"
int x,total = 0;
int Used_Max = Max;
ElemType SortedArray[Max];
ElemType Array[1+Max];
char str[64];

int WriteFile(fstream & destFile){
    //write file
    destFile.open("txtfile.txt", ios::out);
    if(!destFile){
        cout << "1.open file error!" << endl;
        return 0;
    }
    
    srand(int (time(NULL)));
    for (int i=0; i <= Max; i++){
        Array[i] =rand()%1000;
        destFile<<Array[i]<<"\t";
    }
    destFile.close();
    return 1;
}

int* ReadFile(fstream & destFile, int Get_Max, int NewArray[]){
    //read file
    Used_Max = Get_Max;
    destFile.open("txtfile.txt", ios::in);
    if(!destFile){
        cout << "2.open file error!" << endl;
        return 0;
    }
    
    
    while (destFile >> x && total < Get_Max)
        NewArray[total++] = x;
    destFile.close();
    

    int n, m, temp;
    total = 0;
    destFile.open("txtfile.txt", ios::in);
    for (m = 0; m <= Get_Max-1; m++){
        if(!destFile){
            cout << "2.open file error!" << endl;
            return 0;
        }
        destFile >> x;
        SortedArray[total++] = x;
        
        for (n = m-1; n >= 0 ; n--){
            if( SortedArray[n] > SortedArray[n+1] && SortedArray[n+1]){
                temp = SortedArray[n+1];
                SortedArray[n+1] = SortedArray[n];
                SortedArray[n] = temp;
            }
        }
    }
    return SortedArray;
}

void PrintArray(int Array[]){
    for (int i=0; i <= Used_Max-1; i++){
        cout << Array[i] <<"\t";
    }
    cout << endl;
}

void DeleteArray(int NewArray[], int SortedArray[]){
    for(int i = 0; i < Used_Max; i++){
        for (int j = 0; j < Used_Max; j++){
            if(SortedArray[j] == NewArray[i])
                SortedArray[j] = 0;
        }
    }
}

LinkList Creat (int n, ElemType * Array){
    LinkList p ,r = nullptr,list = NULL;
    ElemType a;
    int i;
    for(i = 0; i < n; i++){
        a = Array[i];
        p = (LinkList) malloc (sizeof(LNode));
        p ->data = a;
        p ->link = NULL;
        if(list == NULL)
            list = p;
        else
            r -> link = p;
        r = p;
    }
    return list;
}


void InsertSort(LinkList & list,int n, int m){
    LinkList p, q, temp;
    int point;
    q =list;
    for(int i =0; i< n && q->link; q = q->link, i++);
    for(int i = n; i <= m; i++){
        p =q;
        temp = q;
        for (int j = i ; j <= m ;j++ ){
            if( p->data < temp->data)
                temp= p;
            p = p->link;
        }
        point  = temp->data;
        temp->data = q ->data;
        q->data = point;
        q = q->link;
    }
}

void DELETELINK(LinkList &list){
    LinkList q = list;
    while (q !=NULL){
        list = q-> link;
        free (q);
        q = list ;
    }
}

void PrintList(LinkList list){
    LinkList p = list;
    while (p != NULL){
        cout<< p->data<<"\t";
        p = p->link;
    }
    cout << endl;
}
