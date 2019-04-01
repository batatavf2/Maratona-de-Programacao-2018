#include <bits/stdc++.h>

using namespace std;

int main()
{
	int def[11], ata[11];
	int nDef, nAta;

	while(scanf("%d %d", &nAta, &nDef) && nDef||nAta)
	{
		for (int i = 0; i < nAta; i++)
		{
			scanf("%d", &ata[i]);
		}
		for (int i = 0; i < nDef; i++)
		{
			scanf("%d", &def[i]);
		} 
		sort(def, def + nDef);
		sort(ata, ata + nAta);
		if(ata[0] < def[1])
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}