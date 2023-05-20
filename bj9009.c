#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, k, t, count = 0, fibomax = 1, fibonow = 1;
	int fibo[50];
	int ansfibo[50];
	int* n;
	fibo[0] = 1;
	fibo[1] = 1;
	scanf("%d", &t);
	n = (int*)malloc(sizeof(int)*(t+3));
	for (i = 0; i < t; i++)
		scanf("%d", n + i);
	for (i = 0; i < t; i++)
	{
		if (n[i] >= fibo[fibomax])
			fibonow = fibomax;
		else
			fibonow = 1;
		for (j = fibonow; j < 50; j++)
		{
			fibo[j + 1] = fibo[j] + fibo[j - 1];
			if (fibo[j + 1] > n[i])
			{
				if (fibomax < j + 1)
					fibomax = j + 1;
				break;
			}
		}
		for (k = j; k > -1; k--)
		{
			if (n[i] == 0)
				break;
			if (n[i] >= fibo[k])
			{
				ansfibo[count++] = fibo[k];
				n[i] = n[i] - fibo[k];
			}
		}
		while (count != 0)
			printf("%d ", ansfibo[--count]);
		printf("\n");
	}
	free(n);
	return 0;
}