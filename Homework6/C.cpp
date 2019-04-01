#include <bits/stdc++.h>

using namespace std;

string split(string a, int n)
{
	string aux;
	for(int i = 0; i < n; i++)
	{
		aux += a[i];
	}
	return aux;
}

string dp[105][105];

int main()
{
	string str1, str2;

	cin >> str1;
	int t1 = str1.length();
	cin.ignore();
	cin >> str2;
	int t2 = str2.length();
	cin.ignore();

	cout <<  str1[1] << endl;

	for(int i = 0; i <= t1; i++)
	{
		for(int j = 0; j <= t2; j++)
		{
			if(i == 0)
			{
				if(j != 0)
					dp[i][j] = dp[i][j-1] + str2[j-1];
			}
			else if(j == 0)
			{
				dp[i][j] = dp[i-1][j] + str1[i-1];
			}
			else if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + str1[i-1];
			}
			else
			{
				if()
			}
		}
	}
	return 0;
}