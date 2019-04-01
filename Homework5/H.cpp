#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10005];
int pai[10005], cont;
bool visit[10005], theMightyAnswer;

void walk(int x)
{
	visit[x] = true;
	cont++;
	int tam = adj[x].size();
	for(int i = 0; i < tam; i++)
	{
		if(!visit[adj[x][i]])
		{
			pai[adj[x][i]] = x;
			walk(adj[x][i]);
		}
		else if(adj[x][i] != pai[x])
			theMightyAnswer = false;
	}

}

int main()
{
	int n, edges, x, y;
	// memset(adj, 0, sizeof(adj));
	// memset(pai, 0, sizeof(pai));
	theMightyAnswer = true;
	scanf("%d %d", &n, &edges);

	for(int i = 1; i <= edges; i++)
	{
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	walk(1);

	if(theMightyAnswer && cont == n)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
