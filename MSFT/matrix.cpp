#include <bits/stdc++.h>

int i=0,j=0,a,b,m,ma[110][110],jg;
char test;
int eoq = 0;

int main()
{

    while(scanf("%d%c",&m, &test) != EOF)
    {
        eoq++;
        ma[i][j]=m;
        if(test == ' ')
        {
            j++;
        }
        else if(test=='\n')
        {
            i++;
            jg = j;
            j = 0;
        }

    }
    
    for(int a=0; a<=jg; a++)
    {
        for(int b=0; b<i; b++)
        {
            printf("%d ",ma[b][a]);
        }
        printf("\n");
    }

    return 0;
}
