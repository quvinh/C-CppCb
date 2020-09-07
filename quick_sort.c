#include<stdio.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void quick_sort(int a[], int left, int right)
{
	int i, j, x;
	if(left > right) return;
	x = a[(left + right)/2];
	i = left;
	j = right;
	do
	{
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j)
		{
			Swap(&a[i], &a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(left < j) quick_sort(a, left, j);
	if(i < right) quick_sort(a, i, right);
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
	
	printf("\nQuick Sort:\n");
	quick_sort(a, 0, n-1);
	for(i=0; i<n; i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
