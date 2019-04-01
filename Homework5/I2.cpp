#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
int grau[105];
queue<int> fila;
int pai[105];

int main()
{
	int n, edges, x, y, farAway, maxDist, k=1;
	// memset(adj, 0, sizeof(adj));
	// memset(pai, 0, sizeof(pai));
	while(scanf("%d", &n) && n)
	{
		if(n != 1)
		{
			memset(grau, 0, sizeof(grau));
			memset(adj, 0, sizeof(adj));
			memset(pai, 0, sizeof(pai));
			maxDist = 0;
			while(!fila.empty()) fila.pop();

			for(int i = 1; i < n; i++)
			{
				scanf("%d %d", &x, &y);
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
			fila.push(1);
			int ini = 1;
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
					if(grau[adj[look][i]] == 0 && adj[look][i] != ini)
					{
						grau[adj[look][i]] = grau[look] + 1;
						fila.push(adj[look][i]);
						// printf("grau de %d -> %d\n", adj[look][i], grau[look] + 1);

					}
				}
			}

			memset(grau, 0, sizeof(grau));
			maxDist = 0;
			fila.push(farAway);
			//printf("leaf: %d\n", farAway);
			ini = farAway;
			while(!fila.empty())
			{
				int look = fila.front();
				// printf("look: %d\n", look);
				// printf("grau[%d] = %d, maxDist = %d\n", look, grau[look], maxDist);
				if(grau[look] > maxDist)
				{
					//printf("farAway setado para %d\n", look);
					farAway = look;
					maxDist = grau[look];
				}

				fila.pop();
				int tam = adj[look].size();
				for(int i = 0; i < tam; i++)
				{
					if(grau[adj[look][i]] == 0 && adj[look][i] != ini)
					{
						// printf("grau de %d -> %d\n", adj[look][i], grau[look] + 1);
						grau[adj[look][i]] = grau[look] + 1;
						fila.push(adj[look][i]);
						pai[adj[look][i]] = look;
					}
				}
			}

			maxDist = maxDist/2;
			while(grau[farAway] != maxDist)
				farAway = pai[farAway];
		}
		//printf("farAway: %d\n", farAway);
		if(k!=1)
		{
			printf("\n");
		}

		printf("Teste %d\n", k++);
		if(n!=1)
			printf("%d\n", farAway);
		else
			printf("1\n");
	}
	
	return 0;
}
