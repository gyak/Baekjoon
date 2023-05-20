#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int ucl(int, int);

int main()
{
	int a[10000];
	int b[10000];
	int i, t;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
		scanf("%d %d", a + i, b + i);
	for (i = 0; i < t; i++)
		printf("%d\n", (a[i] / ucl(a[i], b[i]))*b[i]);
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