#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100

typedef struct node{
    int data[MAXSIZE];
    int length;
}SeqList,*PSeqList;

PSeqList Init_SeqList(viod)
{
    PSeqList PL;
    PL=(PSeqList)malloc(sizeof(SeqList));
    if(PL)
      PL->length=0;
    return (PL);
}

//求顺序表的长度

int Length_SeqList(PSeqList L)
{
    return (L->length);
}

//顺序表达检索操作

int Location_SeqList(PSeqList L,int x)//x视情况而定
{
    int i=0;
    while(i<L->length && L->data[i]!=x)
      i++;
    if(i>=L->length)  return  (0);
    else  return (i+1);    
}

//顺序表的插入运算

int Insert_SeqList(PSeqList PL,int i,int x)//视情况而定
{
    int j;
    if(!PL)
    {
        printf("表不存在");
        return(-2);
    }
    if(PL->length>=MAXSIZE)
    {
        printf("表溢出");
        return(-1);
    }
    if(i<1||i>PL->length+1)
    {
        printf("插入位置不合法");
        return (0);
    }
    for(j=PL->length-1;j>=i-1;j--)
    {
        PL->data[j+1]=PL->data[j];
        PL->data[i-1]=x;
        PL->length++;
    }
    return (1);
}

//顺序表的删除运算

int Delete_SeqList(PSeqList PL,int i)
{
    int j;
    if(!PL)
    {
        printf("表不存在");
        return(-1);
    }
    if(i<1 || i>PL->length)
    {
        printf("删除位置不合法");
        return(0);
    }
    for(j=i;j<PL->length;j++)
      PL->data[j-1]=PL->data[j];
      PL->length--;
      return(1);    
}

