#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
int color[100005], c1, c2;

void paint(int vert, int cor)
{

	for(int i = 0; i < adj[vert].size(); i++)
	{
		if(color[adj[vert][i]] == 0)
		{
			//printf("pintando %d de %d\n", adj[vert][i], cor);
			//printf("c1 == %d\n", c1+1);
			color[adj[vert][i]] = cor;
			c1++;
			paint(adj[vert][i], cor);

		}
	}
}

int main()
{
	int nodes, queries, k;
	pair<int, int> edges[100005];

	scanf("%d %d", &nodes, &queries);
	for(int i = 1; i < nodes; i++)
	{
		scanf("%d %d", &edges[i].first, &edges[i].second);
		adj[edges[i].first].push_back(edges[i].second);
		adj[edges[i].second].push_back(edges[i].first);
	}

	for(int j = 1; j <= queries; j++)
	{
		int i;
		scanf("%d", &i);
		c1 = 1;
		c2 = 1;
		memset(color, 0, sizeof(color));
		color[edges[i].first] = 1;
		color[edges[i].second] = 2;
		paint(edges[i].first, 1);
		printf("%d\n", c1*(nodes-c1));
		}
	
	return 0;
}

