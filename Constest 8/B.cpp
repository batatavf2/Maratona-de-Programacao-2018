#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll best[112345];
ll v[112345], aux;

int main()
{
	ll n;
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++)
	{
		scanf("%lld", &aux);
		v[aux]++;
	}
	best[0] = 0;
	best[1] = v[1];
	for(ll i = 2; i <= 100000; i++)
	{
		best[i] = max(best[i-1], best[i-2] + v[i]*i);
	}

	printf("%lld\n", best[100000]);

	return 0;

}
