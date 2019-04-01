#include <bits/stdc++.h>

using namespace std;

bool notPrime[1123456];

int  main()
{
	int ok;
	long long int n;
	for(long long int i = 2; i <= 1123455; i++)
	{
		if(!notPrime[i])
		{
			for(long long int j = 2*i; j <= 1123455; j+=i)
			{
				notPrime[j] = true;
			}
		}
	}

	while(scanf("%lld", &n) && n != 0)
	{
		ok = 0;
		printf("%lld = ", n);
		for(long long int i = 2; i <= 1123455; i++)
		{
			if(!notPrime[i] && n%i == 0)
			{
				ok++;
				printf("%lld", i);
				if(ok < 3)
					printf(" x ");
				else
					printf("\n");
			}
		}
	}

	return 0;
}