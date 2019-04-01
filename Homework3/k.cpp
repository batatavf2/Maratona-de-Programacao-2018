#include <bits/stdc++.h>

using namespace std;

int maxQnt;

typedef struct m
{
	int size;
	char matriz[5][5];
	int qnt = 0;
}m;

int isLegal(m tabl, int line, int col)
{
	bool okLine = true;
	bool okCol = true;
	if(tabl.matriz[line][col] != '.')
		return 0;
	for(int i = 1; i < line; i++)
	{
		if(tabl.matriz[i][col] == 'H')
			okLine = false;
		if(tabl.matriz[i][col] == 'X')
			okLine = true;
	}

	for(int i = tabl.size; i > line; i--)
	{
		if(tabl.matriz[i][col] == 'H')
			okLine = false;
		if(tabl.matriz[i][col] == 'X')
			okLine = true;
	}

	for(int i = 1; i < col; i++)
	{
		if(tabl.matriz[line][i] == 'H')
			okCol = false;
		if(tabl.matriz[line][i] == 'X')
			okCol = true;
	}

	for(int i = tabl.size; i > col; i--)
	{
		if(tabl.matriz[line][i] == 'H')
			okCol = false;
		if(tabl.matriz[line][i] == 'X')
			okCol= true;
	}

	if(okLine && okCol)
		return 1;
	return 0;
}


void go(m tabl, int line, int col)
{
	tabl.qnt++;
	if(tabl.qnt > maxQnt)
		maxQnt = tabl.qnt;

	tabl.matriz[line][col] = 'H';
	for(int i = 1; i <= tabl.size; i++)
	{
		for(int j = 1; j <= tabl.size; j++)
		{
			if(isLegal(tabl, i, j))
			{
				//printf("%d %d\n",i, j);
				go(tabl, i, j);
			}

		}
	} 	
}

void init(m tabl)
{
	for (int i = 1; i <= tabl.size; ++i)
	{
		for (int j = 0; j <= tabl.size; ++j)
		{
			if(isLegal(tabl, i, j))
			{
				go(tabl, i, j);
			}
		}
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) && n != 0)
	{
		m main;
		main.size = n;
		maxQnt = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf(" ");
			for (int j = 1; j <= n; j++)
			{
				scanf("%c", &main.matriz[i][j]);
			}
		}
		//main.matriz[2][2] = 'H';
		/* // debug
		printf("\n");
		for(int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%c", main.matriz[i][j]);
			}
			printf("\n");
		}
		// debug */
		/* // debug
		for(int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%d ", isLegal(main, i, j));
			}
			printf("\n");
		}

		// debug */


		init(main);
		printf("%d\n", maxQnt);
	}
	return 0;
}