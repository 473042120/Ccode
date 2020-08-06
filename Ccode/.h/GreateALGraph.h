#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxVertexNum 30

typedef int InfoType;
typedef int VertexType;

typedef struct node{
    int adjvertex;
    InfoType info;
    struct node *next;
}EdgeNode;

typedef struct vnode{
    VertexType vertex;
    EdgeNode* firstedge;
}VertexNode;

typedef struct {
    VertexNode adjlist[MaxVertexNum];
    int vertexNum,edgeNum;
}ALGraph;

void CreateALGraph(ALGraph*G)
{
    int i,j,k;
    EdgeNode*p;
    scanf("%d,%d",&(G->vertexNum),&(G->edgeNum));
    for(i=0;i<G->vertexNum;i++)
    {
        scanf("%c",&(G->adjlist[i].vertex));
        G->adjlist[i].firstedge=NULL;
    }
    for(k=0;k<G->edgeNum;k++)
    {
        scanf("%d,%d",&i,&j);
        p=(EdgeNode*)malloc(sizeof(EdgeNode));
        p->adjvertex=j;
        p->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=p;
    }
}