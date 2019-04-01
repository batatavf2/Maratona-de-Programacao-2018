#include <bits/stdc++.h>

using namespace std;

long long int mdc(long long int a, long long int b)
{
	if(b > a)
	{
		long long int auz = a;
		a = b;
		b = auz;
	}
	if(a%b == 0)
		return b;
	else
		return mdc(b, a%b);
}

long long int conter(long long int a, long long int b)
{
	long long int ans = -1, c;
	if(mdc(a, b) != 1)
	{
		for(c = a; c <= b; c++)
		{
			//printf("mdc(%lld, %lld) = %lld\n", a, c, mdc(a,c));
			//printf("mdc(%lld, %lld) = %lld\n", c, b, mdc(c,b));
			if(mdc(c,a) == 1 && mdc(b, c) == 1)
				ans = c;
		}
	}
	return ans;
}


int main()
{
	long long int a, b, i, j, ans = -1;
	scanf("%lld %lld", &a, &b);
	for(i = a; i <= b; i++)
	{
		for(j = i; j <= b; j++)
		{
			ans = conter(i, j);
			if(ans != -1)
			{
				printf("%lld %lld %lld\n", i, ans, j);
				goto point;
			}
		}
	}
	printf("-1\n");
	point:
	return 0;
}