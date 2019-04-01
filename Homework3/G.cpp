#include <bits/stdc++.h>

using namespace std;

typedef struct carMaker
{
	char name[25];
	int minPrice;
	int maxPrice;
}carMaker;

int ordena(carMaker a, carMaker b)
{
	if(a.minPrice > b.minPrice)
		return 0;

	return 1;
}

int main()
{
	int n, queries, numDeMarcas, valueToSearch;
	carMaker brands[10005];
	scanf("%d", &n);
	for(int j = 1; j <= n; j++)
	{
		if(j > 1)
			printf("\n");
		scanf("%d", &numDeMarcas);
		for(int i = 0; i < numDeMarcas; i++)
		{
			scanf(" %s %d %d", brands[i].name, &brands[i].minPrice, &brands[i].maxPrice);
		}
		scanf("%d", &queries);

		sort(brands, brands+numDeMarcas, ordena);

		//DEBUG
		// for(int i = 0; i < numDeMarcas; i++)
		// {
		// 	printf("%s\n", brands[i].name);
		// }




		//DEBUG
		for (int i = 0; i < queries; ++i)
		{
			scanf("%d", &valueToSearch);
			int ok = -1;
			for(int k = 0; brands[k].minPrice <= valueToSearch && k < numDeMarcas; k++)
			{
				if(brands[k].maxPrice >= valueToSearch)
				{
					if(ok == -1)
						ok = k;
					else
					{
						ok = -2;
						break;
					}
				}
			}
			if(ok >= 0)
				printf("%s\n", brands[ok].name);
			else
				printf("UNDETERMINED\n");
		}

	}

	return 0;
}