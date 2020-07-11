#include<stdio.h>
#include<malloc.h>

typedef struct 
{
    char*p_ch;
    int length;
}Hstring;

//串常量赋值
int StrAssign (Hstring * s1,char * s2)
{
   int i;char *pc;
   if(s1->p_ch)free (s1->p_ch);
   for(i=0,pc=s2;*pc!='\0';i++,pc++);
   if(i==0)
   {
       s1->p_ch=0;s1->length=0;
       return 0;
   }
   if(!(s1->p_ch=(char *)malloc(i* sizeof(char))))
   {
       printf("堆空间不足，赋值失败！\n");
       return 0;
   }
   for(int j=0; j<i;j++)
   s1->p_ch[j]=s2[j];
   s1->length=i;
   return 1;
}


//赋值一个串

int StrCopy(Hstring *s1,Hstring s2)
{
    if(s2.length<=0) return 0;
    if(!(s1->p_ch=(char *)malloc(s2.length*sizeof(char))))
    {  
       printf("堆空间不足，赋值失败！\n");
       return 0;
    }
    for(int i=0;i<s2.length;i++)   s1->p_ch[i]=s2.p_ch[i];
    s1->length=s2.length;
    return 1;
}


//求子串

int SubString(Hstring *Sub,Hstring S,int pos,int len)
{ //用Sub返回串s的第pos个字符起长度为len的子串；其中，1<=pos<=StrLength(S)且0<=len<=StrLength(S)-pos+1
    int i;
    if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
    return 0;
    if(Sub->p_ch)free(Sub->p_ch);
    if(!len)
    {
        Sub->p_ch=0;
        Sub->length=0;
    }
    else
    {
        Sub->p_ch=(char *)malloc(len *sizeof(char));
        for(i=0;i<len;i++) Sub->p_ch[i]=S.p_ch[pos-1+i];
        Sub->length=len;        
    }
    return 1;
}

//串连接

int StrContact (Hstring*t,Hstring s1,Hstring s2)
{//*t保存字符串s1,s2连接的新串
    if(t->p_ch)  free(t->p_ch);
    if(!(t->p_ch=(char*)malloc((s1.length+s2.length)*sizeof(char))))
    {
        printf("堆空间不足，串连接失败！\n");
        return 0;
    }
    for(int i=0;i<s1.length;i++) t->p_ch[i]=s1.p_ch[i];
    t->length=s1.length+s2.length;
    for(int i=s1.length;i< t->length;i++) t->p_ch[i]=s2.p_ch[i-s1.length];
    return 1;
}

//在目标串的指定位置前插入字符串

int StrInsert(Hstring *s,int pos,Hstring t)
{
    int i;
    if(pos<1 ||pos>s->length+1)return 0;
    if(t.length==0)return 1;
    if(!(s->p_ch=(char *)realloc(s->p_ch,(s->length+t.length)*sizeof(char))))
    {
      printf("堆空间不足，插入失败！\n");
      return 0;
    }
    for(i=s->length-1;i>=pos-1;i--)
    {
        s->p_ch[i+t.length]=s->p_ch[i];
    }
    for(i=pos-1;i<=pos+t.length-2;i++)
    {
        s->p_ch[i]=t.p_ch[i-pos+1];
    }
    s->length=s->length+t.length;
    return 1;
}

//置空串

int Init_String (Hstring *s)
{
   s->p_ch=0;
   s->length=0;
   return 1;
}

//销毁串

int Destory_String(Hstring *s)
{
        if(s->length)
    {
        free(s->p_ch);
        s->p_ch=0;
        s->length=0;
    }
    return 1;
}