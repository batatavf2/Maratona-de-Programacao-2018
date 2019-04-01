#include <stdio.h>

char *strstrstr(char *s1,char *s2)
{
    int ok=0,t1=0,t2=0;
    char *p=s1,*q=s2, *ptr=NULL;
    // puts(p);
    // puts(s2);
    while(p[t1] != '\0')
    {
        t1++;
    }
    while(q[t2] != '\0')
    {
        t2++;
    }
    // printf("%d\n", t1);
    // printf("%d\n", t2);
    for(int i=0;i<t1;i++)
    {
        ok = 0;
        if(*(p+i) == *q)
        {
            for(int j=0;j<t2;j++)
            {
                if(*(p+i+j) == *(q+j))
                {
                    ok++;
                }
            }
            if(ok==t2)
            {
                ptr=&s1[i];
                break;
            }
        }
    }
    
    if(ptr) return ptr;
}

int main()
{
    char n1[1000],n2[1000],l;
    char *k=n1;
    printf("Digite a primeira string: ");
    scanf("%[^\n]s" , n1);
    printf("Digite a segunda string: ");
    scanf(" %[^\n]s", n2);
    // for(int i=0;i<strlen(n1);i++)
    //     printf("%c",*(k+i));
    // printf("\n");
    printf("%s\n", strstrstr(n1,n2));

    return 0;

}