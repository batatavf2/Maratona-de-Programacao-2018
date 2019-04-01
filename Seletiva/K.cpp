#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> ii;
typedef pair<int, string> pis;

vector <ii> adj[3*N];
int verts, edges, dist[3*N];
set<ii> pq;
set<pis> ans;
vector<string> names;

int main()
{
	int v1, v2, w;
	names.push_back("me");
	names.push_back("Gon");
	names.push_back("Killua");

	//Input
	scanf("%d %d", &verts, &edges);
	for(int i = 1; i <= edges; i++)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		if(v1 != verts)
		{
			adj[3*v1].push_back({3*v2+1, w});
			adj[3*v1+1].push_back({3*v2+2, w});
			adj[3*v1+2].push_back({3*v2, w});
		}
		if(v2 != verts)
		{
			adj[3*v2].push_back({3*v1+1, w});
			adj[3*v2+1].push_back({3*v1+2, w});
			adj[3*v2+2].push_back({3*v1, w});
		}
	}

	//Diskstra
	for(int i = 0; i <= 2; i++)
	{
		memset(dist, 63, sizeof(dist));
		dist[3] = 0;
		pq.insert({0, 3});
		while(!pq.empty())
		{
			int d, v;
			tie(d, v) = *pq.begin();
			pq.erase(pq.begin());
			if(d <= dist[v])
			{
				for(auto path: adj[v])
				{
					if(d + path.second < dist[path.first])
					{
						dist[path.first] = d + path.second;
						pq.insert({dist[path.first], path.first});
					}
				}
			}
		}
		ans.insert({dist[3*verts+i], names[i]});
	}

	while(!ans.empty())
	{
		cout << (*ans.begin()).second << endl;
		ans.erase(ans.begin());
	}


	return 0;
}