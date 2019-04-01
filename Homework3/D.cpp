#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, s, v[100005];
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	sort(v, v+n);
	reverse(v, v+n);
	for(int i = 0; i < n; i++)
	{
		s -= v[i];
		if(s <= 0)
		{
			printf("%d\n", i+1);
			return 0;
		}
	}
}