#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool visited[2005];
vector<int> adj[2005];
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
	int k = 1, x, y, n, numEdges, m, ans;
	while(scanf("%d %d", &n, &numEdges) && (n||numEdges))
	{
		cont = 0;
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));

		//printf("Teste %d\n", k++);
		for(int i = 1; i <= numEdges; i++)
		{
			scanf("%d %d %d", &x, &y, &m);
			adj[x].pb(y);
			if(m == 2)
			{
				adj[y].pb(x);
			}
		}
		ans = 1;
		for(int i = 1; i <= n; i++)
		{
			cont = 0;
			memset(visited, 0, sizeof(visited));
			walk(i);
			if(cont != n)
			{
				ans = 0;
				break;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}