#include<stdio.h>
#include<algorithm>

typedef struct
{
	char ten[30];
	int masv;
	float d1;
}Data;

typedef struct tagNode
{
	Data infor;
	struct tagNode *l, *r;
}Node;

typedef Node *BSTree;

void initBSTree(BSTree *T)
{
	*T = NULL;
}

void InsertNode(BSTree *T, Data x)
{
	if((*T)==NULL)
	{
		(*T) = (Node*)malloc(sizeof(Node));
		(*T)->infor = x;
		(*T)->l = NULL;
		(*T)->r = NULL;
	}
	else
	{
		if((*T)->infor.masv < x.masv)//inset
			InsertNode(&(*T)->r, x);
		else
			if((*T)->infor.masv > x.masv)
				InsertNode(&(*T)->l, x);
			else return;
	}
}

void searchStandFor(BSTree &pp, BSTree &q)
{
	if(q->l)
		searchStandFor(pp, q->l);
	else
	{
		pp->infor = q->infor;
		pp = q;
		q = q->r;
	}
}

int delNode(BSTree &T, Data x)
{
	if(T==NULL) return 0;
	if(T->infor.masv > x.masv) return delNode(T->l, x);
	if(T->infor.masv < x.masv) return delNode(T->r, x);
	
	Node *p = T;
	if(T->l == NULL)
		T = T->r;
	else
	{
		if(T->r == NULL)
			T = T->l;
		else
			searchStandFor(p, T->r);
	}
	delete p;
}

bool find(BSTree &T, Data x)
{
	if(T == NULL) return false;
	if(T->infor.masv == x.masv)
		return true;
	if(T->infor.masv > x.masv)
		find(T->l, x);
	if(T->infor.masv < x.masv)
		find(T->r, x);
}

void nhap(Data *x)
{
	printf("Nhap masv:"); scanf("%d",&x->masv);
	if(x->masv>0)
	{
		printf("Nhap ten SV:");
		fflush(stdin);
		gets(x->ten);
		printf("Nhap Diem 1:"); scanf("%f",&x->d1);		
	}
}

void in(Data x)
{
	printf("Ten:%s\tMasv:%d\tDiem1:%.2f\n",x.ten,x.masv,x.d1);
}

void CreateTree(BSTree &T)
{
	Data x;
	initBSTree(&T);
	do
	{
		nhap(&x);
		if(x.masv!=0)
			InsertNode(&T, x);
	}while(x.masv!=0);
}

void PreOrder(BSTree T)//NLR
{
	if(T!=NULL)
	{
		in(T->infor);
		PreOrder(T->l);
		PreOrder(T->r);
	}
}

void InOrder(BSTree T)
{
	if(T!=NULL)
	{
		InOrder(T->l);
		in(T->infor);
		InOrder(T->r);
	}
}

void PostOrder(BSTree T)//LRN
{
	if(T!=NULL)
	{
		PostOrder(T->l);
		PostOrder(T->r);
		in(T->infor);
	}
}

int main()
{
	BSTree T;
	CreateTree(T);
	Data x;
	printf("*NLR\n");
	PreOrder(T);
	
//	printf("Nhap data x:\n");
//	printf("Nhap masv can xoa:");scanf("%d",&x.masv);
//	delNode(T, x);
	printf("*LNR\n");
	InOrder(T);
	printf("*LRN\n");
	PostOrder(T);
//	printf("Nhap masv can tim:");scanf("%d",&x.masv);
//	find(T, x);
	return 0;
}







