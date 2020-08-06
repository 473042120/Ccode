#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct node{
    int a[10];
    struct node *next;
}a,*pa;

a chushihua (pa i)
{
   i=(pa)malloc(sizeof(a));
   i->next;
   (*i).next;
   (*i).a[0]=0;
   i->a[1]=1;
   (*i).a[2]=2;

}

int main()
{   pa a;
    chushihua(a);
    printf("%d ",a->a[2]);
    printf("%d ",(*a).a[1]);
    printf("%d ",(*a).a[0]);
}