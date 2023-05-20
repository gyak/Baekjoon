#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
int partition(int, int);
void quicksort(int, int);


int* sen;
int* dist;

int main()
{
	int n, k, i, j, max, maxloca, ans = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	sen = (int*)malloc(sizeof(int)*n);
	dist = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", sen + i);
	quicksort(0, n - 1);
	for (i = 0; i < n - 1; i++)
		dist[i] = sen[i + 1] - sen[i];
	for (i = 0; i < k - 1; i++)
	{
		max = dist[0];
		maxloca = 0;
		for (j = 0; j < n - 1; j++)
			if (dist[j] > max)
			{
				max = dist[j];
				maxloca = j;
			}
		dist[maxloca] = -1;
	}
	for (i = 0; i < n - 1; i++)
	{
		if (dist[i] != -1)
			ans = ans + dist[i];
	}
	printf("%d\n", ans);
	free(sen);
	free(dist);
	return 0;
}

void swap(int* a, int* b)
{
	int t = *b;
	*b = *a;
	*a = t;
}

int partition(int left, int right)
{
	int i, pivot = left;
	for (i = left; i < right; i++)
		if (sen[i] < sen[right])
			swap(&sen[i], &sen[pivot++]);
	swap(&sen[pivot], &sen[right]);
	return pivot;
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