//
//  main.cpp
//  DataStructure
//
//  Created by amirx on 2020/3/27.
//  Copyright © 2020 amirx. All rights reserved.
//

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct LNode {
    ElemType data;          // 数据域
    struct LNode *next;     // 指针域
}LNode, *LinkList;          // *LinkList 为 LNoded 的指针n类型

LinkList p;

// 初始化，构造一个空表
Status InitList_L(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    return OK;
}

int main() {
    LinkList L = new LNode;
    InitList_L(LinkList &L);
    
    return 0;
}


// 查找，根据 i 获取指定位置的数据元素的内容
Status GetElem_L(LinkList L, int i, ElemType &e) {
    p = L->next;
    int j = 1;      // 初始化
    while (p && j < i) {   // 向后扫描，直到 p 指向第 i 个元素或 p 为空
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    e = p->data;
    return OK;
}

// 插入，插在第 i 个节点之前
Status ListInsert(LinkList &L, int i, ElemType e) {
    p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if(!p || j > i - 1) {    // i 大于表长 ➕1 或者小于 1
        return ERROR;
    }
    LNode *s = new LNode;   // 生成新的节点 s
    s->data = e;            // 将 e 存入节点 s 的数据域
    s->next = p->next;      // 将节点 s 插入 L 中
    p->next = s;
    return OK;
}

// 将线性表 L 中第 i 个元素删除
Status ListDelete_L (LinkList &L, int i, ElemType &e) {
    p = L;
    int j = 0;
    while (p->next && j < i - 1) {  // 寻找第 i 个节点，并令 p 指向其前驱
        p = p->next;
        ++j;
    }
    if (!(p->next) && j > i - 1) {
        return ERROR;
    }
    LNode *q = new LNode;
    q = p->next;        // 临时保存被删节点的地址
    p->next=q->next;
    e = q->data;
    delete q;           // 释放删除节点的空间
    return OK;
}
