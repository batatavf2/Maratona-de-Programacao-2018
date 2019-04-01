#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
queue<int> fila;
int numChildren[105];
bool onQueue[105];

int main()
{
	int n, x, y, k=1;
	while(scanf("%d", &n) && n)
	{
		//RESET
		memset(adj, 0, sizeof(adj));
		while(!fila.empty()) fila.pop();
		memset(numChildren, 0, sizeof(numChildren));
		//SCAN
		for(int i = 1; i <= n-1; i++)
		{
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		//SETUP
		for(int i = 1; i <= n; i++)
		{
			numChildren[i] = adj[i].size();
			if(numChildren[i] == 1) 
				fila.push(i);
			onQueue[i] = true;
		}
		fila.push(-1);
		//RUN
		int nodesLeft = n;
		while(fila.size() > 2)
		{
			int look = fila.front();
			if(look != -1)
			{
				int adjs = adj[look].size();
				numChildren[look]--;
				for(int j = 0; j < adjs; j++)
				{
					if(--numChildren[adj[look][j]] == 1)
						fila.push(adj[look][j]);
				}
				fila.pop();
				nodesLeft--;
			}
			else
			{
				fila.pop();
				if(nodesLeft > 2)
					fila.push(-1);
			}
		}
		if(k!=1)
		{
			printf("\n");
		}
		printf("Teste %d\n", k++);
		while(!fila.empty())
		{
			printf("%d ", fila.front());
			fila.pop();
		}
		printf("\n");
	}
	return 0;
}