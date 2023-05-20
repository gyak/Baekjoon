#include<stdio.h>
//이 방법은 공간이 부족해서 못씀
int factorial(int);
int nCk(int, int);
int max = 0;
int arr[1000];

int main()
{
	arr[0] = 1;
	int n, k;
	//scanf("%d", &n);
	//printf("%d\n", factorial(n));
	scanf("%d %d", &n, &k);
	printf("%d\n", nCk(n, k) % 10007);
	return 0;
}

int factorial(int n)
{
	if (max >= n)
	{
		printf("now factorial[%d] = %d, max = %d\n", n, arr[n], max);
		return arr[n];
	}
	for (int i = max + 1; i < n + 1; i++)
	{
		arr[i] = arr[max] * i;
		max = i;
	}
	printf("factorial[%d] = %d, max = %d\n", n, arr[n], max);
	return arr[n];	
}

int nCk(int n, int k)
{
	return factorial(n) / (factorial(n - k) * factorial(k));
}