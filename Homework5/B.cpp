#include <bits/stdc++.h>

using namespace std;

typedef struct snowDrift
{
	int line;
	int col;
	int color;

}snowDrift;

int place[1005][1005];
snowDrift node[1005];

void go(snowDrift x)
{
	//printf("Set %d, at [%d][%d],  to group %d\n", place[x.line][x.col], x.line, x.col, x.color);
	for(int i = 1; i <= 1000; i++)
	{
		if(place[x.line][i] != 0 && node[place[x.line][i]].color == 0)
		{
			int viz = place[x.line][i];
			node[viz].color = x.color;
			//printf("to indo hein [%d][%d] -> %d\n", node[viz].line, node[viz].col, node[viz].color);
			go(node[viz]);
		}
	}

	for(int i = 1; i <= 1000; i++)
	{
		if(place[i][x.col] != 0 && node[place[i][x.col]].color == 0)
		{
			int viz = place[i][x.col];
			node[viz].color = x.color;
			//printf("to indo hein [%d][%d] -> %d\n", node[viz].line, node[viz].col, node[viz].color);
			go(node[viz]);
		}
	}
}

int main()
{
	memset(place, 0, sizeof(place));
	memset(node, 0, sizeof(node));
	int n, x, y;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		node[i].line = x;
		node[i].col = y;
		place[x][y] = i;
	}

	int group = 1, look = 1;
	while(look <= n)
	{
		if(node[look].color == 0)
		{
			node[look].color = group;
			go(node[look]);
			group++;
		}
		look++;
	}

	printf("%d\n", group-2);

	return 0;
}
