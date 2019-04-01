#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll aux;

bool isPerfectCube(ll n) {
    ll root = round(cbrt((double)n));
    aux = root;
    return n == root * root * root;
}

int main()
{
	ll k, a, b, mdc;
	scanf("%lld", &k);
	while(k--)
	{
		scanf("%lld %lld", &a, &b);
		//printf("%lld %lld %lld ", a, b, __gcd(a, b));
		mdc = __gcd(a, b);
		ll cmp = (a/mdc)*(b/mdc);
		cmp = mdc/cmp;
		if(isPerfectCube(cmp) && isPerfectCube(a*b) &&  mdc >= aux)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}