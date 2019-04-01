#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10005];
int grau[10005];
queue<int> fila;

int main()
{
	int n, edges, x, y, farAway, maxDist;
	// memset(adj, 0, sizeof(adj));
	// memset(pai, 0, sizeof(pai));

	scanf("%d", &n);

	for(int i = 1; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	fila.push(1);

	while(!fila.empty())
	{
		int look = fila.front();
		if(grau[look] > maxDist)
		{
			farAway = look;
			maxDist = grau[look];
		}

		fila.pop();
		int tam = adj[look].size();
		for(int i = 0; i < tam; i++)
		{
			if(grau[adj[look][i]] == 0)
			{
				grau[adj[look][i]] = grau[look] + 1;
				fila.push(adj[look][i]);

			}
		}
	}
	memset(grau, 0, sizeof(grau));
	maxDist = 0;
	fila.push(farAway);
	while(!fila.empty())
	{
		int look = fila.front();
		if(grau[look] > maxDist)
		{
			farAway = look;
			maxDist = grau[look];
		}

		fila.pop();
		int tam = adj[look].size();
		for(int i = 0; i < tam; i++)
		{
			if(grau[adj[look][i]] == 0)
			{
				grau[adj[look][i]] = grau[look] + 1;
				fila.push(adj[look][i]);

			}
		}
	}
	printf("%d\n", maxDist);

	return 0;
}
