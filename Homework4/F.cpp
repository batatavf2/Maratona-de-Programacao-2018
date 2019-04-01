#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	ll n, mult = 1;
	scanf("%lld", &n);
	while(n > 1)
	{
		if(n%2 != 0)
		{
			printf("%lld %lld\n", mult*(n*n - 1)/2, mult*(n*n + 1)/2);
			return 0;
		}
		else if(n == 4)
		{
			printf("%lld %lld\n", 3*mult, 5*mult);
			return 0;
		}
		else
		{
			n = n/2;
			mult *= 2;
		}
	}
	printf("-1\n");

	return 0;
}