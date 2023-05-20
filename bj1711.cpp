#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;
typedef long long ll;

ll guri(int, int);

ll x[1501];
ll y[1501];

int main()
{
	int i, j, k, n, ans = 0;
	ll a, b, c;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lld %lld", x + i, y + i);
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			for (k = j + 1; k < n; k++)
			{
				a = guri(i, j);
				b = guri(j, k);
				c = guri(k, i);
				if (a >= b && a >= c && a == b + c)
					ans++;
				else if (b >= a && b >= c && b == a + c)
					ans++;
				else if (c >= a && c >= b && c == a + b)
					ans++;
			}
	printf("%d\n", ans);
	return 0;
}

ll guri(int a, int b)
{
	return (x[b] - x[a])*(x[b] - x[a]) + (y[b] - y[a])*(y[b] - y[a]);
}