#include <stdio.h>

int main()
{
	int i, n, count, start, minloca;
	int min = 1001;
	int sum = 0;
	int p[1000];

	scanf("%d", &n);
	for (i = 0; i < n; i++)//�켱�� �ѹ� �� �����鼭 ���� �ּҸ� ã��
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
	/*A�� ������ �� �ʿ��� �ð��� a, B�� ������ �� �ʿ��� �ð��� b, 
	C�� ������ �� �ʿ��� �ð��� c �̷������� ���� ���� ��(��, a<b<c)
	A�� �ʿ��� �ð��� a, B�� �ʿ��� �ð��� a+b, C�� �ʿ��� �ð��� a+b+c
	�׷��Ƿ� �� �ʿ��� �ð��� 3a+2b+c�� �ȴ�.
	�̸� �Ϲ�ȭ �ϸ� �� ����� ���� n�̶� ���� �� (n-0)a+(n-1)b+(n-2)c+...*/
	while (count != 0)
	{
		min = 1001;//1<=pi<=1000 �̹Ƿ�
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