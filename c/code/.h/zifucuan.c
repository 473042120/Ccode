#include <stdio.h>
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
