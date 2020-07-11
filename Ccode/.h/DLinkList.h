#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100

typedef struct node
{
   int data;
   struct node *prior,*next;
}DuNode,*DLinkList;

DLinkList fuzhi (DLinkList H)
{   int i,len;
    DLinkList H_head=(DLinkList)malloc(sizeof(DLinkList));
    DLinkList H_new;
    H=H_head;
    printf("请输入节点的个数:");
    scanf("%d",&len);
    for (i=0;i<len;i++)
    {   
        H_new=(DLinkList)malloc(sizeof(DLinkList));
        printf("输入数值");
        scanf("%d",&H_new->data);
        H_new->prior=H;
        H->next=H_new;//将尾节点指向新节点
        H_new->next=NULL;//新节点应该指向NULL
        H=H_new;//当前尾节点为新节点
    }
    return(H_head);
}

DLinkList fanxiang(DLinkList H)
{  
    DLinkList p;
    p=H;
    while(p->next!=NULL)  p=p->next;  //找出尾节点
    while(p->prior) //我认为的是赋值时申请空间的时候默认头节点是空的
    { 
        printf("%d",p->data);
        p=p->prior;
    }
    printf("\n");
    return (0);
}

DLinkList xianshi (DLinkList H)
{
    DLinkList p;
    p=H;
    p=p->next;
    while(p)
    { 
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
    return (0);
}


//插入

int  chrru (DLinkList p, DLinkList s)
{
  s->prior=p->prior;
  p->prior->next=s;
  s->next=p;
  p->next=s;
  return 0;
}
