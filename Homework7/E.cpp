#include <bits/stdc++.h>

using namespace std;

int dist[1005][1005];

int main()
{
	int c, vert, edges;
	scanf("%d", &c);
	while(c--)
	{
		int x, y;
		memset(dist, 63, sizeof(dist));
		scanf("%d %d", &vert, &edges);
		for(int i = 0; i < vert; i++)
		{
			dist[i][i] = 0;
		}
		for(int j = 1; j <= edges; j++)
		{
			scanf("%d %d", &x, &y);
			scanf("%d", &dist[x][y]);
		}
		for(int k = 0; k < vert; k++)
		{
			for(int i = 0; i < vert; i++)
			{
				for(int j = 0; j < vert; j++)
				{
					if(dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		bool ok = false;
		for(int i = 0; i < vert; i++)
		{
			if(dist[i][i] < 0)
			{
				printf("possible\n");
				ok = true;
				break;
			}
		}
		if(ok == false)
			printf("not possible\n");

	}
	return 0;
}	