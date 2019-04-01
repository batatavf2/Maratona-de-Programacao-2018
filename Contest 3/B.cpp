#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, val[4], div[4005];

	 // while(scanf("%d %d %d %d", &n, &val[1], &val[2], &val[3]))
	 // {
	memset(div, 0, sizeof(div));
	scanf("%d %d %d %d", &n, &val[1], &val[2], &val[3]);
	div[0] = 1;
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(div[j] != 0 && j + val[i] <= n)
			{
				if(div[j] + 1 > div[j+val[i]])
					div[j+val[i]] = div[j] + 1;
			}
		}
	}
	printf("%d\n", div[n]-1);
	//}
	
	return 0;

}
