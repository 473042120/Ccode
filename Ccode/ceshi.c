#include<stdio.h>
 int main ()
 {
 	int a[3][4],i,j,n,max=0,m;
 	for(i=0;i<3;i++)
 	for(j=0;j<4;j++)
 	{
 		scanf("%d",&a[i][j]);
 		if(max<a[i][j])
 		{
 			max=a[i][j];
 			m=i;n=j;
		 }
	 }
	for(i=0;i<3;i++)
 	{
	 for(j=0;j<4;j++)
 	printf("%d ",a[i][j]);
 	printf("\n");
	 }
	 
	 printf("\nmax=a[%d][%d]=%d\n",m+1,n+1,a[m][n]);
     return 0;
  } 