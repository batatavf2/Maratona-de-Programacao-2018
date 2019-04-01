#include <bits/stdc++.h>

using namespace std;

set<string> sete;
string str;
int t;

void cycleShift(string str, int n)
{
	if(n > 0)
	{
		string aux;
		aux = str[t-1] + str;
		//cout << aux << endl;
		aux.erase(aux.end() - 1);
		//cout << " - " << aux << endl;
		sete.insert(aux);
		cycleShift(aux, n-1);
	}
}

int main()
{
	cin >> str;
	sete.insert(str);
	t = str.length();
	cycleShift(str, t);
	printf("%d\n", (int) sete.size());

	return 0;

}