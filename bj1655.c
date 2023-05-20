#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
void heapin(int, int);
int heapout(int);

int* maxheap;
int* minheap;
int minnum = 0, maxnum = 0;


int main()
{
	int n, i, k;
	scanf("%d", &n);
	maxheap = (int*)malloc(sizeof(int)*n);
	minheap = (int*)malloc(sizeof(int)*n);
	int* x = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", x + i);

	for (i = 0; i < n; i++)
	{
		if (i == 0)
			heapin(x[i], -1);
		else if (i == 1)
		{
			if (x[i] >= maxheap[0])
				heapin(x[i], 1);
			else
			{
				heapin(x[i], -1);
				heapin(heapout(-1), 1);
			}
		}
		else
		{
			if (x[i] > minheap[0])
				heapin(x[i], 1);
			else
				heapin(x[i], -1);
			if (maxnum > minnum + 1)
				heapin(heapout(-1), 1);
			else if (maxnum < minnum)
				heapin(heapout(1), -1);
		}
		printf("%d\n", maxheap[0]);
	}
	free(x);
	free(maxheap);
	free(minheap);
	return 0;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void heapin(int x, int minmax)
{
	int i;
	if (minmax == -1)//maxheap
	{
		i = maxnum;
		maxheap[maxnum++] = x;
		if (maxnum == 1)
			return;
		while ((i - 1) / 2 >= 0 && i != 0)
		{
			if (maxheap[(i - 1) / 2] < maxheap[i])
				swap(maxheap + (i - 1) / 2, maxheap + i);
			i = (i - 1) / 2;
		}

	}
	else if (minmax == 1)//minheap
	{
		i = minnum;
		minheap[minnum++] = x;
		if (minnum == 1)
			return;
		while ((i - 1) / 2 >= 0 && i != 0)
		{
			if (minheap[(i - 1) / 2] > minheap[i])
				swap(minheap + (i - 1) / 2, minheap + i);
			i = (i - 1) / 2;
		}

	}
}

int heapout(int minmax)
{
	int i = 0, out;
	if (minmax == -1)//maxheap
	{
		out = maxheap[0];
		maxheap[0] = maxheap[--maxnum];
		while (1)
		{
			if (2 * i + 1 < maxnum && maxheap[2 * i + 1] > maxheap[i] && maxheap[2 * i + 1] >= maxheap[2 * i + 2])
			{
				swap(maxheap + 2 * i + 1, maxheap + i);
				i = 2 * i + 1;
			}
			else if (2 * i + 2 < maxnum && maxheap[2 * i + 2] > maxheap[i] && maxheap[2 * i + 2] > maxheap[2 * i + 1])
			{
				swap(maxheap + 2 * i + 2, maxheap + i);
				i = 2 * i + 2;
			}
			else
				break;
		}
	}
	else if (minmax == 1)//minheap
	{
		out = minheap[0];
		minheap[0] = minheap[--minnum];
		while (1)
		{
			if (2 * i + 1 < minnum && minheap[2 * i + 1] < minheap[i] && minheap[2 * i + 1] <= minheap[2 * i + 2])
			{
				swap(minheap + 2 * i + 1, minheap + i);
				i = 2 * i + 1;
			}
			else if (2 * i + 2 < minnum && minheap[2 * i + 2] < minheap[i] && minheap[2 * i + 2] < minheap[2 * i + 1])
			{
				swap(minheap + 2 * i + 2, minheap + i);
				i = 2 * i + 2;
			}
			else
				break;
		}
	}
	return out;
}