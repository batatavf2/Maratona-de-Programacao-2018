#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	set<int> sums;
	map<int, int> keys;
	int sum = 0, aux, n, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &aux);
		sum+=aux;
		sums.insert(sum);
		keys.insert({sum, i});
	}
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &aux);
		printf("%d\n", keys[*sums.lower_bound(aux)]);
	}
	return 0;
}