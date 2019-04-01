#include <bits/stdc++.h>

using namespace std;

int main()
{
	stack <string > st;
	string stra;
	int n;
	scanf("%d ", &n);
	while(!st.empty())
		st.pop();
	for(int i = 1; i <= n; i++)
	{
		stra.clear();
		cin >> stra;
		cin.ignore();
		//printf("%s\n", str);
		if(stra == "Sleep")
		{
			cin >> stra;
			cin.ignore();
			//cout << stra << endl;
			// //printf("oi\n");
			// scanf(" %s", str);
			// //printf("%s\n", str);

			// tam = strlen(str);
			// for(j = 0; j <= tam; j++)
			// {
			// 	stra.push_back(str[j]);
			// }
			st.push(stra);
		}
		else if(stra == "Test")
		{
			if(st.empty())
				printf("Not in a dream\n");
			else
			{
				cout << st.top() << endl;
				// //printf("-> ");
				// tam = st.top().size();
				// for(j = 0; j < tam; j++)
				// {
				// 	printf("%c", st.top());
				// }
				// printf("\n");
			}
		}
		else
		{
			if(!st.empty())
				st.pop();
		}
	}
	return 0;
}