#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll segtree[400005], lazy[400005], n, op;

void lazyUpdate(ll ini, ll fim, ll k)
{
	segtree[k] += (fim-ini+1)*lazy[k];

	if(ini != fim)
	{
			lazy[2*k] += lazy[k];
			lazy[2*k + 1] += lazy[k];
	}
	lazy[k] = 0;
}

ll sumQuery(ll a, ll b, ll k, ll ini, ll fim)
{
	if(lazy[k] != 0)
		lazyUpdate(ini, fim, k);

	if(ini >= a && fim <= b)
		return segtree[k];

	if(fim < a || ini > b)
		return 0;


	ll mid = (fim+ini)/2;

	return sumQuery(a, b, 2*k, ini, mid) + sumQuery(a, b, 2*k + 1, mid+1, fim);
}

void rangeUpdate(ll a, ll b, ll k, ll ini, ll fim, ll v)
{
	if(lazy[k] != 0)
		lazyUpdate(ini, fim, k);

	if(ini >= a && fim <= b)
	{
		lazy[k] += v;
		lazyUpdate(ini, fim, k);
		return;
	}
	if(fim < a || ini > b)
		return;

	ll mid = (fim+ini)/2;

	rangeUpdate(a, b, 2*k, ini, mid, v);
	rangeUpdate(a, b, 2*k + 1, mid+1, fim, v);
	segtree[k] = segtree[2*k+1] + segtree[2*k];
}


void pTree()
{
	for(ll j = 1; j <= n; j *= 2)
	{
		for(ll i = 0; i < j; i++)
		{
			printf("(%lld/%lld) ", segtree[j+i], lazy[j+i]);
		}
		printf("\n");
	}

}


int main()
{
	ll k, a, b, v, c;
	scanf("%lld", &k);
	while(k--)
	{
		memset(segtree, 0, sizeof(segtree));
		memset(lazy, 0, sizeof(lazy));
		scanf("%lld %lld", &n, &c);
		for(ll i = 1; i <= c; i++)
		{
			scanf("%lld", &op);
			if(op)
			{
				scanf("%lld %lld", &a, &b);
				printf("%lld\n", sumQuery(min(a, b),max(a, b), 1, 1, n));
			}
			else
			{
				scanf("%lld %lld %lld", &a, &b, &v);
				rangeUpdate(min(a, b), max(a, b), 1, 1, n, v);
				//pTree();
			}
		}
	}

	return 0;
}