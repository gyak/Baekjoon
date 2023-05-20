#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;
typedef long long ll;

int ucl(int, int);
int cmp(ll, ll, ll, ll);

int main()
{
	int i, j, k, a, b, c, d, ansup = 1, ansdown = 1;
	ll mid, chaup, chadown, minup = 1, mindown = 1;
	scanf("%d %d", &a, &b);
	for (i = 1; i <= 32767; i++)
	{
		mid = i * a / b;
		for (j = mid - 2; j < mid + 3; j++)
		{
			if ((j == a && i == b) || j == 0)
				continue;
			if (j < 0 || j >= i || ucl(i, j) != 1)
				continue;
			chaup = a * i - b * j;
			if (chaup < 0)
				chaup = chaup * -1;
			chadown = i * b;
			if (cmp(chaup, chadown, minup, mindown) == -1)
			{
				ansup = j;
				ansdown = i;
				minup = chaup;
				mindown = chadown;
			}
			else if (cmp(chaup, chadown, minup, mindown) == 0)
			{
				if (cmp(ansup, ansdown, j, i) == 1)
				{
					ansup = j;
					ansdown = i;
				}
			}
		}
	}
	printf("%d %d\n", ansup, ansdown);
	return 0;
}

int ucl(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return ucl(b, a%b);
}

int cmp(ll up1, ll down1, ll up2, ll down2)
{
	if (up1 * down2 - up2 * down1 < 0)
		return -1;
	else if (up1 * down2 - up2 * down1 == 0)
		return 0;
	else
		return 1;
}