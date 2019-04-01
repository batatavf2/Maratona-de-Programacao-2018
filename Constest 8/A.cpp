#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
using namespace std;

stack<int> pilha;
map<int, int > par;
int nex[500005], pre[500005], n, cursor;
string str;
char command;

void cr(int start)
{
	while(start < n)
	{
		if(start == cursor)
			printf("^");
		else
			printf("_");
		start = nex[start];
		
	}
	printf("\n");
}

void pr(int start)
{
	int aux = start;
	while(start < n)
	{
		printf("%c", str[start]);
		start = nex[start];
	}
	printf("\n");
	
	//cr(aux);
}


int main()
{
	int numOp, start = 0;
	scanf("%d %d %d ", &n, &numOp, &cursor);
	int foca = n-1;
	cursor--;

	cin >> str;
	//cout << str;


	
	for(int i = 0; i < n; i++)
	{
		nex[i] = i+1;
		pre[i+1] = i;
		if(str[i] == '(')
			pilha.push(i);
		else
		{
			par[i] = pilha.top();
			par[pilha.top()] = i;
			pilha.pop();
		}
	}


	//pr(start);

	// for(int i = 0; i < n; i++)
	// {
	// 	printf("%d ", par[i]);
	// }
	// printf("\n");

	// while(start < n)
	// {
	// 	printf("%c", str[start]);
	// 	start = nex[start];
	// }
	// start = 0;

	for(int i = 0; i < numOp; i++)
	{
		scanf(" %c", &command);
		//printf("command: _%c_\n", command);
		//db(foca);
		if(command == 'L' && cursor > start)
			cursor = pre[cursor];
		else if(command == 'R' && cursor < foca)
			cursor = nex[cursor];
		else
		{
			int ini = min(par[cursor], cursor), fim = max(par[cursor], cursor);
			//db(ini);
			//db(fim);
			if(ini != start)
			{
				nex[pre[ini]] = nex[fim];
				pre[nex[fim]] = pre[ini];
			}
			else
				start = nex[fim];
			if(fim < foca)
			{
				cursor = nex[fim];
			}
			else
			{
				cursor = pre[ini];
				foca = cursor;
			}
			//db(start);

		}

		//pr(start);
	}
	pr(start);
	
	
	return 0;
}