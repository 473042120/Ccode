#include ".h/栈中缀表达式.h"

int main()
{   
    char a[30]="7*(8+2)*9+9*7#";
    char b[30]=" ";
    char *p=a;
    char *q=b;
    //scanf("%s",p);
    infix_exp_value(p,q);
    while(*q!='\0')
    printf("%c",*q++);
    printf("\n");
}