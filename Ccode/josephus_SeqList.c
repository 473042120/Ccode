#include ".h/SeqList.h"//约瑟夫问题  顺序表解决问题
#include".h/LinkList.h"
typedef int DataType;

int josephus_SeqList(PSeqList josephus_Seq, int s, int m)
{//入口：已经存放数据的顺序表，起始序号s，计数值m
 //出口：1成功0失败
 //约瑟夫问题是从s开始每隔m个
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
        if (i % 5 == 0)  printf("\n");
        w = josephus_Seq->data[s1];
        printf("%d\t", w);
        s1 = (s1 + m - 1) % i;
        Delete_SeqList(josephus_Seq, s1 + 1);
    }
    return (1);
}

int josephus_LinkList (LinkList josephus_Link ,int s,int m)
{
  LinkList p,pre;
  int count;
  if(!josephus_Link)
  {
    printf("表中无元素");
    return 0;
  }
  p=josephus_Link;
  for(count=1;count<s;count++)
  p=p->next;
  printf("输出约瑟夫序列");
  while(p!=p->next)
  {
      pre=p->next;
      while(pre->next!=p) pre=pre->next;
      for(count=1;count<m;count++){
          pre=p;
          p=p->next;
      }
      printf("%d\t",p->data);
      pre->next=p->next;
      free(p);
      p=pre->next;
  }
  printf("%d\t",p->data);
  free(p);
  return 1;
}

int main()
{
    int i;
    PSeqList PL;
    PL=Init_SeqList();
    fuzhi(PL);
    josephus_SeqList(PL, 0, 5);
}
