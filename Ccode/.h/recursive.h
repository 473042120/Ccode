#include <stdio.h>//递归

int jieji (int n)  //求阶级
{
    if (n==0)
    return 1;
    else 
    return (n*jieji(n-1));
}

int max (int a[],int l,int h) //求最大
{
  if(l==h)  return a[l];
  int m,x,y;
  m=(l+h)/2;
  x=max (a,l,m);
  y=max (a,m+1,h);
  if(x>y)
      return x;
  else
      return y;
}

int sum (int a[],int l,int h) //求和
{
    if(l==h)
      return a[1];
    else
      return (sum(a,1,h-1)+a[h]);
}


void Swap (int A[],int i,int j) //数组中两个数据交换
{
    int x;
    x=A[i];
    A[i]=A[j];
    A[j]=x;
}

void Perm(int list [],int  k, int m)//递归全排列集合的全部排列 

{
    int i;
    if(k==m)
    {
        for (i=0;i<=m;i++) printf("%d",list[i]);
        printf("\n");
    }
    else
    {
        for(i=k; i<m; i++)
        {
            Swap(list,k,i);
            Perm(list,k+1,m);
            Swap(list,k,i);
        }
    }
}

void ConverseStrt (char *str ,int start,int end)
{
    if(end-start<1)
    return;
    else
    {
    //    str[start] <-> str[end];//将首尾字符交换有问题有待更改
        ConverseStrt (str,start+1,end-1);
    }
    
}








//迷宫递归
#define m  6                    //迷宫
#define n  8                    //迷宫
#include <malloc.h>             //迷宫
#include "SeqStackmaze.h"   //迷宫

int path (int maze[][n+2],item move[],int x,int y,int step)
{
   int i;
   step++;
   maze[x][y]==step;
   if(x==m&&y==n)
   return 1;
   for(int i=0;i<4;i++)
   {
       if(maze[x+move[i].x][y+move[i].y]==0)
           if(path(maze,move,x+move[i].x,y+move[i].y,step))
             return 1;
   }
   step--;
   maze[x][y]=0;
   return 0;
}

//火车出站可能

int Train_into_PlatForm(int i,int j)
{
    if(i==0) return 1;  //火车没有，或者全部在站台内
    else 
     if(j==0) return Train_into_PlatForm(i-1,1);
      else return Train_into_PlatForm(i-1,j+1)+Train_into_PlatForm(i,j-1);
}

int dunno(int p)
{
    int v;
    if(p==0) v=3;

    else v=dunno(p-1)+5;
    return v;
}