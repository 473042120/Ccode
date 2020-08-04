#include<stdio.h>
#define N 20

typedef int DataType;
typedef struct {
	char ch;
	DataType weight;
	int lchild ,rchild,parent;
}Htnode; 

typedef struct {
	char *code;
	char leaf;
	int length;
}CodeType;

void HuFcoding(Htnode hufftree[],CodeType cd[],int w[],int n)
{
	/*静态链表huftrre中，w存放结点权重，
	n是叶子个数，最后的编码放在cd[] */
	int i,j,k,s1,s2,s,m,f,c,sum;
	char temp[N];
	m=2*n-1;
	for(i=1;i<n;i++)
	{
		huftree[i].weight=w[i-1];
	}
 } 