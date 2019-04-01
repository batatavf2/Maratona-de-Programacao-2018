#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x1, x2, y1, y2, n;
	scanf("%d", &n);
	//printf("%d\n", __gcd(0, n));
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", 1 + __gcd(abs(y2-y1), abs(x2-x1)));
	}
	return 0;

}