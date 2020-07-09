#include <stdio.h>

int jieji (int n)
{
    if (n==0)
    return 1;
    else 
    return (n*jieji(n-1));
}

int max (int a[],int l,int h)
{
    int m,x,y;
    if (l=h)
    return a[1];
    m=(1+h)/2;
    x=max(a,1,m);
    y=max(a,m+1,h);
    if(x>y)
    return x;
    else 
    return y;
}
