#include <bits/stdc++.h>
#define ll long long int
#define MAX 456789987655
using namespace std;

bool notPrime[1123456];
ll rows, cols;
ll m[505][505];

ll moves(ll val)
{
	// printf("%lld -> ", val);
	ll c = 0;
	while(notPrime[val])
	{
		val++;
		c++;
	}
	// printf("%lld\n", val);
	return c;
}

ll sumRow(ll row)
{
	ll s = 0;
	for(ll j = 1; j <= cols; j++)
	{
		s += moves(m[row][j]);
	}
	return s;
}

ll sumCol(ll col)
{
	ll s = 0;
	for(ll j = 1; j <= rows; j++)
	{
		s += moves(m[j][col]);
	}
	return s;
}

int  main()
{

	notPrime[1] = true;
	for(long long int i = 2; i <= 112344; i++)
	{
		if(!notPrime[i])
		{
			for(long long int j = 2*i; j <= 1123455; j+=i)
			{
				notPrime[j] = true;
			}
		}
	}

	scanf("%lld %lld", &rows, &cols);
	for(ll i = 1; i <= rows; i++)
	{
		for(ll j = 1; j <= cols; j++)
		{
			scanf("%lld", &m[i][j]);
		}
	}

	ll maxSum = MAX;
	ll temp;
	for(ll i = 1; i <= rows; i++)
	{
		temp = sumRow(i);
		if(maxSum > temp)
		{
			// printf("row: %lld\n", i);
			maxSum = temp;
		}
	}

	for(ll i = 1; i <= cols; i++)
	{
		temp = sumCol(i);
		// printf("temp: %lld\n", temp);
		if(maxSum > temp)
		{
			// printf("col: %lld\n", i);
			maxSum = temp;
		}
	}

	if(maxSum == MAX)
		printf("0\n");
	else
		printf("%lld\n", maxSum);

	return 0;
}
