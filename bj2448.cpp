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
		star[i] = (int*)calloc(2 * n - 1, sizeof(int));
	starcheck(n - 1, 0, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2 * n - 1; j++)
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
	int j;
	if (n == 3)
	{
		star[x - 2][y + 2] = 1;
		star[x - 1][y + 1] = 1;
		star[x - 1][y + 3] = 1;
		for (j = y; j < y + 5; j++)
			star[x][j] = 1;
		return;
	}
	starcheck(x, y, n / 2);
	starcheck(x - n / 2, y + n / 2, n / 2);
	starcheck(x, y + n, n / 2);
}