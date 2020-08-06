#include <stdio.h>  //队列链式存储
#include <malloc.h>

typedef int DataType;

typedef struct node {
   DataType  data;//存储数据
   struct node*next;  
}Qnode,*PQNode;

typedef struct{
    PQNode front,rear;
}LinkQueue,*PLinkQueue;

//初始化一个空队列

PLinkQueue Init_LinkQueue()
{
    PLinkQueue Q;
    Q=(PLinkQueue)malloc(sizeof(LinkQueue));
    if(Q)
    {
        Q->front=NULL;
        Q->rear=NULL;
    }
    return Q;
}

//判断队列空

int Empty_LinkQueue (PLinkQueue Q)
{
    if(Q && Q->front==NULL && Q->rear==NULL)
    return 1;
    else 
    return 0;
}

//入队

int In_LinkQueue (PLinkQueue Q,DataType x)
{
   PQNode p;
   p=(PQNode)malloc(sizeof(Qnode));
   if(!p)
   {
       printf("溢出");
       return 0;
   }
   p->data=x;
   p->next=NULL;
   if(Empty_LinkQueue(Q))
    Q->rear=Q->front=p;
    else 
    {
        Q->rear->next=p;
        Q->rear=p;
    }
    return 1;
}

//出队

int out_LinkQueue(PLinkQueue Q,DataType*x)
{
    PQNode p;
    if(Empty_LinkQueue(Q))
    {
        printf("队空");
        return 0;
    }
    *x=Q->front->data;
    p=Q->front;
    Q->front=Q->front->next;
    free(p);
    if(!Q->front)
     Q->rear=NULL;
     return 1;
}

//读队头元素

int Front_LinkQueue(PLinkQueue Q,DataType*x)
{
    if(Empty_LinkQueue(Q))
    {
        printf("队空");
        return (0);
    }
    *x=Q->front->data;
    return 1;
}

void  Destroy_LinkQueue(PLinkQueue * Q)
{/*这里的Q是指针形变量指向队列所以要想引用队列需要加*
又因为->优先级高所以要加括号,为了方便看所以让s=*Q */
    PQNode p;
    PLinkQueue s;
    s=*Q;
    if(s)
    {
        while(s->front)
        {
            p=s->front;
            s->front=s->front->next;
            free(p);
        }
        free(s);
    }
    *Q=NULL;
}