#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
void heapin(int);
int heapout();

int* heap;
int heapnum = 0;

int main()
{
	int n, i, j, x;
	scanf("%d", &n);
	heap = (int*)malloc(sizeof(int)*(n + 1));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		heapin(x);
	}
	for (i = 1; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", &x);
			heapin(x);
			heapout();
		}
	printf("%d\n", heapout());
	free(heap);
	return 0;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void heapin(int x)
{
	int i = heapnum;
	heap[heapnum++] = x;
	if (heapnum == 1)
		return;
	while ((i - 1) / 2 >= 0 && i != 0)
	{
		if (heap[(i - 1) / 2] > heap[i])
			swap(heap + (i - 1) / 2, heap + i);
		i = (i - 1) / 2;
	}
}

int heapout()
{
	int i = 0, out = heap[0];
	heap[0] = heap[--heapnum];
	while (1)
	{
		if (2 * i + 1 < heapnum && heap[2 * i + 1] < heap[i] && heap[2 * i + 1] <= heap[2 * i + 2])
		{
			swap(heap + 2 * i + 1, heap + i);
			i = 2 * i + 1;
		}
		else if (2 * i + 2 < heapnum && heap[2 * i + 2] < heap[i] && heap[2 * i + 2] < heap[2 * i + 1])
		{
			swap(heap + 2 * i + 2, heap + i);
			i = 2 * i + 2;
		}
		else
			break;
	}
	return out;
}