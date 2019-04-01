#include <bits/stdc++.h>

using namespace std;

int main()
{
	char str[105];
	scanf("%s", str);
	int t = strlen(str), c = 0, s = 0;
	for(int i = 0; i < t; i++)
	{
		if(str[i] == 'C')
		{
			s = 0;
			if(c == 2)
			{
				printf("P");
				c = 0;
			}
			else
			{
				printf("B");
				c++;
			}
		}

		if(str[i] == 'S')
		{
			c = 0;
			if(s == 2)
			{
				printf("T");
				s = 0;
			}
			else
			{
				printf("D");
				s++;
			}
		}

	}

	return 0;
}