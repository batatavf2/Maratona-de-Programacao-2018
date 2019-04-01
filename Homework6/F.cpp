#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	k = 240 - k;
	int i = 0;
	while(k - 5*(i+1) >= 0 && i < n)
	{
		i++;
		k -= 5*i;
	}
	printf("%d\n", i);
	return 0;
}