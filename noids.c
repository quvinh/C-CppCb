#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	char ten[30];
	int masv;
	float d1,d2,d3;
}Data;

typedef struct tagNode
{
	Data infor;
	struct tagNode *link;
}Node;

typedef struct
{
	Node *pHead;
	Node *pTail;
	int spt;
}LList;

void initL(LList *L)
{
	L->pHead=NULL;
	L->pTail=NULL;
	L->spt=0;
}

int emptyL(LList L)
{
	return(L.spt==0);
}

int fullL(LList L)
{
	return(L.spt==1000);
}

void nhapdl(Data *x)
{
	printf("Nhap ma sinh vien:");
	scanf("%d",&(x->masv));
	if(x->masv==0)
		return;
	printf("Nhap ten sinh vien:");
	fflush(stdin);
	gets(x->ten);
	
	printf("Nhap diem mon 1:");
	scanf("%f",&(x->d1));
	printf("Nhap diem mon 2:");
	scanf("%f",&(x->d2));
	printf("Nhap diem mon 3:");
	scanf("%f",&(x->d3));
}

void indl(Data x)
{
	printf("\nTen:%s Ma SV:%d D1:%.2f D2:%.2f D3:%.2f",x.ten,x.masv,x.d1,x.d2,x.d3);
}

void insert_Head(LList *L,Data x)
{
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=L->pHead;
	if(emptyL(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else {
		L->pHead=pp;
	}
	L->spt++;
}

void insert_After(LList *L,Node *p,Data x)
{
	Node *pp;
	if(p!=NULL)
	{
		pp=(Node*)malloc(sizeof(Node));
		pp->infor=x;
		pp->link=p->link;
		p->link=pp;
		if(p==L->pTail)
			L->pTail==pp;
		L->spt++;
	}
	
}

void LIFO(LList *L)
{
	Data x;
	initL(L);
	do{
	nhapdl(&x);
	if(x.masv!=0)
		insert_Head(L,x);

	}while(x.masv!=0);
	return;
}

void travel(LList L)
{
	printf("\nSo sinh vien :%d",L.spt);
	while(L.pHead!=NULL){
		indl(L.pHead->infor);
		L.pHead=L.pHead->link;
	}
}

void noi_ds(LList *L1, LList L2)
{
	printf("\nhello");

	if(emptyL(L2)) return;
	else
	{
		L1->pTail=L2.pHead;
		L1->pTail->link=L2.pHead;
		L1->spt+=L2.spt;
	}
}

void insertL_maso(LList *L, Data x)
{
	Node *pp,*p,*q;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=NULL;
	if(emptyL(*L))
	{
		L->pHead=pp;
		L->pTail=pp;
	}
	else
	{
		q=L->pHead;
		while(q->infor.masv > x.masv && q!=NULL)
		{
			p=q;
			q=q->link;
		}
		if(q==L->pHead)
			insert_Head(L,x);
		else
			insert_After(L,p,x);
	}
}

main()
{
	LList L1;
	Data x;
	

	LList L2;
	LIFO(&L1);
//	LIFO(&L2);
	travel(L1);
//	travel(L2);
	
	printf("\nNhap thong tin can chen: \n");
	do
	{
		printf("Nhap ma so:");
		scanf("%d",&x.masv);
	}while(x.masv<0);
	printf("Nhap ten: ");
	fflush(stdin);
	gets(x.ten);
	printf("Nhap Diem 1:");
	scanf("%f",&x.d1);
	printf("Nhap Diem 2:");
	scanf("%f",&x.d2);
	printf("Nhap Diem 3:");
	scanf("%f",&x.d3);
	

	insertL_maso(&L1,x);
//	noi_ds(&L1,L2);
	travel(L1);
	
	
}

