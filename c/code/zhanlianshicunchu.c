#include<stdio.h>
#include<malloc.h>

typedef struct node //结点结构
{
    int data;//int可更改
    struct node *next;
}StackNode,*PStackNode;

typedef struct {   //栈
    PStackNode top;
}LinkStack ,*PLinkStack;

//初始化空栈

PLinkStack Init_LinkStack (void)
{
    PLinkStack S;
    S=(PLinkStack)malloc(sizeof(LinkStack));
    if(S)  S->top=NULL;
    return (S);
}

//判断栈空

int  Empty_LinkStack (PLinkStack S)
{
    if(S->top==NULL)
    return 0;
    else
    return 1;
}

//入栈

int Push_LinkStack(PLinkStack S, int x)
{//进栈，入口参数：链栈指针，进栈元素，返回值：1表示成功，0表示失败
  PStackNode P;
  P=(PStackNode)malloc(sizeof(StackNode));
  if(!P)
  {
      printf("内存溢出");
      return 0;
  }
  P->data=x;
  P->next=S->top;
  S->top=P;
  return(1);
}

//出栈

int Pop_LinkStack(PLinkStack S,int *x)
{
    PStackNode P;
    if(Empty_LinkStack(S))
 {
     printf("栈空，不能出栈");
     return (0);
 }
    *x=S->top->data;
    P=S->top;
    S->top=S->top->next;
    free(P);
    return(1);
}

//取栈顶元素

int GetTop_LinkStack(PLinkStack S,int *x)
{
    if(Empty_LinkStack (S))
    {
        printf("栈空");
        return(0);
    }
    *x= S->top->data;
    return 1;
}

//销毁栈

void Destroy_LinkStack (PLinkStack *LS)
{
    PStackNode p,q;
    if(*LS)
    {
        p=(*LS)->top;
        while(p)
        {
            q=p;
            p=p->next;
            free(q);
        }
        free(*LS);
    }
    *LS=NULL;
    return ;
}