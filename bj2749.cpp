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
	ll a;
	ll b;
	ll c;
	ll d;
}hang;

hang cal(hang, hang);
hang fibo(hang, ll);

ll mod = 1000000;

int main()
{
	ll n;
	hang temp = { 1,1,1,0 };
	scanf("%lld", &n);
	printf("%lld\n", fibo(temp, n - 1).a);
	return 0;
}

hang cal(hang x, hang y)
{
	hang temp;
	temp.a = (((x.a%mod)*(y.a%mod) % mod) + ((x.b%mod)*(y.c%mod)) % mod) % mod;
	temp.b = (((x.a%mod)*(y.b%mod) % mod) + ((x.b%mod)*(y.d%mod)) % mod) % mod;
	temp.c = (((x.c%mod)*(y.a%mod) % mod) + ((x.d%mod)*(y.c%mod)) % mod) % mod;
	temp.d = (((x.c%mod)*(y.b%mod) % mod) + ((x.d%mod)*(y.d%mod)) % mod) % mod;
	return temp;
}

hang fibo(hang x, ll n)
{
	hang temp = { 1,1,1,0 };
	if (n == 0)
		return temp;
	else if (n == 1)
		return x;
	else if (n == 2)
		return cal(x, x);
	else if (n % 2 == 0)
		return fibo(fibo(temp, n / 2), 2);
	else
		return cal(temp, fibo(fibo(temp, n / 2), 2));
}