#include <stdio.h>

int jieji (int n)
{
    if (n==0)
    return 1;
    else 
    return (n*jieji(n-1));
}

