#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char ten[30];
	int masv;
}data;

typedef struct tagNode
{
	data infor;
	struct tagNode *link;
}Node;

typedef struct 
{
	Node *pH;
	Node *pT;
	int spt;
}List;

void initL(List *L)
{
	L->pH = NULL;
	L->pT = NULL;
	L->spt = 0;
}

int emptyL(List L)
{
	return(L.spt == 0);
}

void insertTail(List *L, data x)
{
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	pp->infor=x;
	if(emptyL(*L))
	{
		L->pH = pp;
		L->pT = pp;
	}
	else
	{
		L->pT->link = pp;
		L->pT = pp;
	}
	L->spt++;
}

Node *Sbinary(List L, char n[30])
{
	Node *i;
	for(i = L.pH; i!=NULL; i = i->link)
	{
		if(strcmp(n, i->infor.ten)==0)
			return i;
	}
}

void nhapdl(data *x)
{
	printf("Nhap ma sinh vien:");
	scanf("%d",&(x->masv));
	if(x->masv==0)
		return;
	printf("Nhap ten sinh vien:");
	fflush(stdin);
	gets(x->ten);
}

void indl(data x)
{
	printf("\nTen:%s Ma SV:%d",x.ten,x.masv);
}

void FIFO(List *L)
{
	data x;
	initL(L);
	do
	{
		nhapdl(&x);
		if(x.masv !=0)
			insertTail(L, x);
	}while(x.masv != 0);
}

void outp(List L){
	printf("So sinh vien :%d\n",L.spt);
	while(L.pH != NULL)
	{
		indl(L.pH->infor);
		L.pH = L.pH->link;
	}
}

int main()
{
	List L;
	FIFO(&L);
	outp(L);
	
	char tt[30];
    fflush(stdin);
    gets(tt);
	Node *q;
	q = Sbinary(L, tt);
	indl(q->infor);
	return 0;
}








