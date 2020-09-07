#include<stdio.h>
#include<stdlib.h>
void init(int a[], int n)
{
	printf("Mang ban dau:");
	srand(time(NULL));
	int i;
	for(i=0;i<n;i++)
	{
		a[i] = rand()%100;
		printf("%5d",a[i]);
	}
}

void sort(int a[], int n)
{
	int i,j, tg;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i] > a[j])
			{
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	printf("\nMang sap xep:");
	for(i = 0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
}

int search_binary(int a[], int n, int x)
{
	int L, R, m;
	L = 0;
	R = n-1;
	while(L<=R)
	{
		m = (L+R)/2;
		if(x == a[m]) return m;
		else
		{
			if(x>a[m]) L = m+1;
			else R = m-1;
		}
	}
	return -1;
}

int main()
{
	int a[100], x, n;
	printf("Nhap so phan tu:");scanf("%d",&n);
	init(a,n);
	sort(a,n);
	printf("\nNhap so can tim:");scanf("%d",&x);
	printf("vi tri thu: %d",search_binary(a,n,x)+1);
	return 0;
}
