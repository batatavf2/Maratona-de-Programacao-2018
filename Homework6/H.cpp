#include <bits/stdc++.h>

using namespace std;

int dp[2005][2005];
char str1[2005], str2[2005];


int main()
{
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
	{
		memset(dp, 0, sizeof(dp));
		scanf(" %s", str1);
		scanf(" %s", str2);

		// puts(str1);
		// puts(str2);
		int t1 = strlen(str1);
		int t2 = strlen(str2);
		for(int m = 0; m <= t1; m++)
		{
			for(int n = 0; n <= t2; n++)
			{
				if(m == 0)
					dp[m][n] = n;
				else if(n == 0)
					dp[m][n] = m;

				else if(str1[m-1] == str2[n-1])
					dp[m][n] = dp[m-1][n-1];
				else
					dp[m][n] = 1 + min(dp[m-1][n-1], min(dp[m-1][n], dp[m][n-1]));
			}
		}
		printf("%d\n", dp[t1][t2]);
	}

	return 0;
}