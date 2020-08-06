#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STRINGSIZE 80

typedef struct chuan{
    char data [STRINGSIZE];
    struct chuan *next;
}LinkString;

typedef struct {
    LinkString *head, *tail;
    int curlen;
}LString;