#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

long long ucl(long long, long long);

int main()
{
	long long a, b;
	long long min, loca1, loca2;
	int i, j, k = 0;
	scanf("%lld %lld", &a, &b);
	long long amu = (long long)sqrt(b / a);
	int* sosu = (int*)calloc(amu, sizeof(int));
	for (i = 1; (i * i) <= (b / a); i++)
	{
		if ((b / a) % i == 0)
			sosu[k++] = i;
	}
	if (k == 1)
		printf("%d %d\n", a * sosu[0], a * (b / a / sosu[0]));
	else
	{
		min = sosu[0] + (b / a / sosu[0]);
		loca1 = sosu[0];
		loca2 = b / a / sosu[0];
		for (j = 0; j < k; j++)
		{
			if (min > sosu[j] + (b / a / sosu[j]) && a == ucl(a*sosu[j], a*(b/a/sosu[j])))
			{
				min = sosu[j] + (b / a / sosu[j]);
				loca1 = sosu[j];
				loca2 = b / a / sosu[j];
			}
		}
		printf("%lld %lld\n", a*loca1, a*loca2);
	}
	free(sosu);
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