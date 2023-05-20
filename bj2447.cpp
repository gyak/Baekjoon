#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

void starcheck(int, int, int);

int** star;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	star = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++)
		star[i] = (int*)calloc(n, sizeof(int));
	starcheck(0, 0, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (star[i][j] == 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(star[i]);
	free(star);
	return 0;
}

void starcheck(int x, int y, int n)
{
	int i, j;
	if (n == 3)
	{
		for(i=x; i<x+n; i++)
			for (j = y; j < y + n; j++)
				if (i != x + 1 || j != y + 1)
					star[i][j] = 1;
		return;
	}
	for(i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (i != 1 || j != 1)
				starcheck(x + i * (n / 3), y + j * (n / 3), n / 3);
}