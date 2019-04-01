#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int dist[105][105];

int main()
{
	int cells, exit, cd, numEdges;
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	scanf("%d", &cells);
	scanf("%d", &exit);
	scanf("%d", &cd);
	scanf("%d", &numEdges);
	for(int i = 1; i <= cells; i++)
		dist[i][i] = 0;

	for(int i = 1; i <= numEdges; i++)
	{
		int x, y, d;
		scanf("%d %d %d", &x, &y, &d);
		dist[x][y] = d;
	}

	//FLOYD-WHARSHALL
	for(int k = 1; k <= cells; k++)
		for(int i = 1; i <= cells; i++)
			for(int j = 1; j <= cells; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];


	// for(int i = 1; i <= cells; i++)
	// {
	// 	for(int j = 1; j <= cells; j++)
	// 		printf("%d ", dist[i][j]);
	// 	printf("\n");
	// }


	int cont = 0;

	for(int i = 1; i <= cells; i++)
	{
		if(dist[i][exit] <= cd)
			cont++;
	}


	printf("%d\n", cont);
	return 0;
}