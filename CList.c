#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char ten[30];
	int ma;
	float d1,d2,d3;
}Data;

typedef struct tagNode
{
	Data infor;
	struct tagNode *link;
}Node;

typedef struct 
{
	Node *pH;
	Node *pT;
	int spt;
}CList;

void initL(CList *L)
{
	L->pH=NULL;
	L->pT=NULL;
	L->spt=0;
}

int emptyL(CList L)
{
	return(L.spt==0);
}

int fullL(CList L)
{
	return(L.spt==100);
}

void nhapdl(Data *x)
{
	printf("Nhap ma: "); scanf("%d", &(x->ma));
	if(x->ma == 0)
	{
		return;
	}
	printf("Nhap ten :");
	fflush(stdin);
	gets(x->ten);
	printf("Nhap Diem 1:"); scanf("%f",&(x->d1));
	printf("Nhap Diem 2:"); scanf("%f",&(x->d2));
	printf("Nhap Diem 3:"); scanf("%f",&(x->d3));
}

void indl(Data x)
{
	printf("\n |Ten: %s  Ma_so: %d  Diem1: %.2f  Diem2: %.2f  Diem3: %.2f ",x.ten,x.ma,x.d1,x.d2,x.d3);
}

void insertHead(CList *L, Data x)
{
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=L->pH;
	if(emptyL(*L))
	{
		L->pH=pp;
		L->pT=pp;
	}
	else
	{
		pp->link = L->pH;
		L->pH = pp;
	}
	L->pT->link=L->pH;
	L->spt++;
}

void insertTail(CList *L, Data x)
{
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=L->pT;
	if(emptyL(*L))
	{
		L->pH=pp;
		L->pT=pp;
	}
	else
	{
		L->pT->link = pp;
		L->pT = pp;
	}
	L->pT->link=L->pH;
	L->spt++;
}

void insertAfter(CList *L, Node *q, Data x)
{
	Node *pp;
	if(q!=NULL)
	{
		pp=(Node*)malloc(sizeof(Node));
		pp->infor=x;
		pp->link=q->link;
		q->link=pp;
		if(q==L->pT)
		{
			L->pT=pp;
			
		}
		L->spt++;
	}
}

void delHead(CList *L)
{
	if(!emptyL(*L))
	{
		Node *pp=L->pH;
		L->pH = L->pH->link;
		free(pp);
	}
	L->pT->link = L->pH;
	L->spt--;
}

void delTail(CList *L)
{
	if(!emptyL(*L))
	{
		Node *q = L->pH;
		Node *pp;
		pp = (Node*)malloc(sizeof(Node));
		while(q->link != L->pT) q = q->link;
		pp = q;
		q = q->link;
		L->pT = pp;
		L->pT->link = NULL;
		free(q);
	}
	L->pT->link = L->pH;
	L->spt--;
}

void delAfter(CList *L, Node *q)
{
	Node *pp;
	if(q==NULL)
		return;
	else
	{
		pp=q->link;
		q->link=pp->link;
		free(pp);
		if(L->pT == NULL) L->pT = q;
	}
	L->spt--;
}

void delK(CList *L, char K[30])
{
	Node *pp = L->pH, *q;
	while(strcmp(pp->infor.ten, K)!=0)
	{
		q = pp;
		pp = pp->link;
	}

	if(pp == L->pH)
		delHead(L);
	else
		delAfter(L, q);
}

void find(CList *L, int x)
{
	Node *pp = L->pH, *q;
	while(x != pp->infor.ma)
	{
		pp = pp->link;
		q = pp;	
	}
	indl(q->infor);
}

void LIFO(CList *L)
{
	Data x;
	initL(L);
	do
	{
		nhapdl(&x);
		if(x.ma != 0)
			insertHead(L,x);
	}while(x.ma != 0);
}

void FIFO(CList *L)
{
	Data x;
	initL(L);
	do
	{
		nhapdl(&x);
		if(x.ma != 0)
			insertTail(L,x);
	}while(x.ma != 0);
}

void output(CList L)
{
	printf("\nSo sinh vien :%d\n",L.spt);
	Node *pp = L.pH;
	do
	{
		indl(pp->infor);
		pp=pp->link;
	}while(pp != L.pH);
}

int main()
{
	CList L;
	FIFO(&L);
	Data x;
	char tt[30];

	int lc;
	do
	{
		
		printf("  ____________MENU____________\n");
		printf("  | 1. Insert Head           |\n"
			"  | 2. Insert Tail           |\n"
			"  | 3. Insert After          |\n"
			"  | 4. Delete Head           |\n"
			"  | 5. Delete Tail           |\n"
			"  | 6. Delete After          |\n"
			"  | 7. Delete Key_Name       |\n"
			"  | 8. Find_infor            |\n"
			"  | 9. Output                |\n"
			"  | 0. Exit                  |\n"
			"  |__________________________|\n"
			"_Lua chon cua ban: ");
		scanf("%d",&lc);
		
		switch(lc)
		{
			Node *q, *pp;
			int vt,i;
			case 0: break;
			case 1:
				nhapdl(&x);
				insertHead(&L, x);
				break;
			case 2:
				nhapdl(&x);
				insertTail(&L, x);
				break;
			case 3:
				printf("Ban muon chen vao vi tri? "); scanf("%d",&vt);
				printf("_Nhap_\n");
				nhapdl(&x);
				q = L.pH->link;
				for(i=0; i<vt; i++)
				{
					pp = q;
					q = q->link;
				}
				insertAfter(&L, pp, x);
				break;
			case 4:	
				delHead(&L);
				printf(" 'Xoa thanh cong!'\n");
				break;
			case 5:
				delTail(&L);
				printf(" 'Xoa thanh cong!'\n");
				break;
			case 6:
				printf("_Xoa vi tri? "); scanf("%d",&vt);
				q = L.pH->link;
				for(i=0; i<vt; i++)
				{
					pp = q;
					q = q->link;
				}
				delAfter(&L, pp);
				break;
			case 7:
				printf("\n_Xoa Sv co ten: ");
				fflush(stdin);
				gets(tt);
				delK(&L,tt);
				break;
			case 8:
				printf("\n_Tim ma sv: ");
				scanf("%d",&vt);
				if(vt == 1)
					indl(L.pH->infor);
				else
					find(&L, vt);
				printf("\n");
				break;
			case 9:
				output(L);
				printf("\n");
				break;
		}
	}while(lc != 0);

	return 0;
}
