#include <bits/stdc++.h>
#define db(x) cout << #x << " = " << x << endl
#define pb push_back
#define ll long long
using namespace std;

ll n;
vector<ll> sizes, prox;
bool visited[100005];

int main()
{
	ll queries, x, y, conv = 0, alt = 0;
	scanf("%lld", &n);
	prox.pb(0);
	for(ll i = 1; i <= n; i++)
	{
		scanf("%lld", &x);
		prox.pb(x);
	}
	
	for(ll i = 1; i <= n; i++)
	{
		ll k = i, size = 0;
		while(!visited[k])
		{
			size++;
			visited[k] = true;
			k = prox[k];
		}
		if(size == n)
		{
			printf("%lld\n", n*n);
			return 0;
		}
		if(size > 0)
			sizes.pb(size);
	}

	sort(sizes.begin(), sizes.end());
	ll aux = sizes.back();
	sizes.pop_back();
	aux += sizes.back();
	sizes.pop_back();
	sizes.pb(aux);
	//sizes.pb(sizes[0] + sizes[1]);
	for(ll t : sizes)
	{
		//printf("%lld ", t);
		conv += t*t;
	}

	printf("%lld\n", conv);
	return 0;
}