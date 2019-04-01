#include <bits/stdc++.h>

using namespace std;

int main()
{
	int nodes, edges, k, x, y;
	vector<pair<int, int> > adj[1005];
	int value[1005];

	scanf("%d %d %d", &nodes, &edges, &k);

	for(int i = 1; i <= nodes; i++)
	{
		scanf("%d", &value[i]);
	}

	for(int i = 1; i <= edges; i++)
	{
		scanf("%d %d", &x, &y);
		adj[x].push_back(make_pair(-value[y], -y));
		adj[y].push_back(make_pair(-value[x], -x));
	}

	for(int i = 1; i <= nodes; i++)
	{
		sort(adj[i].begin(), adj[i].end());
		if(adj[i].size() > k-1)
			printf("%d\n", -adj[i][k-1].second);
		else
			printf("1\n");
	}

	
	return 0;
}

