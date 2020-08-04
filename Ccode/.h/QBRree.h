#include<stdio.h>
#include<stdlib.h>
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
    if(t)
    {  
        Visit(t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}