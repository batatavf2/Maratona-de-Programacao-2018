#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int fastExp(long long int x, long long int y)
{
	x = x%MOD;
	if(y == 1)
		return x%MOD;
	if(y == 0)
		return 1;

	if(y%2 == 0)
	{
		long long int k = fastExp(x, y/2);
		k = k%MOD;
		return (k*k)%MOD;
	}
	else
		return ((x)*fastExp(x, y-1))%MOD;
}

int main()
{
	long long int a, b, c, d;

	cin >> a;
	if(a == 0)
		printf("1");
	else
	{
		b = fastExp(2, a-1)%MOD;
		c = 1 + fastExp(2, a);
		c = c%MOD;
		d = (b*c)%MOD;
		cout << d;
	}
	return 0;

}