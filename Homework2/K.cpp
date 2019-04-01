#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x[2050],i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        //printf("vai\n");
        scanf("%d",&x[i]);

    }
    //printf("oi");
    sort(x,x+n);
    //printf("eoq");
    vector<int> c;
    c.push_back(1);
    
    //printf("%d\n", c[0]);
    for(i=0;i<n;i++)
    {
        //printf("%d\n", x[i]);
        c[x[i]]++;
    }

    for(i = 0; i < n; i++)
    {
        if(c[i] > 0)
            printf("%d aparece %d vez(es)\n", i, c[i]);
    }
    return 0;
}