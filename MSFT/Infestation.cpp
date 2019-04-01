#include <bits/stdc++.h>

using namespace std;

char m[15][15];
int a, b, n;
void go(int line, int col)
{
	int cont = 0;

	if(line+1 < n && m[line+1][col] == '1')
		cont ++;
	if(line-1 >= 0 && m[line-1][col] == '1')
		cont ++;
	if(col+1 < n && m[line][col+1] == '1')
		cont ++;
	if(col-1 >= 0 && m[line][col-1] == '1')
		cont ++;

	//printf("%d\n", cont);

	if(cont >= 2)
	{
		m[line][col] = '1';
		if(line+1 < n && m[line+1][col] == '0')
			go(line+1, col);
		if(line-1 >= 0 && m[line-1][col] == '0')
			go(line-1, col);
		if(col+1 < n && m[line][col+1] == '0')
			go(line, col+1);
		if(col-1 >= 0 && m[line][col-1] == '0')
			go(line, col-1);
	}
}


int main()
{
	do
	{
		cin >> m[b];
		cin.ignore();
		while(m[b][n] != '\0')
		{
			n++;
		}
		b++;
	}while(b < n);
	//printf("%d\n", n);

	// for(int i = 0; i < n; i++)
	// 	cout << m[i] << endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= n; j++)
			go(i, j);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%c", m[i][j]);
		printf("\n");
	}
	return 0;
}