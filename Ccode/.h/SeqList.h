#include <stdio.h> //顺序表 线性表的顺序存储结构
#include <malloc.h>
#define MAXSIZE 100

typedef int DataType;//顺序表中存储的数据类型

typedef struct node{
    DataType data[MAXSIZE];
    int length;  //表长
}SeqList,*PSeqList;//*PSeqlist为地址指针方便以后址传递

//顺序链表初始化

PSeqList Init_SeqList()
{
    PSeqList PL;
    PL=(PSeqList)malloc(sizeof(SeqList));
    /*因为声明时没赋值所以初始化时要自己申请空间*/
    if(PL)  //PL==NULL证明申请空间失败，空地址
      PL->length=0;
    return (PL);
}

//求顺序表的长度

int Length_SeqList(PSeqList L)
{   //求顺序表的长度，入口参数：顺序表地址，返回表长
    return (L->length);
}

//顺序表达检索操作

int Location_SeqList(PSeqList L,DataType x)
{//入口：顺序表，检索元素  返回元素位置或者查找失败0
    int i=0;
    while(i<L->length && L->data[i]!=x)
      i++;
    if(i>=L->length)  return  (0);
    else  return (i+1);    
}

//顺序表的插入运算

int Insert_SeqList(PSeqList PL,int i,int x)//视情况而定
{//在顺序表的第i个元素之前插入x，入口:顺序表指针，插入位置，插入元素
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
        printf("插入成功");
    return (1);
}

//顺序表的删除运算

int Delete_SeqList(PSeqList PL,int i)
{/*入口：顺序表指针，删除元素位置，
   返回：1成功,0删除位置不合法,-1表示表不存在*/
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
