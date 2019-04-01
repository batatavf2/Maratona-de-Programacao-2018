#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool visited[105];
vector<int> adj[105];
int cont;
int dep[105];

void go(int a)
{
	visited[a] = true;
	cont++;
	int t1 = adj[a].size();
	for(int i = 0; i < t1; i++)
	{
		if(!visited[adj[a][i]])
			go(adj[a][i]);
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) && n!=0)
	{	
		memset(adj, 0, sizeof(adj));
		memset(dep, 0, sizeof(dep));
		for(int i = 1; i <= n; i++)
		{
			int numViz;
			scanf("%d", &numViz);
			for(int j = 1; j <= numViz; j++)
			{
				int aux;
				scanf("%d", &aux);
				adj[i].pb(aux);
			}
		}

		for(int i = 1; i <= n; i++)
		{
			memset(visited, 0, sizeof(visited));
			cont = 0;
			go(i);
			dep[i] = cont;
		}
		int ans = 1;
		for(int i = 1; i <= n; i++)
		{
			if(dep[ans] < dep[i])
			{
				ans = i;
			}
		}
		printf("%d\n", ans);	
	}
	return 0;
}