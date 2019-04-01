#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r = 0, n, aux;
	bool imp = false;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &aux);
		r += aux%2;
		if(aux%2)
			imp = true;
	}
	if(imp || r%2)
		printf("First\n");
	else
		printf("Second\n");

	return 0;
}
