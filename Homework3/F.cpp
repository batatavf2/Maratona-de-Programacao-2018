#include <bits/stdc++.h>

using namespace std;

long long int fastExp(long long int x, long long int y, long long int mod)
{
    x = x%mod;
    if(y == 1)
        return x;
    if(y == 0)
        return 1;

    if(y%2 == 0)
    {
        int k = fastExp(x, y/2, mod);
        return (k%mod)*(k%mod)%mod;
    }
    else
        return (x*fastExp(x, y-1, mod))%mod;
}
int main()
{
    long long int a, b, n, mod;

    while(scanf("%lld", &n) && n != 0)
    {
        for(int i = 1; i <= n; i++){
            scanf("%lld %lld %lld", &a, &b, &mod);
            printf("%lld\n", fastExp(a%mod, b, mod)%mod);
        }
    }
    return 0;
}