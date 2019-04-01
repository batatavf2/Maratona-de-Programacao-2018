#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool notPrime[1123456];


int  main()
{
	int n;
	scanf("%d", &n) && n != 0;
	
	if(n%2 == 0)
	{
		printf("4 %d\n", n-4);
	}
	else if(n < 19)
	{
		printf("%d 9\n", n-9);
	}
	else
		printf("9 %d\n", n-9);

	
	return 0;
}