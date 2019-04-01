#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool visited[2005];
vector<int> adj[2005];
vector<int> revAdj[2005];
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

void revWalk(int x)
{
	cont++;
	//printf("visited: %d\n", x);
	visited[x] = true;
	int tam = revAdj[x].size();
	for(int i = 0; i < tam; i++)
	{
		if(!visited[revAdj[x][i]]){
			revWalk(revAdj[x][i]);
		}
	}
}

int main()
{
	int k = 1, x, y, n, numEdges, m, ans;
	while(scanf("%d %d", &n, &numEdges) && (n||numEdges))
	{
		memset(adj, 0, sizeof(adj));
		memset(revAdj, 0, sizeof(revAdj));

		//printf("Teste %d\n", k++);
		for(int i = 1; i <= numEdges; i++)
		{
			scanf("%d %d %d", &x, &y, &m);
			adj[x].pb(y);
			revAdj[y].pb(x);
			if(m == 2)
			{
				adj[y].pb(x);
				revAdj[x].pb(y);
			}
		}
		ans = 1;
		
		// for(int j = 1; j <= n; j++)
		// {
		// 	int tam = revAdj[j].size();
		// 	for(int i = 0; i < tam; i++)
		// 	{
		// 		printf("%d ", revAdj[j][i]);
		// 	}
		// 	printf("\n");
		// }

		//IDA
		cont = 0;
		memset(visited, 0, sizeof(visited));
		walk(1);
		if(cont != n)
			ans = 0;

		//VOLTA
		cont = 0;
		memset(visited, 0, sizeof(visited));
		revWalk(1);
		if(cont != n)
			ans = 0;

		printf("%d\n", ans);
	}

	return 0;
}