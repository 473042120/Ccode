#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
#define m 6
#define n 8

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

typedef struct {
    int x,y;
}item;
item move[4]={0,1,
              1,0,
              0,-1,
              -1,0}; //迷宫前进的方向

typedef struct {
    int x,y,d;
}DataTypde;  //迷宫的坐标

typedef struct node{
    int x[MAXSIZE];
    int y[MAXSIZE];
    int d[MAXSIZE];
    int size=100;
    int prior;
    int next;
}SeqStack,*PSeqStack;//迷宫的队列

PSeqStack Init (void)
{
    PSeqStack S;
    S=(PSeqStack)malloc(sizeof(SeqStack));
    if(S)
    {
        S->prior=0;
        S->next=0;
    }
    else 
    printf("失败");
    return(S);
}

int Empty (PSeqStack S)
{
    if(S->prior==S->next)
    return 1;
    else
    return 0;   
}

int filled (PSeqStack S)
{
    if(((S->next+1)%S->size)==S->prior)
    return 1;
    else return 0;
}

int push (PSeqStack S,DataTypde z)
{   
    if(filled(S))
    {
        printf("溢出");
        return 0;
    }
    else
    {
    S->next=((S->next+1)%S->size);
    S->x[S->next]=z.x;
    S->y[S->next]=z.y;
    S->d[S->next]=z.d;
    return 1;
    }
}


int pop (PSeqStack S,DataTypde z)
{   
    if(Empty(S))
    return 0;
    else{
    S->prior=(S->prior+1)%S->size;
    z.x=S->x[S->prior];
    z.x=S->y[S->prior];
    z.x=S->d[S->prior];
    return 1;}
}

void Destroy_SeqStack (PSeqStack & S)
{
  if(S)
   free(S);
   S=NULL;
   return;
}

void  mazepath (int maze[][n+2], item move[], int x1,int y1,int x2,int y2)
{   
    int i,j,d,x,y;
    PSeqStack S;
    S=Init();
    DataTypde z;
    z.x=x1;z.y=y1;z.d=-1;
    push(S,z);
    while(!Empty(S))
    {   
        pop(S,z);
        x=z.x; y=z.y; d=z.d+1;
        while(d<4)
        {
          i=x+move[d].x; j=y+move[d].y; 
          if(maze[i][j]==0)
         { z.x=x;
          z.y=y;
          z.d=d;
          push(S,z);
          x=i;y=j; maze[x][y]=-1;
          if(x==x2&&y==y2)
          {
              z.x=x2;
              z.y=y2;
              push(S,z);
              while(!Empty(S))
              {
                  pop(S,z);
                  printf("(%d,%d)",z.x,z.y);
              }
              Destroy_SeqStack(S);
              
          }
         else d=0;    
        }
        else d++;
        }
    }
  Destroy_SeqStack(S);
  
    
}