#include <bits/stdc++.h>

using namespace std;

int test;

typedef struct ring
{
	bool used[18];
	vector <int> circle;
	int size = 0;
}ring;

bool isPrime(int n)
{
//printf("%d\n", ++test);

	for(int i = 2; i < n; i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

void go(ring anel, int add, int n)
{
	anel.size++;
	anel.used[add] = true;
	anel.circle.push_back(add);

	/* //DEBUG
	printf("1");
	for(int i = 1; i < anel.size; i++)
		printf(" %d", anel.circle[i]);
	printf("\n");
	//DEBUG */

	if(anel.size == n && isPrime(anel.circle[n-1] + anel.circle[0]))
	{
		printf("1");
		for(int i = 1; i < n; i++)
			printf(" %d", anel.circle[i]);
		printf("\n");
		// printf("1");
		// for(int i = n-1; i > 0; i--)
		// 	printf(" %d", anel.circle[i]);
		// printf("\n");

	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(anel.used[i] == false)
			{

				if(isPrime(anel.circle[anel.size-1] + i))
				{		
					go(anel, i, n);
				}				
			}
		}
	}
}

int main()
{
	int n, test = 0;
	while(scanf("%d", &n) != EOF)
	{
		ring anel;
		if (test > 0)
			printf("\n");
		
		printf("Case %d:\n", ++test);
		for(int i = 1; i <= n; i++)
		{
			anel.used[i] = false;
		}

		go(anel, 1, n);
	}
	return 0;
}