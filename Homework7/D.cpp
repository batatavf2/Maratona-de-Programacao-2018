#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

vector<pair<ll, ll> > adj[1005];//(vert, dist)
priority_queue<pair<ll, ll> > q;//(-dist, vert)
bool vis[1005];
ll dist[1005];
int main()
{
	memset(dist, 63, sizeof(dist));
	dist[0] = 0;

	ll a, b, w, n, k;
	scanf("%lld %lld", &n, &k);
	while(k--)
	{
		scanf("%lld %lld %lld", &a, &b, &w);
		adj[a].pb({b, w});
		adj[b].pb({a, w});
	}

	q.push({0, 0});
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
	printf("%lld\n", dist[n+1]);

	return 0;
}