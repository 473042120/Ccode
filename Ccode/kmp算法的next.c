#include<stdio.h>
#include <stdlib.h>
void shuzi (int next[],int j)
{  
    int i=0;
    while(i<=j)
    {
        i++;
        printf("%d ",next[i]);
      //   if(i%5==0)
      //   printf("\n");
    }
     printf("\n");
}

void zifu (char *t)
{   
    int i=1;
    while(t[i]!='\0')
    {
        printf("%c ",t[i]);
        i++;
    }
    printf("\n");
}
void GetNext(char *t ,int next[])
{
    int i=1,j=0;
    next[1]=0; 
    while(i<t[0])
    {
        if(j==0||t[i]==t[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

void GetNext_Recursion (char *t,int next[],int L)
{//求模式t的next的值并存入nxet数组中，参数t为模式串，L为模式串的长度（t[0]），算法结束时，字符串t的next数组值保存在数组next[]中，从下标为1开始存储
   
   if(L==1)
   {
       next [1]=0;
       return ;
   }
   GetNext_Recursion(t,next,L-1);
   int k=next[L-1];
   while(1)
   {
       if(t[k]==t[L-1])
       {
           next[L]=k+1;
           return;
       }
       k=next[k];
       
       if(k==0)
       {
           next[L]=1;
           return;
       }
   }
}
void main()//'9','a','b','c','a','b','c','a','b','c'{'9','a','b','c','a','a','b','a','b','c'};
{   
    int t[50];  
    char cuan[10]="8abcacbca";
    zifu(cuan);
    GetNext_Recursion(cuan,t,8);
    shuzi(t,7); 
    // GetNext(cuan,t);
    // shuzi(t,7);    
}