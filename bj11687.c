#include <stdio.h>

int fivejegob(int);

int main()
{
	int five[20];
	int i, j, k, m, n = 0;
	int superpass = 0;
	scanf("%d", &m);
	five[0] = 1;
	for (i = 0; ; i++)
	{
		if (m == five[i])//5ÀÇ °ÅµìÁ¦°öÀÌ¶û ÀÏÄ¡ÇÒ °æ¿ì
		{
			printf("%d\n", fivejegob(i+1));
			break;
		}
		if (m < five[i])
		{
			if (i == 1 && m == 5)
				superpass = 1;
			for(j = i - 1; j > 0; j--)
			{
				
				for (k = 1; k < 5; k++)
					if (m < k*five[j])
						break;
				if (k*five[j] - j <= m)
				{
					superpass = 1;
					break;
				}
				m = m - (k - 1)*five[j];
				n = n + (k - 1)*fivejegob(j + 1);
			}
			if (superpass == 1)
				printf("-1\n");
			else
				printf("%d\n", n + 5 * m);
			break;
		}
		five[i + 1] = 5 * five[i] + 1;
	}
	return 0;
}

int fivejegob(int a)
{
	int i, product = 1;
	for (i = 0; i < a; i++)
		product = product * 5;
	return product;
}