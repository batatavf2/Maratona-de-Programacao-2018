#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int a, n, i, s1 = 0, s2 = 0;
	scanf("%lld", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%lld", &a);
		s1 = s1 | a;
	}
	for(i = 1; i <= n; i++)
	{
		scanf("%lld", &a);
		s2 = s2 | a;
	}
	printf("%lld\n", s1 + s2);
	return 0;
}