#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];//这里的int可以自定义
    int top;
}SeqStack, *PSeqStack;

//初始化空栈

PSeqStack Init_SeqStack(void)
{
    PSeqStack S;
    S=(PSeqStack)malloc(sizeof(SeqStack));
    if(S)
        S->top=-1;
    return S;
}

//判栈空

int Empty_SeqStack (PSeqStack S)
{
    if(S->top==-1)
        return 1;
    else
        return 0;
}

//入栈

int Push_SeqStack(PSeqStack S,int x)//x的数据类型可自己定义
{
    if(S->top==MAXSIZE-1)
      return 0;
    else
    {
        S->top++;
        S->data[S->top]=x;
      return 1;
    }
}

//出栈

int Pop_SeqStack(PSeqStack S,char *x)//x的数据类型自定义
{
    if(Empty_SeqStack (S))
    return 0;
    else 
    {
        *x=S->data[S->top];
        S->top--;
        return 1;
    }
}

//取栈顶元素

int GetTop_SeqStack(PSeqStack S,char *x)//x类型自定义
{
    if(Empty_SeqStack(S))
     return 0;
    else
    {
        *x =S->data[S->top];
    return 1;
    }  
}

//销毁栈

void Destroy_SeqStack (PSeqStack * S)
{
  if(*S)
   free(*S);
   *S=NULL;
   return;
}


int IsNum(char c)
{
    if(c>='0'&&c<='9')
    return 1;
    else return 0;
}

int priority (char op)
{
    switch (op)
    {
        case '#': return(1);
        case ')': return(2);
        case '+':
        case '-': return(3);
        case '*': 
        case '/': return(4);
        case '(': return(5);
        default : return(0);
    }
}

typedef char DataType;

int infix_exp_value(char *infixexp,char *postfixexp)
{
    PSeqStack S;
    char c,w, topelement;
    S=Init_SeqStack();
    if(!S)
    {
        printf("初始化失败");
        return 0;
    }
    Push_SeqStack(S,'#');
    w=*infixexp;
    while((GetTop_SeqStack(S,&c),c)!='#'||'w'!='#')
    {
        if( IsNum(w))
        {
            *postfixexp=w;
            postfixexp++;
            w=*(++infixexp);
        }
        else
        {
            if ((GetTop_SeqStack(S,&c),c) == '(' && w ==')')
            {
                Pop_SeqStack(S,&topelement);
                w=*(++infixexp);
            }
            else 
            {
                if((GetTop_SeqStack(S,&c),c) == '(' 
                || priority((GetTop_SeqStack(S,&c),c)<priority(w)))
                {
                    Push_SeqStack(S,w);
                    w=*(++infixexp);
                }
                else
                {
                Pop_SeqStack(S,&topelement);
                *postfixexp=topelement;
                postfixexp++;
                }
            }
        }
        *postfixexp='#';
        *(++postfixexp)='\0';
        postfixexp++;
    }
    
}
