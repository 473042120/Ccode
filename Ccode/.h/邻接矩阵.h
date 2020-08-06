#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxVertexNum 30 //最大顶点数

typedef int
//顶点表的类型
VertexType;

typedef 
//邻接矩阵，既边表
int Edgetype;

typedef struct{
    VertexType vertexs[MaxVertexNum];
    Edgetype   arcs[MaxVertexNum][MaxVertexNum];
    int VertexNum,edgeNum;
}MGragh;

void CreatGraph(MGragh * G)
{
    int i,j,k,w;
    scanf("%d,%d",&(G->VertexNum),&(G->edgeNum));
    for(i=0;i<G->VertexNum;i++)    
    scanf("%c",&(G->vertexs[i]));
    for(i=0;i<G->VertexNum;i++)  
    for(j=0;j<G->VertexNum;i++)
    G->arcs[i][j]=0;
    for(k=0;k<G->edgeNum;k++)
    {
        scanf("%d,%d",&i,&j);
        G->arcs[i][j];
    }
}
