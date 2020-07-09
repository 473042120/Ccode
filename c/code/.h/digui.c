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
  if(l==h)  return a[l];
  int m,x,y;
  m=(l+h)/2;
  x=max (a,l,m);
  y=max (a,m+1,h);
  if(x>y)
      return x;
  else
      return y;
  
}