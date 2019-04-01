#include <bits/stdc++.h>

using namespace std;

char numb[1123456];
char aux[1123456];

int main()
{
	int nMax = 0;

	scanf("%s", numb);
	
	int nSize = strlen(numb);

	for(int i = 0; i < nSize; i++)
	{
		if(numb[i] - '0' > nMax)
			nMax = numb[i] - '0';
	}

	printf("%d\n", nMax);

	for(int i = 1; i <= nMax; i++)
	{
		memset(aux, 0, sizeof(aux));
		int j = 0;
		while(numb[j] == 0)
			j++;
		for(int k = j; k < nSize; k++)
		{
			if(numb[k] != '0')
			{
				aux[k-j] = '1';
				numb[k]--;
			}
			else
				aux[k-j] = '0';
		}
		aux[nSize - j] = '\0';
		printf("%s ", aux);
	}
	printf("\n");

	return 0;
}