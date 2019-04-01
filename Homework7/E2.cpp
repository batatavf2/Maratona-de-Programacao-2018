#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef struct edge
{
	int f;
	int to;
	int w;
}edge;

int dist[1005];
edge aux;
int main()
{
	int k, vert, lig, a, b, c;
	
	scanf("%d", &k);
	while(k--)
	{
		memset()
		edge edges[2005];
		scanf("%d %d", &vert, &lig);
		for(int i = 0; i < lig; i++)
		{
			scanf("%d %d %d", &aux.f, &aux.to, &aux.w);
			edges[i] = aux;
		}
		for(int i = 1; i <= vert-1; i++)
		{
			for(int j = 0; j < lig; j++)
			{
				dist[edges[j].to] = min(dist[edges[j].to], dist[edges[j].f] + edges[j].w);
			}
		}
		bool ok = false;
		for(int j = 0; j < lig; j++)
		{
			if(dist[edges[j].to] > dist[edges[j].f] + edges[j].w)
			{
				ok = true;
				break;
			}
		}
		ok ? printf("possible\n") : printf("not possible\n");
	}
	

	return 0;
}	