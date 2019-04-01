#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b ,n;
	char owners[100005];
	scanf("%d %d %d", &n, &a, &b);
	scanf(" %s", owners);
	if(owners[a-1] == owners[b-1])
		printf("0\n");
	else
		printf("1\n");

	return 0;
}