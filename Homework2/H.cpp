#include <bits/stdc++.h>

using namespace std;

int v[100005], n, s, r;

int bSearch(int c, int f, int val)
{
	int mid = (c+f)/2;
	// printf("c: %d, f: %d, mid: %d\n", c, f, mid);
	// printf("v[mid] = v[%d] = %d, val = %d\n", mid, v[mid], val);
	if(c > f){
		//printf("kd vc mermãaao\n");
		return -1;
	}
	else if(c == f)
	{
		if(v[mid] == val){
			//printf("achei\n");
			return mid;
		}
		else{
			//printf("fuck, kd vc\n");
			return -1;
		}
	}
	else
	{
		//printf("c < f\n");
		if(v[mid] < val)
		{
			return bSearch(mid+1, f, val);
		}
		else if(v[mid] > val)
		{
			return bSearch(c, mid-1, val);
		}
		else
		{
			//printf("achei, mas quero o menor\n");
			return bSearch(c, mid, val);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	for(int i = 0; i < s; i++)
	{
		scanf("%d", &r);
		printf("%d\n", bSearch(0, n-1, r));
	}
	return 0;
}