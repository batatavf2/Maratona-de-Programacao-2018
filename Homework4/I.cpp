#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll escolhe(ll n, ll k)
{
	if (k > n) {
		return 0;
	}
	ll r = 1;
	for (ll d = 1; d <= k; ++d) {
		r *= n--;
		r /= d;
	}
	return r;
}

int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll temp = n/m;
	ll nMin = (m-n%m)*(temp*(temp-1)/2) + (n%m)*(temp*(temp+1)/2);
	ll nMax = (n-m+1)*(n-m)/2;
	//eprintf("%lld\n", nMax);
	printf("%lld %lld\n", nMin, nMax);

	return 0;
}