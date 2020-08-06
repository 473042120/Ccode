#include <stdio.h> //约瑟夫问题  顺序表解决问题
#include <malloc.h>
#include ".h/SeqList.h"
#define MAXSIZE 100
typedef int DataType;

int josephus_SeqList(PSeqList josephus_Seq, int s, int m)
{//入口：已经存放数据的顺序表，起始序号s，计数值m
 //出口：1成功0失败
    int s1, i, w;
    if (!josephus_Seq->length)
    {
        printf("表中无元素");
        return (0);
    }
    s1 = s - 1;
    printf("输出约瑟夫序列：");
    for (i = josephus_Seq->length; i > 0; i--)
    {
        s1 = (s1 + m - 1) % i;
        w = josephus_Seq->data[s1];
        if (i % 5 == 0)  printf("\n");
        printf("%d\t", w);
        Delete_SeqList(josephus_Seq, s1 + 1);
    }
    return (1);
}

int main()
{
    int i;
    PSeqList PL;
    PL = (SeqList*)malloc(sizeof(PSeqList));
    //SeqList*可以替换成PSeqList
    PL = zidongfuzhi(PL);
    josephus_SeqList(PL, 2, 5);
}
