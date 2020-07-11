#include "SeqQueue.h"

void Array_LeftCircle_Move(int A[],int n,int k)//n代表数组中存储的元素个数，k代表循环左移动k位
{  
    int i;
    PSeqQueue Q=Init_SeqQueue();
    for(i=0;i<k;i++) In_SeqQueue(Q,A[i]);
    for(i=k;i<n;i++) A[i-k]=A[i];
    i=n-k;
    while(!Empty_SeqQueue(Q))
    {
        Out_SeqQueue(Q,&A[i]);
        ++i;
    }
}

//队列实现打印杨辉三角

void YangHui_trangle(int n)
{
    int s=0;
    int i;
    PSeqQueue sq=Init_SeqQueue();
    In_SeqQueue(sq,1);
    In_SeqQueue(sq,1);
    for(i=1;i<=n;i++,sq=0)
    {  
        printf("\n");
        for(int k=0;k<40-4*i;k+=2) printf(" ");
        In_SeqQueue(sq,0);
        for(int j=1;j<=i+2;j++)
        {
            int t;
            Out_SeqQueue(sq,0);
            In_SeqQueue(sq,s+t);
            s=t;
            if(j!=i+2) printf("%4d",s);
        }
    }
    printf("\n");
    Destroy_SeqQueue(&sq);
}