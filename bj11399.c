#include <stdio.h>

int main()
{
	int i, n, count, start, minloca;
	int min = 1001;
	int sum = 0;
	int p[1000];

	scanf("%d", &n);
	for (i = 0; i < n; i++)//우선은 한번 쭉 훑으면서 제일 최소를 찾음
	{
		scanf("%d", &p[i]);
		if (min >= p[i])
		{
			minloca = i;
			min = p[i];
		}
	}
	count = n;
	sum = sum + (min * count--);
	/*A가 인출할 때 필요한 시간을 a, B가 인출할 때 필요한 시간을 b, 
	C가 인출할 때 필요한 시간을 c 이런식으로 정의 했을 때(단, a<b<c)
	A가 필요한 시간은 a, B가 필요한 시간은 a+b, C가 필요한 시간은 a+b+c
	그러므로 총 필요한 시간은 3a+2b+c가 된다.
	이를 일반화 하면 총 사람의 수를 n이라 했을 때 (n-0)a+(n-1)b+(n-2)c+...*/
	while (count != 0)
	{
		min = 1001;//1<=pi<=1000 이므로
		for (i = minloca, start = minloca; i < count; i++)
		{
			p[i] = p[i + 1];
			if (min >= p[i])
			{
				minloca = i;
				min = p[i];
			}
		}
		for (i = 0; i < start; i++)
		{
			if (min >= p[i])
			{
				minloca = i;
				min = p[i];
			}
		}
		sum = sum + (min * count--);
	}
	printf("%d\n", sum);	
	return 0;
}