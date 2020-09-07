#include<stdio.h>

void insertion_sort(int a[], int n)
{
	int i, pos, x;
	for(i=1; i<n; i++)
	{
		x=a[i];
		pos=i;
		while(pos>0 && a[pos-1]>x)
		{
			a[pos]=a[pos-1];
			pos--;
		}
		a[pos]=x;
	}
}
int main()
{
	int a[100], n, i;
	printf("Nhap so pt: "); scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		printf("Nhap ptu thu %d :",i);
		scanf("%d", &a[i]);
	}
	printf("Hien thi:\n");
	for(i=0; i<n; i++)
	{
		printf(" %d",a[i]);
	}
	
	printf("\nSort:\n");
	insertion_sort(a,n);
	for(i=0; i<n; i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
