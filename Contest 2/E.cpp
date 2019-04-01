#include<bits/stdc++.h>

char str[150];
int countStr(char text[])
{
	int i, j, c = 0, t1, t2;
	t1 = strlen(str);
	t2 = strlen(text);

	for(i = 0; i < t1; i++)
	{
		for(j = 0; j < t2; j++)
		{
			if(str[i+j] != text[j])
				break;
			if(j == t2-1)
				c++;
		}
	}
	return c;
}

int main()
{
	int s = 0;
	scanf("%s", str);
	char text[10];
	strcpy(text, "Danil");
	s += countStr(text);
	strcpy(text, "Olya");
	s += countStr(text);
	strcpy(text, "Slava");
	s += countStr(text);
	strcpy(text, "Ann");
	s += countStr(text);
	strcpy(text, "Nikita");
	s += countStr(text);
	if(s == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}