#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct{
    int data[MAXSIZE];
    int top;
}SeqStack,*PSeqStack;

PSeqStack Init_SeqStack (void)
{
    PSeqStack S;
    S=(PSeqStack)malloc(sizeof(SeqStack));
    if(S)
    {
        S->top=-1;
    }
    return(S);
}

int Empty_SeqStack (PSeqStack S)
{
    if(S->top==-1)
    return(1);
    else
    return 0;
}

int Push_SeqStack(PSeqStack S,int  x)
{
    if(S->top==MAXSIZE-1)
    return 0;
    else 
    {
        S->top++;
        S->data[S->top]=x;
        printf("shu%d\n",S->data[S->top]);
        return 1;
    }
}

int Pop_SeqStack(PSeqStack S,int*x)
{
    if(Empty_SeqStack(S))
    return 0;
    else{
        *x=S->data[S->top];
        S->top--;
        return 1;
    }
}

int GetTop_SeqStack(PSeqStack S,int*x)
{
    if(Empty_SeqStack(S))
     return 0;
    else
    {
        *x =S->data[S->top];
    return 1;
    }  
}

void Destroy_SeqStack (PSeqStack *S)
{
    if(*S)
    free(*S);
    *S=NULL;
    return;
}

typedef double  DataType;

int IsNum (char c)
{   
    if(c>='0'&& c<='9') return 1;
    else  return 0;
}

int postfix_exp(char* A)
{
    PSeqStack S;
    char ch;
    int Resulet,a,b,c;
    ch=*A++;
    S=Init_SeqStack();
    while(ch!='\0')
    {
        if(IsNum(ch)) 
        {
            c=(int)ch-48;
            Push_SeqStack(S,c);
        }
        else
        { 
            Pop_SeqStack(S,&b);
            Pop_SeqStack(S,&a);
            switch(ch)
            {
                case '+': c=a+b;break;
                case '-': c=a-b;break;
                case '*': c=a*b;break;
                case '/': c=a/b;break;
                case '%': c=a%b;break;
            }
            Push_SeqStack(S,c);
        }
        ch=*A++;
    }
    GetTop_SeqStack(S,&c);
    printf("%d\n",c);
    Destroy_SeqStack(&S);
    return Resulet;
}

int main()
{   
    char ch;
    while(ch!='#')
   {
    scanf("%s",&ch);
    postfix_exp(&ch);
   }
    return 0;
}
