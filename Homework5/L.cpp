#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
queue<int> fila;
bool visited[105];
map<int, string> i2n;
map<string, int> n2i;
int dependencies[105];
set<int> aux;
int n, edges;

void findLeaves()
{	
	bool again = false;
	//visited[x] = true;
	for(int x = 1; x <= n; x++)
	{
		//printf("\t%s dep %d\n", i2n[x].c_str(), dependencies[x]);
		if(dependencies[x] == 0 && !visited[x])
		{
			//printf("removed: %s\n", i2n[x].c_str());
			again = true;
			visited[x] = true;
			//printf("x: %d\n", x);
			aux.insert(x);
			//printf("added to answer: %s\n", i2n[*aux.begin()].c_str());
			int tam = adj[x].size();

			int leaf = (*aux.begin());
			for(int j = 0; j < tam; j++)
			{
				int viz = adj[leaf][j];
			//printf("viz: %s\n", i2n[viz].c_str());
				dependencies[viz]--;
			}
			fila.push(*aux.begin());
			aux.erase(x);
			break;
		}
	}
	if(again)
		findLeaves();
	else
	{
		while(!aux.empty())
		{
			int leaf = (*aux.begin());
			//printf("%s ", i2n[leaf].c_str());
			fila.push(leaf);
			int tam = adj[leaf].size();
			aux.erase(leaf);
		}
	}
}

int main()
{
	int k = 1;

	while(scanf("%d", &n) != EOF)
	{
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));
		memset(dependencies, 0, sizeof(dependencies));
		for(int i = 1; i <= n; i++)
		{
			cin.ignore();
			string aux;
			cin >> aux;
			n2i[aux] = i;
			i2n[i] = aux;
		}

		scanf("%d", &edges);
		for(int i = 1; i <= edges; i++)
		{
			cin.ignore();
			string x, y;
			cin >> x >> y;
			adj[n2i[x]].push_back(n2i[y]);
			dependencies[n2i[y]]++;
		}

		findLeaves();
		printf("Case #%d: Dilbert should drink beverages in this order:", k++);
		while(!fila.empty())
		{
			printf(" %s", i2n[fila.front()].c_str());
			fila.pop();
		}
		printf(".\n\n");
	}
	return 0;
}