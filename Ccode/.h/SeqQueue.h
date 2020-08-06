#include<stdio.h>  //队列的顺序存储
#include<malloc.h>
#define MAXSIZE 100

typedef int DataType;

typedef struct {
    DataType data[MAXSIZE];//存储数据
    int front,rear;
}SeqQueue,*PSeqQueue;

//Q->data[0]-Q->data[MAXSIZE -1]
//对头指针：Q->front(0<=Q->front<=MAXSIZE -1)
//队尾指针：Q->rear(0<=Q->rear<=MAXSIZE -1)
//Q->rear=(Q->rear+1)%MAXSIZE;
//Q->front=(Q->front+1)%MAXSIEZ; 头尾连接的循环结构

//队列初始化
PSeqQueue Init_SeqQueue()
{
   PSeqQueue Q;
   Q=(PSeqQueue)malloc(sizeof(SeqQueue));
   if(Q)
   {
       Q->front=0;
       Q->rear=0;
   }
   return Q;
}

//判队空操作
int Empty_SeqQueue (PSeqQueue Q)
{
   if(Q&&Q->front==Q->rear)
   return 1;
   else 
   return 0;
}

//入队
int In_SeqQueue(PSeqQueue Q,DataType x)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
    {
        printf("堆满");
        return -1;
    }
    else
    {
        Q->rear=(Q->rear+1)%MAXSIZE;
        Q->data[Q->rear]=x;
        return 1; 
    }
}

//出队
int Out_SeqQueue (PSeqQueue Q,DataType *x)
{
    if(Empty_SeqQueue(Q))
    {
        printf("队空");
        return -1;
    }
    else
    {
        Q->front=(Q->front+1)%MAXSIZE;
        *x=Q->data[Q->front];
        return 1;
    }
    
}
//读队头元素

int Front_SeqQueue(PSeqQueue Q,DataType *x)
{
    if(Q->front==Q->rear)
    {
        printf("队空");
        return -1;
    }
    else
    {
        *x=Q->data[(Q->front+1)%MAXSIZE];
        return 1;
    }
}

//销毁队列

void Destroy_SeqQueue(PSeqQueue *Q)
{//调用时Destroy_SeqQueue（&Q）；
    if(*Q)
      free(*Q);
      *Q =NULL;
}