#include <bits/stdc++.h>

using namespace std;

int main()
{
	int M[4][2600];
	queue<pair<int, int> > fila, temp;
	scanf("%d", &n);
	//RECEBE
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 4; j++)
			scanf("%d", M[j][i])
	}

	for(i = 0; i < n; i++)
	{
		fila.push_back(make_pair(M[0][i], ));
	}
	//LOOP
	for(j = 1; j < 4; j++)
	{
		while(!fila.empty())
		{
			int num = fila.front().first;
			int cont = fila.front().second;
			for(i = 0; i < n; i++)
			{
				temp.push_back(aux + M[j][i], );
			}
			fila.pop();
		}
		while(!temp.empty())
		{
			fila.push_back(temp.front());
			temp.pop();
		}
	}

	//Loop
}