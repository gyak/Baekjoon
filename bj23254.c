#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
void heapin(int, int);
int heapout();

int* heap;
int heapnum = 0;
int* heapzari;

int main()
{
	int n, m, i, j, temp, ans = 0;
	scanf("%d %d", &n, &m);
	int* a = (int*)malloc(sizeof(int)*m);
	int* b = (int*)malloc(sizeof(int)*m);
	for (i = 0; i < m; i++)
		scanf("%d", a + i);
	for (i = 0; i < m; i++)
		scanf("%d", b + i);
	heap = (int*)malloc(sizeof(int)*m);
	heapzari = (int*)malloc(sizeof(int)*m);
	for (i = 0; i < m; i++)
		heapin(b[i], i);
	for (i = 0; i < 24 * n; i++)
	{
		if (100 - a[heapzari[0]] >= b[heapzari[0]])
			a[heapzari[0]] = a[heapzari[0]] + b[heapzari[0]];
		else
		{
			temp = heapout();
			b[temp] = 100 - a[temp];
			heapin(b[temp], temp);
			i--;
		}
	}
	for (i = 0; i < m; i++)
		ans = ans + a[i];
	printf("%d\n", ans);
	free(a);
	free(b);
	free(heap);
	free(heapzari);
	return 0;
}


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void heapin(int x, int zari)
{
	int i = heapnum;
	heapzari[heapnum] = zari;
	heap[heapnum++] = x;
	if (heapnum == 1)
		return;
	while ((i - 1) / 2 >= 0 && i != 0)
	{
		if (heap[(i - 1) / 2] < heap[i])
		{
			swap(heap + (i - 1) / 2, heap + i);
			swap(heapzari + (i - 1) / 2, heapzari + i);
		}
		i = (i - 1) / 2;
	}
}

int heapout()
{
	int i = 0, out = heapzari[0];
	heap[0] = heap[--heapnum];
	heapzari[0] = heapzari[heapnum];
	while (1)
	{
		if (2 * i + 1 < heapnum && heap[2 * i + 1] > heap[i] && heap[2 * i + 1] >= heap[2 * i + 2])
		{
			swap(heap + 2 * i + 1, heap + i);
			swap(heapzari + 2 * i + 1, heapzari + i);
			i = 2 * i + 1;
		}
		else if (2 * i + 2 < heapnum && heap[2 * i + 2] > heap[i] && heap[2 * i + 2] > heap[2 * i + 1])
		{
			swap(heap + 2 * i + 2, heap + i);
			swap(heapzari + 2 * i + 2, heapzari + i);
			i = 2 * i + 2;
		}
		else
			break;
	}
	return out;
}