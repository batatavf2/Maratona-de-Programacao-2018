#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	map<pair<int, int>, string> mapa;
	pair<int, int> scan;
	string name;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d ", &scan.first, &scan.second);
		cin >> name;
		mapa[scan] = name;
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &scan.first, &scan.second);
		printf("%s\n", mapa[scan].c_str());
	}
	return 0;
}