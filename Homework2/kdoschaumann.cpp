#include<stdio.h>
#include<string.h>
 
int main()
{
    int n,a,i,num[2010];
    scanf("%d",&n);
    memset(num,0,sizeof(num));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        num[a]++;
    }
    for(i=0;i<2010;i++)
    {
        if(num[i] != 0)
        {
            printf("%d aparece %d vez(es)\n",i,num[i]);
        }
    }
    return 0;
}