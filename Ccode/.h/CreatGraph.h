#include<stdio.h>
#define MaxVertexNum 30

typedef int VertexType;
typedef int Edgetype ;

typedef struct 
{
  VertexType vertxes[MaxVertexNum];//顶点表
  Edgetype arcs [MaxVertexNum][MaxVertexNum];
  int vertexNum,edgeNum;
}MGragh;

void CreatGraph(MGragh* G)
{
    int i,j,k,w;
    scanf("%d,%d",&(G->vertexNum),&(G->edgeNum));
    for(i=0;i<G->vertexNum;i++)
    scanf("%c",&(G->vertxes[i]));
    for(i=0;i<G->vertexNum;i++)
    for(j=0;j<G->vertexNum;j++)
    G->arcs[i][j]=0;
    for(k=0;k<G->edgeNum;k++)
    {
        scanf("%d,%d",&i,&j);
        G->arcs[i][j]=1;
    }
}
