#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
#define m 6
#define n 8

typedef struct {
    int x,y;
}item;
item move[4]={0,1,
              1,0,
              0,-1,
              -1,0};

typedef struct{
    int x,y,d;
}DataType;

typedef struct {
    int x[MAXSIZE];
    int y[MAXSIZE];
    int d[MAXSIZE];//这里的int可以自定义
    int top;
}SeqStack, *PSeqStack;

//初始化空栈

PSeqStack Init_SeqStack(void)
{
    PSeqStack S;
    S=(PSeqStack)malloc(sizeof(SeqStack));
    if(S)
    {
        S->top=-1;
    }

    else
    {
        printf("失败");
    }
     return (S);
}

//判栈空

int Empty_SeqStack (PSeqStack S)
{
    if(S->top==-1)
    return 1;
    else
    return 0;
}

//入栈

int Push_SeqStack(PSeqStack S,DataType *z)//x的数据类型可自己定义
{
    if(S->top==MAXSIZE-1)
    {
     printf("栈溢出");
     return 0;
    }
    else
    {
        S->top++;
        S->x[S->top]=z->x;
        S->y[S->top]=z->y;
        S->d[S->top]=z->d;
      return 1;
    }
}

//出栈

int Pop_SeqStack(PSeqStack S,DataType *z)//x的数据类型自定义
{
    if(Empty_SeqStack (S))
    return 0;
    else 
    {
        z->x=S->x[S->top];
        z->y=S->y[S->top];
        z->d=S->d[S->top];
        S->top--;
        return 1;
    }
}

//销毁栈

void Destroy_SeqStack (PSeqStack * S)
{
  if(*S)
   free(*S);
   *S=NULL;
   return;
}

int mazepath (int maze[][n+2],item move[],int x0,int y0)
{
    PSeqStack S;
    DataType temp;
    int x,y,d,i,j;
    temp.x=x0; temp.y=y0; temp.d=-1;
    S=Init_SeqStack();
    if(!Empty_SeqStack(S))
    {
        printf("栈初始化失败");
        return 0;
    }
    Push_SeqStack(S,&temp);
    while(!Empty_SeqStack(S))
    {
        Pop_SeqStack(S,&temp);
        x=temp.x; y=temp.y; d=temp.d+1;
        while(d<4)
        {
            i=x+move[d].x; j=y+move[d].y;
            if( maze[i][j]==0 )
            {
                temp.x=x;
                temp.y=y;
                temp.d=d;
                Push_SeqStack(S,&temp);
                x=i;y=j;maze[x][y]=-1;
                if(x==m&&y==n)
                {   temp.x=m;
                    temp.y=n;
                    Push_SeqStack(S,&temp);
                    while(!Empty_SeqStack(S))
                    {
                        Pop_SeqStack(S,&temp);
                        printf("(%d,%d)",temp.x,temp.y);
                    }
                    Destroy_SeqStack(S);
                    return 1;
                }
                else d=0;
            }
            else  d++;
        }
    }
    Destroy_SeqStack(S);
    return 0;
}

int  xianshi ( int maze[][n+2] )
{   int i,j;
       for(i=0;i<8;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%d  ",maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}