#include <bits/stdc++.h>

int main()
{
	int a1, a2, n;
	char b1, b2, c1, c2, d1, d2;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%c%c%c", &a1, &b1, &c1, &d1);
		scanf("%d%c%c%c", &a2, &b2, &c2, &d2);
		printf("Group %d: ", i);

		if(a1 == a2)
			printf("%d", a1);
		else
			printf("%d", 6-a1-a2);

		if(b1 == b2)
			printf("%c", b1);
		else
			printf("%c", 'E' + 'S' + 'F' - b1 - b2);


		if(c1 == c2)
			printf("%c", c1);
		else
			printf("%c", 'R' + 'P' + 'G' - c1 - c2);


		if(d1 == d2)
			printf("%c", d1);
		else
			printf("%c", 'O' + 'S' + 'D' - d1 - d2);

		printf("\n");
	}
	return 0;
	
}

