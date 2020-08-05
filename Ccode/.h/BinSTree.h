#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct 
{
	int key;
}DataType;

typedef int KeyType;

typedef struct BinSTreeNode
{
	DataType elem;
	struct BinSTreeNode * lchild;
	struct BinSTreeNode * rchild;
 } *BinSTree;
 
BinSTree BSTreeSearch(BinSTree t,KeyType k)
{
	/*在根指针为t的二叉排序树中查找关键字为k的结点，
	若查找成功，则返回指向该结点的指针；否则返回空指针*/
	if(t==NULL)return NULL;
	if(t->elem.key==k)return (t);
	if(t->elem.key>k)
	return BSTreeSearch (t->lchild,k);
	else
	return BSTreeSearch (t->rchild,k);
}

void BSTreeInsert (BinSTree * t,KeyType k)
{
	/*在二叉排序树中插入关键字为k的结点，*t指向二叉排序树的根结点*/ 
	BinSTree r;
	if(* t==NULL)
	{
		r=(BinSTree)malloc(sizeof(struct BinSTreeNode));
		r->elem.key=k; r->lchild=r->rchild=NULL;
		*t=r;
		return ;
	}
	else
	    if(k<((*t)->elem.key))
	      BSTreeInsert(&((*t)->lchild),k);
	    else
	      BSTreeInsert(&((*t)->rchild),k);
}

int BSTreeDelete (BinSTree * bt,KeyType k)
{
	/*在二叉树中删除关键字为k的结点，*bt 指向二叉排序树的根结点；
	删除成功返回1，不成功返回0*/
	BinSTree f,p,q,s;
	p=*bt; f=NULL;
	while(p&&p->elem.key!=k)
	{
		f=q;
		if(p->elem.key>k)p=p->lchild;
		else p=p->rchild;
	 }
	 if (p==NULL)return (0);
	 if(p->lchild==NULL)
	 {
	 	if(f==NULL)
	 	   *bt=p->rchild;
	 	else if(f->lchild==p)
	 	      f->lchild=p->rchild;
	 	      else f->rchild=p->rchild;
	 	free(p);
	 }
	 else
	 {
	 	q=p;s=p->lchild;
		while (s->rchild)
		{
			q=s;
			s=s->rchild;
		 } 
		 if(q==p)
		 q->lchild=s->lchild;
		 else q->rchild=s->lchild;
		 p->elem.key=s->elem.key;
		 free(s);
		 return (1);
	 }
}
































