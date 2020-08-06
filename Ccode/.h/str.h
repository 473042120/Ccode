/*
动态堆存储
c语言中是通过malloc，realloc，free等函数实现对堆的使用
串的堆式存储，一般仍是以一组地址连续的存储单元存放字符串，
但串的空间是在程序运行中动态获取的，在使用结束后，归还堆
*/
#include<stdio.h> 
#include<stdlib.h>
#include<malloc.h>

typedef struct{
    char *p_ch;
    int length;
}Hstring;

int StrAssign(Hstring*s1,char*s2)
{/*将一个字符串常量的值赋值给一个字符串变量*/
    int i;char *pc;
    if(s1->p_ch)free(s1->p_ch);
    for(i=0,pc=s2;*pc!='\0';i++,pc++);
    if(i==0)
    {
        s1->p_ch=0;s1->length=0;
        return 0;
    }
    if(!(s1->p_ch=(char *)malloc(i*sizeof(char))))
    {
        printf("堆空间不足，赋值失败！\n");
        return 0;
    }
    for(int j=0;j<i;j++) s1->p_ch[j]=s2[j];
    s1->length=i;
    return 1;
}