#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);

long long k;
int from = 1, to = 3, etc = 2;
long long han[70];

int main()
{
	long long i;
	long long n;
	scanf("%lld %lld", &n, &k);
	han[0] = 0;
	for (i = 0; i < n; i++)
		han[i + 1] = 2 * han[i] + 1;
	for (i = n; i > 0; i--)
	{
		if (k < han[i - 1] + 1)
			swap(&to, &etc);
		else if (k == han[i - 1] + 1)
			break;
		else
		{
			swap(&from, &etc);
			k = k - han[i - 1] - 1;
		}
	}
	printf("%d %d\n", from, to);
	return 0;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}