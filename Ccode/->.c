#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 16

typedef struct 
{
  int  a[2];
}D;

typedef struct DataType{
    D b[2];
}DataType;

typedef struct node{
    DataType a[MAX];
    struct node *next;
}a,*pa;

pa chushihua ()
{  pa j;
   j=(pa)malloc(sizeof(a));
   int i=0,d=0;
   while (i<MAX)
    {  if(d==0) 
        {
            d=1;
            (&((&((*j).a[i]))->b[d]))->a[d]=i;
        }
        else  
        {    
            d=0;
            (&(j->a[i]))->b[d].a[d]=i;
        }
        i++;
        
    }
     return j;
}

int main()
{   pa a;
    int i=0,d=0;
    a=chushihua(a);
    pa p;
    p=a;
    while(i<MAX)
    {  
        if(d==0) d=1;
        else   d=0;
       printf("a[%d].b[%d].a[%d]=",i,d,d);
       printf("%d\n",a->a[i++].b[d].a[d]);
    }    
    i=0;
    while(i<MAX)
    {  
        if(d==0) d=1;
        else   d=0;
       printf("a[%d].b[%d].a[%d]=",i,d,d);
       printf("%d\n",p->a[i++].b[d].a[d]);
       //p->a[i++]对于b来说相当于*p想要用->
       //需要转换用(&（p->a[i++]))->b[d]表示S
    }    
}

    