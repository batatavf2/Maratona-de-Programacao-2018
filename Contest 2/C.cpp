#include <bits/stdc++.h>

using namespace std;

void printStack(stack<int> st)
{
	while(!st.empty())
	{
		printf("%d ", st.top());
		st.pop();
	}
	printf("\n");
}


int main()
{
	int n, ok;
	int i, j, aux;
	stack<int> st;
	int v[1005];
	while(scanf("%d", &n) && n != 0)
	{
		for(i = 1; i <= n; ++i)
		{
			scanf("%d", &v[i]);

		}

		ok = 1;
		while(!st.empty())
			st.pop();
		j = 1;

		for(i = 1; i <= n; ++i)
		{
			aux = v[i];
			if(aux != j)
			{
				if(!st.empty() && st.top() == j)
				{
					st.pop();
					j++;
					i--;
				}
				else
				{
					st.push(aux);
				}
			}
			else
			{
				j++;
			}
			//printStack(st);
		}
		while(j <= n)
		{
			if(!st.empty() && st.top() == j)
			{
				st.pop();
				j++;
			}
			else{
				ok = 0;
				break;
			}
		}
		if(ok)
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;

}