#include <bits/stdc++.h>

using namespace std;

int bag[2005];
bool reach[2005];
int capac, items, maxValue;

int main()
{
	int value, weight;
	reach[0] = true;
	scanf("%d %d", &capac, &items);
	for(int i = 1; i <= items; i++)
	{
		scanf("%d %d", &weight, &value);
		for(int j = capac; j >= 0; j--)
		{
			if(reach[j] && capac >= j+weight && bag[j] + value > bag[j+weight])
			{
				reach[j+weight] = true;
				bag[j+weight] = bag[j] + value;
				if(bag[j+weight] > maxValue)
					maxValue = bag[j+weight];
			}
		}
	}
	
	printf("%d\n", maxValue);

	return 0;
}