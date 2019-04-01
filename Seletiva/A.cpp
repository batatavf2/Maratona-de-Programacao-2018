#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;
const int MOD = 1e9 + 7;
int f[N], g[N], n;

int main()
{
	f[0] = 1;
	g[0] = 1;

	for(int i = 2; i <= 10000000; i++)
	{
		f[i] = (f[i-2] + 2*g[i-2]%MOD)%MOD;
		g[i] = (f[i] + g[i-2])%MOD;
	}

	scanf("%d", &n);
	printf("%d\n", (f[n])%MOD);

	return 0;
}
