#include <stdio.h>  //队列链式存储
#include <malloc.h>

typedef struct node {
   int  data;//存储数据
   struct node*next;  
}Qnode,*PQNode;

typedef struct{
    PQNode front,rear;
}LinkQueue,*PLinkQueue;

//初始化一个空队列

PLinkQueue Init_LinkQueue()
{
    PLinkQueue Q;
    Q=(PLinkQueue)malloc(sizeof(Init_LinkQueue));
    if(Q)
    {
        Q->front=NULL;
        Q->rear=NULL;
    }
    return Q;
}

//判断队列空

int Empty_LinkQueue (PLinkQueue (Q))
{
    if(Q&&Q->front==NULL&&Q->rear==NULL)
    return 1;
    else 
    return 0;
}

//入队

int In_LinkQueue (PLinkQueue Q,int x)
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

int out_LinkQueue(PLinkQueue Q,int*x)
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

int Front_LinkQueue(PLinkQueue Q,int*x)
{
    if(Empty_LinkQueue(Q))
    {
        printf("队空");
        return (0);
    }
    *x=Q->front->data;
    return 1;
}

// void  Destroy_LinkQueue(PLinkQueue *Q)
// {
//     PQNode p,s;
//     if(*Q)
//     {
//         while(Q->front)
//         {
//             p=Q->front;
//             Q->front=Q->front->next;
// //报错expression must have pointer-to-struct-or-union type
// //我认为的是队列Q还没创建所以没有指向就是根本没有这个队列肯定报错
//             free(p);
//         }
//         free(*Q);
//     }
//     *Q=NULL;
// }