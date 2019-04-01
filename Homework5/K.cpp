#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
stack<int> pilha;
bool visited[105];

void topologicalSorting(int x)
{
	visited[x] = true;
	int tam = adj[x].size();
	for(int i = 0; i < tam; i++)
	{
		if(!visited[adj[x][i]])
		{
			topologicalSorting(adj[x][i]);
		}
	}
	pilha.push(x);
}

int main()
{
	int n, edges;
	while(scanf("%d %d", &n, &edges) && (n||edges))
	{
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= edges; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
		}

		for(int i = 1; i <= n; i++)
		{
			if(!visited[i])
			{
				topologicalSorting(i);
			}
		}

		while(!pilha.empty())
		{
			printf("%d ", pilha.top());
			pilha.pop();
		}
		printf("\n");
	}
	return 0;
}