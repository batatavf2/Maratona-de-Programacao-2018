#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
int color[105];
bool isThereAnyBug;

void colorize(int x)
{
	int tam = adj[x].size();
	for(int i = 0; i < tam; i++)
	{
		if(color[adj[x][i]] == 0)
		{
			color[adj[x][i]] = 3 - color[x];
			colorize(adj[x][i]);
		}
		else if(color[adj[x][i]] != 3 - color[x])
			isThereAnyBug = true;
	}
}

int main()
{
	int k = 1, n, edges;
	while(scanf("%d %d", &n, &edges) != EOF)
	{
		memset(adj, 0, sizeof(adj));
		memset(color, 0, sizeof(color));
		isThereAnyBug = false;
		for(int i = 1; i <= edges; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		color[1] = 1;
		colorize(1);

		if(k != 1)
			printf("\n");
		printf("Instancia %d\n", k++);
		if(isThereAnyBug)
			printf("nao\n");
		else
			printf("sim\n");
	}
	return 0;
}