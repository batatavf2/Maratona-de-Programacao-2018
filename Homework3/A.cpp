#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, x, y, c = 0;
	scanf("%d %d %d %d", &x, &y, &a, &b);

	for(int i = max(a,b); i <= x; i++)
	{
		for(int j = b; j <= min(i-1, y); j++)
		{
			c++;
		}
	}

	printf("%d\n", c);

	for(int i = max(a,b); i <= x; i++)
	{
		for(int j = b; j <= min(i-1, y); j++)
		{
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}