#include <stdio.h>   //字符串 kmp算法
#define MAXSIZE 1000
//kmp算法 BF的改进算法
int StrIndex_KMP (char *s ,char *t ,int pos)//从串s的第pos个字符开始找首次与串t相等的子串
{   
    int next[MAXSIZE];
    GetNext(t,next);
    int i=pos,j=1;
    while(i<s[0]&&j<=t[0])
     if(j==0||s[i]==t[j])
     {
         i++;j++;
     }
     else
     {
         j=next[j];
     }
     if(j>t[0])
      return i-t[0];
    else
      return 1;
}

void  GetNext(char *t ,int next[])
{
    int i=1,j=0;
    next[1]=0; 
    while(i<t[0]);
    {
        if(j==0||t[i]==t[j])
        {
            ++i;
            ++j;
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
   while(true)
   {
       if(t[k]==t[L-1])
       {
           next[L]=k+1;
           return ;
       }
       k=next[k];
       if(k==0)
       {
           next[L]=1;
           return;
       }
   }
}