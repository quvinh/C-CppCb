#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	char ten[30];
	int maso;
	float d1,d2,d3;
}Data;

typedef struct tagNode
{
	Data infor;
	struct tagNode *next;
	struct tagNode *pre;
}Node;

typedef struct 
{
	Node *pHead;
	Node *pTail;
	int spt;
}DList;

void initL(DList *L)
{
	L->pHead=NULL;
	L->pTail=NULL;
	L->spt=0;
}

int emptyL(DList L)
{
	return(L.spt==0);
}

int fullL(DList L)
{
	return(L.spt==100);
}

void insert_Tail(DList *L, Data x)
{
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->next=NULL;
	pp->pre=NULL;
	if(emptyL(*L))
	{
		L->pHead=pp;
		L->pTail=pp;
	}
	else
	{
		L->pTail->next=pp;
		pp->pre=L->pTail;
		L->pTail=pp;
	}
	L->spt++;
}

void insert_Head(DList *L, Data x)
{
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->next=NULL;
	pp->pre=NULL;
	if(emptyL(*L))
	{
		L->pHead=pp;
		L->pTail=pp;
	}
	else
	{
		L->pHead->pre=pp;
		pp->next=L->pHead;
		L->pHead=pp;
	}
	L->spt++;
}

void insert_After(DList *L, Node *p, Data x)
{
	Node *pp;
	if(pp==NULL) return;
	else
	{
		pp=(Node*)malloc(sizeof(Node));
		pp->infor=x;
		pp->next=p->next;
		p->next->pre=pp;
		p->next=pp;
		pp->pre=p;
	}
}

void del_Head(DList *L)
{
	
	if(emptyL(*L))
	{
		return;
	}	
	else
	{
		Node *pp=L->pHead;
		L->pHead->next->pre=NULL;
		L->pHead=L->pHead->next;
		free(pp);
		L->spt--;
		if(L->pHead==NULL)
			L->pTail=NULL;
	}
}

void nhapdl(Data *x)
{
	printf("Nhap ma SV:");
	scanf("%d",&(x->maso));
	if(x->maso==0)
		return;
	printf("Nhap ten SV:");
	fflush(stdin);
	gets(x->ten);
	printf("Nhap Diem 1:");
	scanf("%f",&(x->d1));
	printf("Nhap Diem 2:");
	scanf("%f",&(x->d2));
	printf("Nhap Diem 3:");
	scanf("%f",&(x->d3));
}

void indl(Data x)
{
	printf("\n|_Ten: %s  |_Ma SV: %d  |_Diem 1: %.2f  |_Diem 2: %.2f   |_Diem 3: %.2f|",x.ten,x.maso,x.d1,x.d2,x.d3);
}

void FIFO(DList *L)
{
	Data x;
	initL(L);
	do
	{
		nhapdl(&x);
		if(x.maso!=0)
			insert_Tail(L,x);
	}while(x.maso!=0);
	return;
}

void LIFO(DList *L)
{
	Data x;
	initL(L);
	do
	{
		nhapdl(&x);
		if(x.maso!=0)
			insert_Head(L,x);
	}while(x.maso!=0);
	return;
}

void travel(DList L)
{
	Node *pp=L.pHead;
	printf("_So SV: %d",L.spt);
	while(L.pTail!=NULL)
	{
		indl(pp->infor);
		pp=pp->next;
//		L.pHead=L.pHead->next;
//		L.pTail=L.pTail->pre;
	}
}

int main()
{
	DList L;
	Data x;
	FIFO(&L);
	travel(L);
//	nhapdl(&x);
//	insert_Head(&L,x);
//	travel(L);
	return 0;
}

