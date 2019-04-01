#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, r;
	vector<int> v;
	while(scanf("%d", &n) && n != 0)
	{
		v.clear();
		for(i = 0; i < n; i++)
		{
			scanf("%d", &r);
			v.push_back(r);
		}
		sort(v.begin(), v.end());
		do
		{
			for(i = 0; i < n; i++)
				printf("%d ", v[i]);
			printf("\n");
		}while(next_permutation(v.begin(), v.end()));
	}

	return 0;
}