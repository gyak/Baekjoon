#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int ucl(int, int);

int main()
{
	int a[101];
	int n;
	long long ans[101];
	int i, j, k, t;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);
	for (i = 1; i < n; i++)
		printf("%d/%d\n", a[0] / ucl(a[0], a[i]), a[i] / ucl(a[0], a[i]));
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