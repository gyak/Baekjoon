#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>


using namespace std;

int* ai;
int* dist;

int  main()
{
	int n, k, i, ans = 0;
	scanf("%d %d", &n, &k);
	ai = (int*)malloc(sizeof(int)*n);
	dist = (int*)malloc(sizeof(int)*(n - 1));
	for (i = 0; i < n; i++)
		scanf("%d", ai + i);
	for (i = 0; i < n - 1; i++)
		dist[i] = ai[i] - ai[i + 1];
	std:sort(dist, dist + n - 1);
	for (i = 0; i < k - 1; i++)
		dist[i] = 0;
	for (i = 0; i < n - 1; i++)
		ans = ans - dist[i];
	printf("%d\n", ans);
	free(ai);
	free(dist);
	return 0;
}