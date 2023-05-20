#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;
typedef long long ll;
typedef struct hang
{
	ll x[6][6];
	ll a;
	ll b;
	ll c;
	ll d;
}hang;

hang cal(hang, hang, ll);
hang jegob(hang, ll, ll);

ll mod = 1000;


int main()
{
	ll n, b, i, j;
	scanf("%lld %lld", &n, &b);
	hang a;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%lld", &(a.x[i][j]));
	hang ans = jegob(a, n, b);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%lld ", ans.x[i][j] % mod);
		printf("\n");
	}
	return 0;
}

hang cal(hang a, hang b, ll n)
{
	int i, j, k;
	hang temp;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			temp.x[i][j] = 0;
			for (k = 0; k < n; k++)
				temp.x[i][j] = ((temp.x[i][j] % mod) + ((a.x[i][k] % mod) * (b.x[k][j] % mod)) % mod) % mod;
		}
	return temp;
}

hang jegob(hang x, ll n, ll b)
{
	if (b == 1)
		return x;
	else if (b == 2)
		return cal(x, x, n);
	else if (b % 2 == 0)
		return jegob(jegob(x, n, b / 2), n, 2);
	else
		return cal(x, jegob(jegob(x, n, b / 2), n, 2), n);
}