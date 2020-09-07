#include<stdio.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int a[], int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=n-1; j>i; j--)
		{
			if(a[j] < a[j-1])
				Swap(&a[j], &a[j-1]);
		}
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
	bubble_sort(a,n);
	for(i=0; i<n; i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
