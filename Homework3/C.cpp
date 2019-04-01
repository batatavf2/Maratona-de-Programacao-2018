#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int w[26], n, s = 0, tam, maxW = 0, i, a;
	char str[1005];
	scanf("%s", str);
	scanf("%lld", &n);
	for(int i = 0; i < 26; i++)
	{
		scanf("%lld", &w[i]);
		if(w[i] > maxW)
			maxW = w[i];
	}
	tam = strlen(str);
	for(i = 1; i <= tam; i++)	
	{
		s += i*w[str[i-1] - 'a'];
	}
	a = i;
	for(i = a; i < a + n; i++)
	{
		s+=maxW*i;
	}
	printf("%lld\n", s);

	return 0;
}