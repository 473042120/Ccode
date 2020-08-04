#include<stdio.h>
#include<stdlib.h>
#define MaxTreeNodeNum 100

typedef char DataType;
typedef struct {
    DataType data[MaxTreeNodeNum];
    int n;
}QBTree;

typedef struct bonde{
    DataType data;
    struct bonde *lchild,*rchild;
}Bonde,*BTree;

void Visit(DataType t)
{
   
}

void PreOrder (BTree t)//先序遍历的递归算法
{
    if(t)
    {  
        Visit(t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}