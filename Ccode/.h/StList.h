#include<stdio.h>//静态链表
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int DataType;

typedef struct {
    DataType data; //元素
    int next;
}SNode;

typedef struct {   //定义静态链表
    SNode sp[MAXSIZE];
    int SL;
}StList,*PStList;