#include <stdio.h> //单链表 线性表的链式存储结构
#include <malloc.h>
#include<stdlib.h>

typedef int DataType;

typedef struct node
{
    DataType data;
    struct node*next;
}LNode,*LinkList;

LinkList Creat_LinkList(void)
{//创建空单链表 返回单链表头指针
    LinkList H;
    H=(LinkList)malloc(sizeof(LNode));
    if(H)
    H->next=NULL;
    return H;
}

void Destroy_LinkList(LinkList * H)
{//单链表的销毁 入口：单链表头指针的地址  调用时Destroy_LinkList(&H)；
    LinkList p,q;
    /*这里申请的是指针变量存储的是地址等价于
    LNode *p,*q; */
    p=*H;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    *H=NULL;
}

int Length_LinkList (LinkList H)
{//单链表求表长 入口：单链表头指针 出口：表长，-1单链表不存在
    LinkList p=H;  //p指向头结点
    int count=-1;  //H带头结点所以从-1开始
    while(p)       //p所指的是count+1个结点
    {
        p=p->next;
        count++;
    }
    return(count);
}

//查找操作

LinkList Locate_LinkList_Pos(LinkList H,int i)
{/*按序号查找  入口：单链表头指针，查找的位置 
             出口：i不存在返回NULL，i==0返回头指针，否则返回第8

    LinkList p;
    int j;
    p=H;  j=0;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(j!=i || !p)
    {
        printf("参数i错或单链表不存在");
        return (NULL);
    }
    return(p);
}

LinkList Locate_LinkList_Value(LinkList H,int x)//x数据类型可更改
{//按值查找
    LinkList p=H->next;
    while (p && p->data!=x)
    {
        p=p->next;
    }
    return(p);
}

LinkList fuzhi (LinkList H)
{   int i,len;
    LinkList H_head=(LinkList)malloc(sizeof(LinkList));
    LinkList H_new;
    H=H_head;
    H->next = NULL;
    printf("请输入节点的个数:");
    scanf("%d",&len);
    for (i=0;i<len;i++)
    {   
        H_new=(LinkList)malloc(sizeof(LinkList));
        printf("输入数值");
        scanf("%d",&H_new->data);
        H->next=H_new;//将尾节点指向新节点
        H_new->next=NULL;//新节点应该指向NULL
        H=H_new;//当前尾节点为新节点
    }
    return(H_head);
}

LinkList xianshi (LinkList H)
{
    LinkList p;
    p=H;
    p=p->next;
    while(p!=NULL)
    { 
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
    return (0);
}
//两个循环单链表 H1，H2的链接操作

LinkList lianjie (LinkList H,LinkList R)
{  LinkList H_head=H;
   while(H->next!=NULL) H=H->next;
   H->next=R->next;
   return H_head;
}

int main()
{
    LinkList H1,H2,p;
    H1=fuzhi(H1);
    H2=fuzhi(H2);
    p=lianjie(H1,H2);
    xianshi(p);
}







//插入

int Insert_LinkList(LinkList H,int i,int x)//x数据类型可更改
{
    LinkList p,q;
    p=Locate_LinkList_Pos(H,i-1);
    if(!p)
    {
        printf("i有误");
        return(0);
    }
    q=(LinkList)malloc(sizeof(LNode));
    if(!q)
    {
        printf("申请空间失败");
        return(0);
    }
    q->data=x;
    q->next=p->next;
    p->next=q;
    return 1;
}

//删除

int Dete_LinkList(LinkList H,int i)
{
    LinkList p,q;
    if(H==NULL || H->next==NULL)
    {
        printf("链表不存在或者空表不能删除");
        return (0);
    }
    p=Locate_LinkList_Pos(H,i-1);
    if(p==NULL || p->next==NULL)
    {
        printf("参数i错");
        return(0);
    }
    q=p->next;
    p->next=q->next;
    free(q);
    return(1);
}