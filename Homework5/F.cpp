#include <bits/stdc++.h>
#define pb push_back
#define MAX 9999999

using namespace std;

int cost[55];
vector<int> adj[55];
int k = 1, x, y, n, numEdges, cidade, afford;

void setup()
{
	for(int i = 1; i <= n; i++)
	{
		cost[i] = MAX;	
	}
	memset(adj, 0, sizeof(adj));
}

void walk(int x)
{
	int numViz = adj[x].size();
	for(int i = 0; i < numViz; i++)
	{
		if(cost[adj[x][i]] > 1 + cost[x])
		{
			cost[adj[x][i]] = 1 + cost[x];
			walk(adj[x][i]);
		}
	}
}

int main()
{

	while(scanf("%d %d %d %d", &n, &numEdges, &cidade, &afford) && (n||numEdges||cidade||afford))
	{
		setup();
		printf("Teste %d\n", k++);
		for(int i = 1; i <= numEdges; i++)
		{
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		cost[cidade] = 0;
		walk(cidade);
		for(int i = 1; i <= n; i++)
		{
			if(cost[i] <= afford && i != cidade)
				printf("%d ", i);
		}
		printf("\n\n");
	}

	return 0;
}