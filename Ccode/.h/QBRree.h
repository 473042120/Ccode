#include<stdio.h>
#include<stdlib.h>
#define MaxTreeNodeNum 100

typedef char DataType;
void Visit(char t)
{
   printf("%c",t);
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