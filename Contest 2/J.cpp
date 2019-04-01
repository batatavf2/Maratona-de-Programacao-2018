#include <bits/stdc++.h>

using namespace std;

int main()
{
	stack<char> pilha;
	int n, i;
	char MEUDEUSQUERAIVADESSAQUESTAOPUTAQUEOPARIU, c;
	bool ok;
	char v[1000];
	scanf("%d", &n);
	scanf("%c", &MEUDEUSQUERAIVADESSAQUESTAOPUTAQUEOPARIU);
	for(int j = 0; j < n; j++)
	{
		while(!pilha.empty())
			pilha.pop();
		ok = true;

		while(true)
		{
			scanf("%c", &c);
			if(c != '\n')
			{
				//printf("%c", c);
				if(c == '(')
				{
					pilha.push(')');
					//printf("%c\n", pilha.top());
				}
				else if(c == '[')
				{
					pilha.push(']');
					//printf("%c\n", pilha.top());
				}
				else if(!pilha.empty())
				{
					if(pilha.top() != c){
						ok = false;
					}
					else
						pilha.pop();
				}
				else
					ok = false;
			}
			else
			{
				//printf("\n");
				if(ok && pilha.empty())
					printf("Yes\n");
				else
					printf("No\n");
				break;
			}

		}

	}
	return 0;
	
}