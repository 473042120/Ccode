#include<stdio.h>//栈顺序存储
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int DataType;//顺序栈中存储的数据类型

typedef struct {//顺序站的类型描述
    DataType data[MAXSIZE];
    int top;
}SeqStack, *PSeqStack;

PSeqStack Init_SeqStack(void)
{//初始化空栈
    PSeqStack S;
    S=(PSeqStack)malloc(sizeof(SeqStack));
    if(S)
        S->top=-1;  //栈顶 -1,为了让第一个元素的top是0
    return S;
}

int Empty_SeqStack (PSeqStack S)
{//判栈空
    if(S->top==-1)
        return 1;
    else
        return 0;
}

int Push_SeqStack(PSeqStack S, DataType x)
{//入栈
    if(S->top==MAXSIZE-1)
      return 0;
    else
    {
        S->top++;
        S->data[S->top]=x;
      return 1;
    }
}

int Pop_SeqStack(PSeqStack S, DataType *x)
{//出栈
    if(Empty_SeqStack (S))
    return 0;
    else 
    {
        *x=S->data[S->top];
        S->top--;
        return 1;
    }
}

int GetTop_SeqStack(PSeqStack S, DataType *x)
{//取栈顶元素
    if(Empty_SeqStack(S))
     return 0;
    else
    {
      *x =S->data[S->top];
      return 1;
    }  
}

void Destroy_SeqStack (PSeqStack *S)
{//销毁栈  调用时Destroy_SeqStack（&S）；
  if(*S)
   free(*S);
   *S=NULL;
   return;
}