/*
动态堆存储
c语言中是通过malloc，realloc，free等函数实现对堆的使用
串的堆式存储，一般仍是以一组地址连续的存储单元存放字符串，
但串的空间是在程序运行中动态获取的，在使用结束后，归还堆
*/
#include<stdio.h> 
#include<stdlib.h>
#include<malloc.h>

typedef struct{
    char *p_ch;
    int length;
}Hstring;

int StrAssign(Hstring*s1,char*s2)
{/*串常量赋值 将一个字符串常量的值赋值给一个字符串变量*/
    int i;char *pc;
    if(s1->p_ch)free(s1->p_ch);
    for(i=0,pc=s2;*pc!='\0';i++,pc++);
    if(i==0)
    {
        s1->p_ch=0;s1->length=0;
        return 0;
    }
    if(!(s1->p_ch=(char *)malloc(i*sizeof(char))))
    {
        printf("堆空间不足，赋值失败！\n");
        return 0;
    }
    for(int j=0;j<i;j++) s1->p_ch[j]=s2[j];
    s1->length=i;
    return 1;
}

int StrCopy(Hstring*s1,Hstring s2)
{//赋值一个串 将一个字符串的值给一个字符串变量
        if(s2.length<=0)return 0;
        if(!(s1->p_ch=(char*)malloc(s2.length*sizeof(char))))
        {
        printf("堆空间不足，赋值失败！\n");
        return 0;
        }
        for(int i=0;i<s2.length;i++)
            s1->p_ch[i]=s2.p_ch[i];
        s1->length=s2.length;
        return 1;
}

int SubString(Hstring *Sub,Hstring S, int pos,int len)
{/*求子串 用Sub返回串s的第pos个字符起长度为len的子串；其中，1<=pos<=StrLength(S)
且0<=len<=StrLength(S)-pos+1*/
  int i;
  if(pos<1||pos>S.length ||len<0||len>S.length-pos+1 )
  return 0;
  if(Sub->p_ch)free(Sub->p_ch);
  if(!len)
  {
      Sub->p_ch=0;
      Sub->length=0;
  }
  else
  {
      Sub->p_ch=(char*)malloc(len*sizeof(char));
      for(i=0;i<len;i++) Sub->p_ch[i]=S.p_ch[pos-1+i];
      Sub->length=len;
  }
  return 1;
}

int StrContact(Hstring *t,Hstring s1,Hstring s2)
{/*串连接  t保存由字符串s1和s2连接而成的新串*/
      int i;
      if(t->p_ch) free(t->p_ch);
      if(!(t->p_ch=(char*)malloc(s1.length+s2.length*sizeof(char))))
        {
        printf("堆空间不足，串连接失败！\n");
        return 0;
        }
        for(int i=0;i<s1.length;i++)  t->p_ch[i]=s1.p_ch[i];
        t->length=s1.length+s2.length;
        for(i=s1.length;i<t->length;i++)
        t->p_ch[i]=s2.p_ch[i-s1.length];
        return 1;
}

int StrInsert(Hstring*s,int pos,Hstring t)
{/*在目标串的指定位置前插入字符串 1<=pos<=StrLength(s)+1,在串s的第pos字符前插入串t*/
       int i;
       if(pos<1||pos>s->length+1) return 0;
       if(t.length==0) return 1;
       if(!(s->p_ch=(char*)realloc(s->p_ch,(s->length+t.length)*sizeof(char))))
       {
           printf("对空间不足，插入失败！\n");
           return 0;
       }
       for(i=s->length-1;i>=pos-1;i++)
        s->p_ch[i+t.length]=s->p_ch[i];
        for(i=pos-1;i<pos+t.length-2;i++)
         s->p_ch[i]=t.p_ch[i-pos+1];
         s->length=s->length+t.length;
         return 1;
}

int Init_Strinf(Hstring*s)
{//置空串
    s->p_ch=0;
    s->length=0;
    return 1;
}

int Destory_String(Hstring*s)
{//销毁串
    if(s->length)
    {
        free(s->p_ch);
        s->p_ch=0;
        s->length=0;
    }
    return 1;
}