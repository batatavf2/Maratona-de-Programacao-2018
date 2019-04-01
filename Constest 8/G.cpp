#include <bits/stdc++.h>
#define pb push_back
using namespace std;


bool ready[300005], added[300005], key; 

void update(int x)
{
	cont++;
	
}


int main()
{
	int n, aux, cont = 0, oks = 0;
	char cmd;
	key = 1;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf(" %s", cmd);
		if(!strcmp(cmd, "add"))
		{
			scanf("%d", &aux);
			added[aux] = true;
			if()
		}
		else
		{
			if(!ready[key])
			{
				update(key);
			}
			key++;
		}

	}


	return 0;
}