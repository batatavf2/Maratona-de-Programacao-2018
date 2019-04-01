#include <bits/stdc++.h>

using namespace std;

int main()
{
	multiset<vector<int> > st;
	multiset<vector<int> >::iterator it;
	multiset<vector<int> >::iterator it2;
	vector<int> scan;
	int n, i, aux, mostP, sum;
	while(scanf("%d", &n) && n != 0)
	{
		st.clear();
		sum = 0;
		mostP = 0;
		for(i = 1; i <= n; i++)
		{
			scan.clear();
			for(int j = 1; j <= 5; j++)
			{
				scanf("%d", &aux);
				scan.push_back(aux);
			}
			sort(scan.begin(), scan.end());
			//printf("\n");
			// for(int a = 0; a <= 4; a++)
			// 	printf("%d ", scan[a]);
			// printf("\n");

			st.insert(scan);
		}
		for(it = st.begin(); it != st.end(); it++)
		{
			if(st.count(*it) > mostP)
				mostP = st.count(*it);

		}
		for(it = st.begin(); it != st.end(); it++)
		{
			
			if(st.count(*it) == mostP && (sum == 0 ||*it != *it2)){
				it2 = it;
				sum += mostP;
			}

		}
		printf("%d\n", sum);
	}
	return 0;
}