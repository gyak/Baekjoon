#include<stdio.h>
#include<stdlib.h>

int* ai;
int* dist;

int  main()
{
	int n, k, i;
	scanf("%d %d", &n, &k);
	ai = (int*)malloc(sizeof(int)*n);
	dist= (int*)malloc(sizeof(int)*(n - 1));
	for (i = 0; i < n; i++)
		scanf("%d", ai + i);
	for (i = 0; i < n - 1; i++)
		dist[i] = ai[i + 1] - ai[i];


	free(ai);
	free(dist);
	return 0;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int left, int right)
{
	int pivot = left, i;
	for (i = left; i < right; i++)
	{
		if (dist[i] > dist[right])
		{
			swap()
		}
	}
}

void quicksort(int left, int right)
{
	int pivot;
	if (right > left)
	{
		pivot = partition(left, right);
		quicksort(left, pivot - 1);
		quicksort(pivot + 1, right);
	}
}