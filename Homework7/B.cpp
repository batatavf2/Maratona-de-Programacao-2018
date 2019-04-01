#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
using namespace std;

int p[100005], n;
int child[100005];
multiset<int> sizes;


int find(int a)
{
	while(p[a] != a)
	{
		p[a] = p[p[a]];
		a = p[a];
	}
	return a;
}

void unite(int a, int b)
{
	int b1 = find(b);
	int a1 = find(a);
	if(b1 != find(a))
	{
		sizes.erase(sizes.find(child[b1]));
		sizes.erase(sizes.find(child[a1]));
		child[a1] += child[b1];
		child[b1] = 0;
		p[b1] = a1;
		sizes.insert(child[a1]);
	}
	printf("%d\n", *sizes.rbegin() - *sizes.begin());


	// for(int i = 1; i <= n; i++)
	// {
	// 	db(find(i));
	// }
	// puts("\n");

	// for(int i = 1; i <= n; i++){
	// 	cout << child[i] << " ";
	// }
	// cout << endl;

	// for(auto t : sizes){
	// 	cout << t << " ";
	// }

}

int main()
{
	int queries, x, y;
	scanf("%d %d", &n, &queries);
	for(int i = 1; i <= n; i++)
	{
		p[i] = i;
		child[i] = 1;
		sizes.insert(1);
	}

	// for(auto t : sizes){
	// 	cout << t << " ";
	// }
	// cout << endl;

	for(int i = 1; i <= queries; i++)
	{
		scanf("%d %d", &x, &y);
		unite(x, y);
	}

	return 0;
}