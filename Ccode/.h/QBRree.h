#include<stdio.h>//二叉树的顺序存储结构
#include<stdlib.h>
#include"SeqStack.h"
#define MaxTreeNodeNum 100

typedef int DataType;

void Visit(int t)
{
   printf("%d",t);
}
typedef struct {
    DataType data[MaxTreeNodeNum];
    int n;
}QBTree;

typedef struct bonde{
    DataType data;
    struct bonde *lchild,*rchild;
}Bonde,*BTree;

void PreOrder (BTree t)//先序遍历的递归算法
{
    if(t)
    {  
        Visit(t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void unPreOrder (BTree t)//先序遍历的非递归算法
{
    PSeqStack S;
    BTree p=t;
    S=Init_SeqStack();
    while(p||!Empty_SeqStack(S))
    {
    if(p)
    {
        Visit(p->data);
        Push_SeqStack(S,p->data);
        p=p->lchild;
    }
    else 
    {
        Pop_SeqStack(S,&p->data);
        p=p->rchild;
    }
    }
}

void InOrder(BTree t)//中序便利店递归的算法
{
    if(t)
    {
        InOrder(t->lchild);
        Visit(t->data);
        InOrder(t->rchild);
    }
}

void unPreOrder (BTree t)//中序遍历的非递归算法
{
    PSeqStack S;
    BTree p=t;
    S=Init_SeqStack();
    while(p||!Empty_SeqStack(S))
    {
    if(p)
    {
        Push_SeqStack(S,p->data);
        p=p->lchild;
    }
    else 
    {
        Pop_SeqStack(S,&p->data);
        Visit(p->data);
        p=p->rchild;
    }
    }
}

void PreOrder (BTree t)//后序遍历的递归算法
{
    if(t)
    {  
        PreOrder(t->lchild);
        PreOrder(t->rchild);
        Visit(t->data);
    }
}

void unPreOrder (BTree t)//后序遍历的非递归算法
{
    PSeqStack S1;
    PSeqStack S2;
    BTree p;
    p=t;
    S1=Init_SeqStack();
    S2=Init_SeqStack();
    while(p||!Empty_SeqStack(S2))
    {
    if(p)
    {
        Push_SeqStack(S1,p->data);
        Push_SeqStack(S2,p->data);
        p=p->lchild;
    }
    else 
    {
        Pop_SeqStack(S2,&p->data);
        p=p->rchild;
    }
    }
    while (!Empty_SeqStack(S1))
    {
        Pop_SeqStack(S1,&p->data);
        Visit(p->data);
    }
}