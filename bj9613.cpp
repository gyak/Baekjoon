#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int ucl(int, int);

int main()
{
	int a[101][101];
	int n[101];
	long long ans[101];
	int i, j, k, t;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", n + i);
		for (j = 0; j < n[i]; j++)
			scanf("%d", &a[i][j]);
	}
	for (i = 0; i < t; i++)
	{
		if (n[i] == 1)
			ans[i] = a[i][0];
		else
		{
			ans[i] = 0;
			for (j = 0; j < n[i] - 1; j++)
				for (k = j + 1; k < n[i]; k++)
					ans[i] = ans[i] + ucl(a[i][j], a[i][k]);
		}
	}
	for (i = 0; i < t; i++)
		printf("%lld\n", ans[i]);
	return 0;
}

int ucl(int a, int b)
{
	int t;
	if (a < b)
	{
		t = b;
		b = a;
		a = t;
	}
	if (a % b == 0)
		return b;
	else
		return(ucl(b, a%b));
}