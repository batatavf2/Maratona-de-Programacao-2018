#include <bits/stdc++.h>

using namespace std;

int table[15][15], dist[15][15], n, m;

void go(int line, int col, int value)
{
	dist[line][col] = value;
	if(line-1 > 0 && dist[line-1][col] > value+1 && table[line-1][col] != 2)
		go(line-1, col, value+1);

	if(line+1 <= n && dist[line+1][col] > value+1 && table[line+1][col] != 2)
		go(line+1, col, value+1);
	
	if(col-1 > 0 && dist[line][col-1] > value+1 && table[line][col-1] != 2)
		go(line, col-1, value+1);
	
	if(col+1 <= m && dist[line][col+1] > value+1 && table[line][col+1] != 2)
		go(line, col+1, value+1);
	
}

int main()
{
	int L, C;
	memset(dist, 63, sizeof(dist));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &table[i][j]);
			if(table[i][j] == 3)
			{
				L = i;
				C = j;
			}
		}
	}
	go(L, C, 0);

	int minDist = 999999;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(table[i][j] == 0 && dist[i][j] < minDist)
				minDist = dist[i][j];
		}
	}

	printf("%d\n", minDist);

	return 0;
}