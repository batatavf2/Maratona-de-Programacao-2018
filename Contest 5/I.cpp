#include <bits/stdc++.h>

using namespace std;


typedef struct direction
{
	char vert;
	char hor;
}direction;

int marked[25][25], cont, n, m;
direction mat[25][25];

void go(int line, int col)
{
	//printf("%d %d\n", line, col);
	cont++;
	marked[line][col] = 1;
	if(mat[line][col].vert == 'v')
	{
		for(int i = line+1; i <= n; i++)
		{
			if(marked[i][col] != 1)
				go(i, col);
		}
	}
	if(mat[line][col].vert == '^')
	{
		for(int i = line-1; i >= 1; i--)
		{
			if(marked[i][col] != 1)
				go(i, col);
		}
	}
	if(mat[line][col].hor == '>')
	{
		for(int i = col+1; i <= m; i++)
		{
			if(marked[line][i] != 1)
				go(line, i);
		}
	}
	if(mat[line][col].hor == '<')
	{
		for(int i = col-1; i >= 1; i--)
		{
			if(marked[line][i] != 1)
				go(line, i);
		}
	}
}

int main()
{
	char aux;
	scanf("%d %d ", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%c", &aux);
		for(int j = 1; j <= m; j++)
		{
			mat[i][j].hor = aux;
		}
	}
	scanf("\n");
	for(int i = 1; i <= m; i++)
	{
		scanf("%c", &aux);
		for(int j = 1; j <= n; j++)
		{
			mat[j][i].vert = aux;
		}
	}

	// for(int i = 1; i <= n; i++)
	// {
	// 	for(int j = 1; j <= m; j++)
	// 	{
	// 		printf("%c", mat[i][j].hor);
	// 	}
	// 	printf("\n");
	// }

	// for(int i = 1; i <= n; i++)
	// {
	// 	for(int j = 1; j <= m; j++)
	// 	{
	// 		printf("%c", mat[i][j].vert);
	// 	}
	// 	printf("\n");
	// }


	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cont = 0;
			memset(marked, 0, sizeof(marked));
			go(i, j);
			if(cont != n*m)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
		printf("YES\n");

	return 0;
}