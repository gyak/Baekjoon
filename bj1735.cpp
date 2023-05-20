#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

long long ucl(long long, long long);

int main()
{
	int a, b, c, d;
	long long up, down;
	int i, j, k, t;
	scanf("%d %d\n%d %d", &a, &b, &c, &d);
	up = a * d + b * c;
	down = b * d;
	printf("%lld %lld\n", up / ucl(up, down), down / ucl(up, down));	
	return 0;
}

long long ucl(long long a, long long b)
{
	long long t;
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