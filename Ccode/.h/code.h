#include<stdio.h>

void  quyu(int a,int b)//a对b取余
{
     int c;
     c=a%b;
     printf("%d\n",c);
}

void f (int n[])//函数传递的形式测试
{
   n[1]=1;
   n[2]=2;
//    int n[3];
//    f(n);
//    printf("%d,%d\n",n[1],n[2]);
}