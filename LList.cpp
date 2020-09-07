#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct{
	char ten [30];
	int masv;
	float d1,d2,d3;
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

void delHead(LList*L){
	Node*pp=L->pHead;
	if(emptyList(*L)){
		return;
	}
	else{
		L->pHead=pp->link;
		free(pp);
		L->spt--;
		if(L->pHead==NULL){
			L->pTail=NULL;
		}
	}
}

void delAfter(LList*L,Node*q){
	Node *pp;
	if(q==NULL){
		return ;
	}
	else{
		pp=q->link;
		q->link=pp->link;
		free(pp);
		L->spt--;
		if(NULL==L->pTail) L->pTail=q;
	}
}

void delK(LList *L,char K[30]){
	Node*pp=L->pHead,*q;
	while(pp!=NULL,strstr(pp->infor.ten,K)!=0){
		q=pp;
		pp=pp->link;
	}
	if(NULL==pp) return ;
	else{
		if(pp==L->pHead){
			delHead(L);
		}
		else delAfter(L,q);
	}
}
//////////////////////////////////////////////////////////////////////////
void nhapdl(Data *x){
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
void indl(Data x){
	printf("\nTen:%s Ma SV:%d D1:%.2f D2:%.2f D3:%.2f",x.ten,x.masv,x.d1,x.d2,x.d3);

}
//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////
void travel(LList L){
	printf("So sinh vien :%d\n",L.spt);

	while(L.pHead!=NULL){
		indl(L.pHead->infor);
		L.pHead=L.pHead->link;
	}
}

main(){
	LList L;
	FIFO(&L);
//	char tt[30];
//	travel(L);
//	
//	printf("\nBan muon xoa Sv co ten:");
//	fflush(stdin);
//	gets(tt);
//	delK(&L,tt);
//	printf("\nD/S:\n");
//	delHead(&L);
	travel(L);
	return 0;
}

