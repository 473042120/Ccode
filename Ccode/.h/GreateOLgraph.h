#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxVertexNum 30

typedef int InfoType;
typedef int VertexType;
int LocateVertex (OLGraph * G,int v)
{
    /*确定v1和v2在G中位值*/
}

typedef struct ArcNode{
    int tailvertex,headvertex;
    struct ArcNode *hlink,*tlink;
    InfoType info;
}ArcNode;

typedef struct VertexNode{
    VertexType vertex;
    ArcNode*firstin,*firstout;
}VertexNode;

typedef struct{
    VertexNode xlist[MaxVertexNum];
    int vertexNum,edgeNum;
}OLGraph;

void CreateOLgraph(OLGraph * G)
{
    int i,k;
    scanf("%d,%d",&(G->vertexNum),&(G->edgeNum));
    /*读入顶点数和弧度*/
    for(i=0;i<G->vertexNum;i++)
    {
        scanf("%d",&(G->xlist[i].firstout=NULL));
        G->xlist[i].firstin =NULL;G->xlist[i].firstout=NULL;
    }
    for(k=0;k<G->edgeNum ;k++)
    {   int i,j,v1,v2;
        ArcNode *p;
        scanf("%d,%d",&v1,&v2);
        i=LocateVertex(G,v1);
        j=LocateVertex(G,v2); /*确定v1和v2在G中位值*/
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->tailvertex=i;p->headvertex=j;
        p->tlink=G->xlist[i].firstout;G->xlist[i].firstout=p;
        p->hlink=G->xlist[j].firstin;G->xlist[j].firstin=p;
    }
}