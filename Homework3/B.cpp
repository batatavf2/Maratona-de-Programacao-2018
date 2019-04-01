#include <bits/stdc++.h>

using namespace std;

typedef struct tri
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
}tri;

int sq2Area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1 - y2);
	return area*area;
}

bool isRight(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if(sq2Area(x1, y1, x2, y2, x3, y3) == 0)
		return false;

	int a2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
	int b2 = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);
	int c2 = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
	int hyp2 = max(max(a2,b2), max(b2, c2));

	if(2*hyp2 == a2+b2+c2)
		return true;
	return false; 
}



string checkTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if(isRight(x1, y1, x2, y2, x3, y3))
		return "RIGHT";
	else
	{
		if(isRight(x1+1, y1, x2, y2, x3, y3))
			return "ALMOST";
		if(isRight(x1-1, y1, x2, y2, x3, y3))
			return "ALMOST";
		if(isRight(x1, y1+1, x2, y2, x3, y3))
			return "ALMOST";
		if(isRight(x1, y1-1, x2, y2, x3, y3))
			return "ALMOST";
		if(isRight(x1, y1, x2+1, y2, x3, y3))
			return "ALMOST";
		if(isRight(x1, y1, x2-1, y2, x3, y3))
			return "ALMOST";
		if(isRight(x1, y1, x2, y2+1, x3, y3))
			return "ALMOST";
		if(isRight(x1, y1, x2, y2-1, x3, y3))
			return "ALMOST";
		if(isRight(x1, y1, x2, y2, x3+1, y3-1))
			return "ALMOST";
		if(isRight(x1, y1, x2, y2, x3-1, y3))
			return "ALMOST";
		if(isRight(x1, y1, x2, y2, x3, y3+1))
			return "ALMOST";
	}
	return "NEITHER";
}

int main()
{
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%s\n", checkTriangle(x1, y1, x2, y2, x3, y3).c_str());
	return 0;
}