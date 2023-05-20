#define _CRT_SECURE_NO_WARNIGS
#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
int heapout(int*, int*);
void heapin(int*, int, int*);

int main()
{
	int n, i, heapnum = 0;
	scanf("%d", &n);
	int* x = (int*)malloc(sizeof(int)*n);
	int* heap = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", x + i);
	for (i = 0; i < n; i++)
	{
		if (x[i] == 0)
			printf("%d\n", heapout(heap, &heapnum));
		else
			heapin(heap, x[i], &heapnum);
	}
	free(x);
	free(heap);
	return 0;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int heapout(int* heap, int* heapnum)
{
	if (*heapnum == 0)
		return 0;
	int i = 0, out = heap[0];
	heap[0] = heap[--(*heapnum)];
	while (1)
	{
		if (2 * i + 1 < *heapnum && heap[2 * i + 1] < heap[i] && heap[2 * i + 1] <= heap[2 * i + 2])
		{
			swap(&heap[2 * i + 1], &heap[i]);
			i = 2 * i + 1;
		}
		else if (2 * i + 2 < *heapnum && heap[2 * i + 2] < heap[i] && heap[2 * i + 2] < heap[2 * i + 1])
		{
			swap(&heap[2 * i + 2], &heap[i]);
			i = 2 * i + 2;
		}
		else
			break;
	}
	return out;
}

void heapin(int* heap, int x, int* heapnum)
{
	int i = *heapnum;
	heap[(*heapnum)++] = x;
	while (1)
	{
		if (i == 0)
			break;
		if ((i - 1) / 2 >= 0 && heap[(i - 1) / 2] > heap[i])
		{
			swap(&heap[(i - 1) / 2], &heap[i]);
			i = (i - 1) / 2;
		}
		else
			break;
	}
}