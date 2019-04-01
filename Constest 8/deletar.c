#include <bits/stdc++.h>

char *strstrstr(char *s1,char *s2)
{
    int ok=0,t1=0,t2=0;
    char *p=s1,*q=s2,*ptr=NULL;

    while(*(p+t1)!='\0')
    {
        t1++;
    }
    while(*(q+t2)!='\0')
    {
        t2++;
    }

    for(int i=0;i<t1;i++)
    {
        if(*(p+i)==*q)
        {
            for(int j=0;j<t2;j++)
            {
                if((p+i+j)!=(q+j))
                {
                    ok=1;
                }
            }
            if(ok==0)
            {
                q=&s1[i];
            }
        }
    }
    if(ok==0)
        return q;
    else
        return ptr;
}

int main()
{
    char n1[1000],n2[1000],l;
    char *k=n1;
    printf("Digite a primeira string: ");
    scanf("%[^\n]s" ,n1);
    printf("Digite a segunda string: ");
    scanf(" %[^\n]s", n2);
    for(int i=0;i<strlen(n1);i++)
        printf("%c",*(k+i));
    printf("\n");
     << *strstrstr(n1,n2) << endl;

    printf("%c",l);

    return 0;

}