#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define N 20
#define MaxTreeNodeNum 100

typedef int DataType;
typedef struct {
	char ch;
	DataType weight;
	int lchild,rchild,parent;
}Htnode; 

void Visit(int t)
{printf("%d",t);}

char getch()
{   
	int a;
	scanf("%c",&a);
	return a;
}

typedef struct {
	char *code;
	char leaf;
	int length;
}CodeType;

void Select (Htnode * H ,int n,int * s1,int * s2)
{
	/*对数组huftree[1..n+i-1]中无双亲的结点权值进行排序，s1,s2
		将是无双亲且权重最小的两个结点下标*/;
}

void HuFcoding(Htnode huftree[],CodeType cd[],int w[],int n)
{
	/*静态链表huftrre中，w存放结点权重，
	n是叶子个数，最后的编码放在cd[] */
	int i,j,k,s1,s2,s,m,f,c,sum;
	char temp[N];
	m=2*n-1;
	for(i=1;i<n;i++)
	{
		huftree[i].weight=w[i-1];
		huftree[i].lchild=huftree[i].rchild=
		huftree[i].parent=-1;
		huftree[i].ch=getch();
	}
	for(i=n+1;i<m;i++)
	{
		huftree[i].weight=-1;
		huftree[i].lchild=huftree[i].rchild=
		huftree[i].parent=-1;
	}
	for(i=1;i<n-1;i++)
	{
	    Select(huftree,n+i-1,&s1,&s2);
		/*对数组huftree[1..n+i-1]中无双亲的结点权值进行排序，s1,s2
		将是无双亲且权重最小的两个结点下标*/
		sum=huftree[s1].weight+huftree[s2].weight;
		huftree[n+i].weight=sum;
		huftree[s1].parent=huftree[s2].parent=n+i;
		huftree[n+i].lchild=s1;huftree[n+i].rchild=s2;
	}
	for(i=1;i<n;i++)
	{
		c=0;
		for(k=i,f=huftree[i].parent;f!=-1;k=f,f=huftree[f].parent)
		if(huftree[f].lchild==k)
		{
			temp[c]='0';
			c++;
		}
		else
		{
			temp[c]='1';
			c++;
		}
		cd[i].code=(char *)malloc(c+1);
		/*产生存储编码的空间*/
		cd[i].code[c]='\0';
		c--;
		k=0;
		while(c>=0)
		cd[i].code[k++]=temp[c--];
		cd[i].leaf=huftree[i].ch;
		cd[i].length=k;
	}
 } 