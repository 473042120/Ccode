/*静态堆存储*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXNAME 100
#define SMAX 100

typedef struct Hstring
{//带串长度的索引表
    char name[MAXNAME];
    int length;
    char* stradr;
}LNode;

typedef struct 
{//末尾指针的索引表
 char name[MAXNAME];
 char *stradr,*enadr;   
}ENode;

char store[SMAX+1];
int free;

typedef struct 
{//串的存储映像类型
    int length;
    int stradr;
}Hstring;

int StrLength(char * s)
{
    ;
}

int StrAssign(Hstring*s1,char *s2)
{/*串常量赋值 将一个字符型数组s2中的字符串送入堆store中，free是
自由区的指针，正常操作返回1 */
    int i=0,len;
    len=StrLength(s2);
    if(len<0||free+len-1>SMAX)
    return 0;
    else{
        for(i=0;i<len;i++)
        store[free+i]=s2[i];
        s1->stradr=free;
        s1->length=len;
        return 1;
    }
}

int StrCopy(Hstring*s1,Hstring s2)
{/* 赋值一个串 该运算将堆store中的一个串s2复制到一个
新串s1中，正常操作返回1 */
    int i;
    if(free+s2.length-1>SMAX)
    return 0;
    else
    {
       for(i=0;i<s2.length;i++)
         store[free+i]=store[s2.stradr+i];
         s1->length=s2.length;
         s1->stradr=free;
         free=free+s2.length;
         return 1;
    }   
}

int StrSub(Hstring*t, Hstring s,int i,int len)
{/*求子串 该运算将串s中第i个字符开始的长度为len的子串送到
一个新串t中，正常操作返回1 */
    int i;
    if(i<0||len<0||len>s.length-i+1)
    return 0;
    else
    {
        t->length=len;
        t->stradr=s.stradr+i-1;
        return 1;
    }
}

void StrConcat(Hstring s1,Hstring s2,Hstring *s)
{//串连接
    Hstring t;
    StrCopy (s,s1);
    StrCopy(&t,s2);
    s->length=s1.length+s2.length;
}