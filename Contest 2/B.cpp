#include <bits/stdc++.h>

using namespace std;

multiset<int> lowers, uppers;

void printMS(multiset<int> ms)
{
	for (multiset<int>::iterator it=ms.begin(); it!=ms.end(); it++){
		cout << ' ' << *it;
	}
	printf("\n");
}

int main()
{
	int v, test;

	scanf("%d", &test);
	for(int i = 0; i < test; i++)
	{
		lowers.clear();
		uppers.clear();
		while(scanf("%d", &v) && v != 0)
		{
			if(v == -1)
			{
				//printMS(lowers);
				//printMS(uppers);
				printf("%d\n", *lowers.rbegin());
				lowers.erase(lowers.find(*lowers.rbegin()));
				if(lowers.size() < uppers.size())
				{
					lowers.insert(*uppers.begin());
					uppers.erase(uppers.begin());
				}
			}

			else
			{	
				if(!lowers.empty() && v > *lowers.rbegin())
					uppers.insert(v);
				else
					lowers.insert(v);

				if(lowers.size() < uppers.size())
				{
					lowers.insert(*uppers.begin());
					uppers.erase(uppers.begin());
				}

				if(lowers.size() - uppers.size() > 1)
				{
					uppers.insert(*lowers.rbegin());
					lowers.erase(lowers.find(*lowers.rbegin()));
				}

			}
		}
	}
	return 0;
}
