#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, ele[112345], numEle, maxWeight, aux;

	scanf("%d", &n);
	for(int j = 1; j <= n; j++)
	{
		scanf("%d %d", &numEle, &maxWeight);
		for(int i = 0; i < numEle; i++)
		{
			scanf("%d", &ele[i]);
		}

		sort(ele, ele + numEle);
		// //DEBUG
		// for(int i = 0; i < numEle; i++)
		// {
		// 	printf("%d ", ele[i]);
		// }
		// printf("\n");
		int cont = 0;
		while(cont < numEle)
		{
			
			if(maxWeight - ele[cont] >= 0)
			{
				maxWeight -= ele[cont];
				cont++;
			}
			else
				break;
		}
		printf("%d\n", cont);
	}
	return 0;

}
