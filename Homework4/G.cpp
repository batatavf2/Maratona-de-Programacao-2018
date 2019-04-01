#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, fact, temp = 0, k;
	stack<int> divs;
	scanf("%d %d", &n, &k);
	for(int i = 2; i <= n; i++)
	{
		while(n%i == 0)
		{
			//printf("i: %d - temp: %d\n", i, temp);
			temp++;
			n = n/i;
			divs.push(i);
		}
	}
	//printf("right!\n");
	if(temp >= k)
	{
		int carteada = 1;
		while(k > 1)
		{
			printf("%d ", divs.top());
			divs.pop();
			k--;
		}
		while(!divs.empty())
		{
			carteada *= divs.top();
			divs.pop();
		}
		printf("%d\n", carteada);
	}
	else
		printf("-1\n");
	return 0;
}