#include <bits/stdc++.h>

using namespace std;

int main()
{
	int v[10], n, ind = 0, dig=0, last, amnt = 0;
	scanf("%d", &n);
	for(int i = 1; i <= 9; i++)
	{
		scanf("%d", &v[i]);
	}

	v[0] = 999999;
	for(int i = 1; i <= 9; i++)
	{
		if(v[ind] >= v[i])
		{
			ind = i;
		}
	}

	dig = n/v[ind];

	int afford = 0;
	if(dig > 0)
	{
		afford = n%v[ind];
		for(int i = 1; i <= 9; i++)
		{
			if(v[i] < afford + v[ind])
				last = i;
		}
	}
		

	while(v[last] < afford + v[ind])
	{
		printf("to cagando o pau\n");
		amnt++;
		afford -= v[last] - v[ind];
		dig--;
	}

	if(dig > 0)
	{
		for(int i = 1; i <= amnt; i++)
		{
			printf("%d", last);
		}

		for(int i = 1; i <= dig; i++)
		{
			printf("%d", ind);
		}
		printf("\n");
	}
	else
		printf("-1\n");

	return 0;
}