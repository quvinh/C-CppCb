#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char ten [30];
	int masv;
	float d1;
}Data;

typedef struct tagNode{
	Data infor ;
	struct tagNode *link;
}Node;

typedef struct {
	Node *pHead;
	Node *pTail;
	int spt;
}LList;

void initL(LList *L){
	L->pHead=NULL;
	L->pTail=NULL;
	L->spt=0;
}

int emptyList(LList L){
	return (L.spt==0);
}

int fullList(LList L){
	return (L.spt==1000);
}

void insert_Head(LList *L,Data x){
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=L->pHead;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else {
		L->pHead=pp;
	}
	L->spt++;
}

void insert_Tail(LList *L,Data x){
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=NULL;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else {
		L->pTail->link=pp;
		L->pTail=pp;
	}
	L->spt++;
}

void insert_Atfer(LList *L,Node *q,Data x){
	Node *pp;
	if(q!=NULL){
		pp=(Node*)malloc(sizeof(Node));
		pp->infor=x;
		pp->link=q->link;
		q->link=pp;
		if(q==L->pTail)
			L->pTail=pp;
		L->spt++;
	}
}

void nhapdl(Data *x){
	printf("Nhap ma sinh vien:");
	scanf("%d",&(x->masv));
	if(x->masv==0)
		return;
	printf("Nhap ten sinh vien:");
	fflush(stdin);
	gets(x->ten);
	
	printf("Nhap diem:");
	scanf("%f",&(x->d1));
}
void indl(Data x){
	printf("\nTen:%s Ma SV:%d Diem:%.2f",x.ten,x.masv,x.d1);
}

void Swap(Data &a, Data &b)
{
	Data temp = a;
	a = b;
	b = temp;
}

Node *truoc(LList L, Node *pp)
{
	Node *q = L.pHead;
	if(pp == q) return NULL;
	while(q->link != pp)
	{
		q = q->link;
	}
	return q;
}

void bubble_sort(LList L)
{
	Node *i, *j;
	for(i=L.pHead; i!=NULL; i=i->link)
	{
		for(j=L.pTail; j!=i; j=truoc(L, j))
		{
			if(strcmp(j->infor.ten, truoc(L, j)->infor.ten)<0 ||
			 (strcmp(j->infor.ten, truoc(L, j)->infor.ten)==0 && j->infor.masv < truoc(L, j)->infor.masv))
				Swap(j->infor, truoc(L,j)->infor);
		}
	}
}

void selection_sort(LList L)
{
	Node *vt, *i, *j;
	for(i=L.pHead; i->link!=NULL; i=i->link)
	{
		vt=i;
		for(j=i->link; j!=NULL; j=j->link)
		{
			if(strcmp(j->infor.ten, vt->infor.ten)<0 ||
			 (strcmp(j->infor.ten, vt->infor.ten)==0 && j->infor.masv < vt->infor.masv))
				vt=j;
		}
			
		if(vt!=j)
			Swap(j->infor, vt->infor);
	}
}

void interchange_sort(LList L)
{
	Node *i, *j;
	for(i=L.pHead; i->link!=NULL; i=i->link)
	{
		for(j=i->link; j!=NULL; j=j->link)
		{
			if(strcmp(i->infor.ten, j->infor.ten)<0 ||
			 (strcmp(i->infor.ten, j->infor.ten)==0 && i->infor.masv < j->infor.masv))
				Swap(i->infor, j->infor);
		}
	}
}

void insertion_sort(LList L)
{
	Node *i, *pos;
	Data x;
	for(i=L.pHead->link; i!=NULL; i=i->link)
	{
		x=i->infor;
		pos=i;
	}
	while(pos!=NULL && strcmp(truoc(L,pos)->infor.ten,x.ten)>0||
			 (strcmp(truoc(L, pos)->infor.ten, x.ten)==0 && truoc(L, pos)->infor.masv < x.masv))
	{
		pos->infor=truoc(L,pos)->infor;
		pos=truoc(L,pos);
	}
	pos->infor=x;
}

void LIFO(LList *L){
	Data x;
	initL(L);
	do{
	nhapdl(&x);
	if(x.masv!=0)
		insert_Head(L,x);
	}while(x.masv!=0);
	return;
}
void FIFO(LList*L){
	Data x;
	initL(L);
	do{
	nhapdl(&x);
		if(x.masv!=0)
			insert_Tail(L,x);
	}while(x.masv!=0);
}

void output(LList L){
	printf("So sinh vien :%d\n",L.spt);

	while(L.pHead!=NULL){
		indl(L.pHead->infor);
		L.pHead=L.pHead->link;
	}
}

int main()
{
	LList L;
	FIFO(&L);
	output(L);
	
//	bubble_sort(L);
//	output(L);

	selection_sort(L);
	output(L);

//	interchange_sort(L);
//	output(L);

//	insertion_sort(L);
//	output(L);
	return 0;
}


