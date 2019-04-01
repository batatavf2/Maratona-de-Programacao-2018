#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> adj[100005];
int color[100005];
int compEdges[100005];
set<int> notUsed;

void paint(int a, int key)
{
	//printf("painting %d as %d\n", a, key);
	color[a] = key;
	notUsed.erase(a);
	for(int i = 0; i < adj[a].size(); i++)
	{
		if(color[adj[a][i]] == 0)
			paint(adj[a][i], key);
	}

	compEdges[key] += adj[a].size();
}

int main()
{

	int nodes, edges, key = 1, x, y;

	scanf("%d %d", &nodes, &edges);

	for(int i = 1; i <= nodes; i++)
		notUsed.insert(i);

	for(int i = 1; i <= edges; i++)
	{
		scanf("%d %d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	while(!notUsed.empty())
	{
		paint(*notUsed.begin(), key);
		key++;
	}
	int maxEdges = 0;
	for(int i = 1; i < key; i++)
	{
		
		if(compEdges[i] > maxEdges)
			maxEdges = compEdges[i];
	}

	// for(int i = 1; i <= nodes; i++)
	// {
	// 	printf(" %d", color[i]);
	// }
	// printf("\n");

	printf("%d\n", maxEdges/2);
return 0;
}

