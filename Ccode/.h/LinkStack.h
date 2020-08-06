#include <stdio.h> //栈链式存储
#include <malloc.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node //结点结构
{
    DataType data;
    struct node *next;
} StackNode, *PStackNode;

typedef struct
{ //栈定义
    PStackNode top;
} LinkStack, *PLinkStack;

PLinkStack Init_LinkStack(void)
{//初始化空栈
    PLinkStack S;
    S = (PLinkStack)malloc(sizeof(LinkStack));
    if (S)
        S->top = NULL;
    return (S);
}

int Empty_LinkStack(PLinkStack S)
{//判断栈空
    if (S->top == NULL)
        return 0;
    else
        return 1;
}

int Push_LinkStack(PLinkStack S, DataType x)
{ //入栈进栈，入口参数：链栈指针，进栈元素，返回值：1表示成功，0表示失败
    PStackNode P;
    P = (PStackNode)malloc(sizeof(StackNode));
    if (!P)
    {
        printf("内存溢出");
        return 0;
    }
    P->data = x;
    P->next = S->top;
    S->top = P;
    return (1);
}

int Pop_LinkStack(PLinkStack S, DataType *x)
{//出栈
    PStackNode P;
    if (Empty_LinkStack(S))
    {
        printf("栈空，不能出栈");
        return (0);
    }
    *x = S->top->data;
    P = S->top;
    S->top = S->top->next;
    free(P);
    return (1);
}

int GetTop_LinkStack(PLinkStack S, DataType *x)
{//取栈顶元素
    if (Empty_LinkStack(S))
    {
        printf("栈空");
        return (0);
    }
    *x = S->top->data;
    return 1;
}

void Destroy_LinkStack(PLinkStack *LS)
{//销毁栈
    PStackNode p, q;
    if (*LS)
    {
        p = (*LS)->top;
        while (p)
        {
            q = p;
            p = p->next;
            free(q);
        }
        free(*LS);
    }
    *LS = NULL;
    return;
}