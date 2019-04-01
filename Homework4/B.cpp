#include <bits/stdc++.h>
#define mdc(x,y) __gcd((x),(y))

using namespace std;

void simplify(long long int n1,long long int n2)
{
	if(n2<0)
	{
		n1 = -n1;
		n2 = -n2;
	}
	long long int m = mdc(n1, n2);
	printf("%lld/%lld = ", n1, n2);
	n1 = n1/m;
	n2 = n2/m;
	if(n2<0)
	{
		n1 = -n1;
		n2 = -n2;
	}
	printf("%lld/%lld\n", n1, n2);
}

int main()
{
	long long int n;
	long long int n1, d1, n2, d2;
	char op;

	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld / %lld %c %lld / %lld", &n1, &d1, &op, &n2, &d2);
		if(op == '+')
			simplify(n1*d2 + n2*d1, d1*d2);
		if(op == '-')
			simplify(n1*d2 - n2*d1, d1*d2);
		if(op == '*')
			simplify(n1*n2, d1*d2);
		if(op == '/')
			simplify(n1*d2, n2*d1);
	}


	return 0;
}