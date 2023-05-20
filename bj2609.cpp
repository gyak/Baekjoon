#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int ucl(int, int);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n", ucl(a, b), (a / ucl(a, b))*b);
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