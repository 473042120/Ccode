#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxVertexNum 30 //最大顶点数

typedef struct{
//顶点表的类型
}VertexType;

typedef struct{
//邻接矩阵，既边表
}Edgetype;

typedef struct{
    VertexType vertexs[MaxVertexNum];
    Edgetype   arcs[MaxVertexNum][MaxVertexNum];
    int VertexNum,edgeNum;
}MGragh;

void CreatGraph(MGragh * G)
{
    int i,j,k,w;
    scanf("%d,%d",&(G->VertexNum),&(G->edgeNum));
}