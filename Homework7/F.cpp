#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

vector<pair<ll, ll> > adj[1005];//(vert, dist)
priority_queue<pair<ll, ll> > q;//(-dist, vert)
ll dist[1005], start, fim;
int main()
{

	ll a, b, w, n, k;
	while(scanf("%lld %lld", &n, &k) && n||k)
	{
		memset(dist, 63, sizeof(dist));
		memset(adj, 0, sizeof(adj));
		while(k--)
		{
			scanf("%lld %lld %lld", &a, &b, &w);
			adj[a].pb({b, w});
			//adj[b].pb({a, w});
		}
		scanf("%lld %lld", &start, &fim);
		q.push({0, start});
		dist[start] = 0;
		while(!q.empty())
		{
			ll look = q.top().second;
			q.pop();
			for(auto u : adj[look])
			{
				ll ve = u.first;
				ll we = u.second;
				if(dist[ve] > dist[look] + we)
				{
					dist[ve] = dist[look] + we;			
					q.push({-we, ve});
				}
			}

		}
		if(dist[fim] != dist[0])
			printf("%lld\n", dist[fim]);
		else
			printf("-1\n");

	}
	return 0;
}