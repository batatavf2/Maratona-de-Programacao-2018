#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool visited[105];
vector<int> adj[105];
int cont;

void walk(int x)
{
	cont++;
	visited[x] = true;
	int tam = adj[x].size();
	for(int i = 0; i < tam; i++)
	{
		if(!visited[adj[x][i]]){
			walk(adj[x][i]);
		}
	}
}

int main()
{
	int k = 1, x, y, n, numEdges;
	while(scanf("%d %d", &n, &numEdges) && (n||numEdges))
	{
		cont = 0;
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));

		printf("Teste %d\n", k++);
		for(int i = 1; i <= numEdges; i++)
		{
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		walk(1);
		if(cont == n)
			printf("normal\n\n");
		else
			printf("falha\n\n");
	}

	return 0;
}