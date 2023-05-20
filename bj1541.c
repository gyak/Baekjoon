#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, j, ans, trans = 1;
	int num[100];
	char oper[100];
	for (i = 0; ; i++)
	{
		if (i % 2 == 0)
			scanf("%d", &num[i / 2]);
		else
			scanf("%c", &oper[i / 2]);
		if (oper[i / 2] == '\n')
			break;
	}
	ans = num[0];
	for (j = 0; ; j++)
	{
		if (oper[j] == '\n')
		{
			printf("%d\n", ans);
			break;
		}
		if (oper[j] == '-')
			trans = -1;
		ans = ans + trans * num[j + 1];
	}
	return 0;
}