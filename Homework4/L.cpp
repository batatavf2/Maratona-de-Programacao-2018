#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;





ll mmc(ll a, ll b)
{
	return a*b/__gcd(b, a);
}

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result%MOD;
}

ll modularInverse(ll a)
{

	return fast_power(a%MOD, MOD-2);
}


int main()
{
	ll cases, f0, md, k, days, m;
	scanf("%lld", &cases);
	for(ll i = 1; i <= cases; i++)
	{
		scanf("%lld %lld", &m, &days);
		md = fast_power(m, days);
		f0 = mmc(md - 1, md*(m-1))*modularInverse((md*(m-1)));
		k = f0*md*(m-1)*modularInverse(md-1);
		printf("%lld %lld\n", f0%MOD, k%MOD);
	}
	return 0;
}