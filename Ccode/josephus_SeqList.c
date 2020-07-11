#include <stdio.h>   //约瑟夫问题
#include <malloc.h>
#include ".h/SeqList.h"
#define MAXSIZE 100

typedef struct {
     int x;
}DdataType;

int josephus_SeqList(PSeqList josephus_Seq,int s, int m)
{
    int s1,i,w;
    if(!josephus_Seq->length)
    {
        printf("表中无元素");
        return(0);
    }
    s1=s-1;
    printf("输出约瑟夫序列：");
    for(i=josephus_Seq->length;i>0;i--)
    {   
        s1=(s1+m-1)%i;
        w=josephus_Seq->data[s1].x;
        if(i%20==0)
        printf("\n");
        printf("%d\t",w);
        Delete_SeqList(josephus_Seq,s1+1);
    }
    return(1);
}

PSeqList zidongfuzhi(PSeqList H)
{   int i;
    H=(PSeqList)malloc(sizeof(PSeqList)*MAXSIZE);
    for(i=0;i<100;i++)
     {   
         H->data[i].x=i;
         H->length++;
     }
     return(H);
}

PSeqList fuzhi(PSeqList H)
{   int i;
    H=(PSeqList)malloc(sizeof(PSeqList)*MAXSIZE);
    for(i=0;i<10;i++)
     {   printf("输入数值");
         scanf("%d",&H->data[i].x);
         H->length++;
     }
     return(H);
}

int main()
{    int i;
     PSeqList PL;
     PL=(PSeqList)malloc(sizeof(PSeqList)*100);
     PL=zidongfuzhi(PL);
     josephus_SeqList(PL,2,5);
}