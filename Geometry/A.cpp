#include <bits/stdc++.h>

using namespace std;

class vec
{
public:
	double x, y;
	vec() 
	{
		x = 0;
		y = 0;
	}
	vec(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	double mod()
	{
		return pow(x*x + y*y, 0.5);
	}

	vec operator + (vec v1)
	{
		return vec(v1.x + this->x, v1.y + this->y);
	}

	vec scale(double r)
	{
		return vec(this->x * r, this->y * r);
	}

	void print()
	{
		printf("%.9lf %.9lf\n", this->x, this->y);
	}

	double operator * (vec v1)
	{
		return (this->x)*v1.x + (this->y)*v1.y;
	}

	double operator ^ (vec v1)
	{
		return (this->x)*v1.y - (this->y)*v1.x; 
	}
};



int main()
{
	double x1, x2, y1, y2;

	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	vec v1(x2-x1, y2-y1);

	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	vec v2(x2-x1, y2-y1);
	
	printf("%.9lf %.9lf\n", v1.mod(), v2.mod());
	(v1+v2).print();
	printf("%.9lf %.9lf\n", v1*v2, v1^v2);
	printf("%.9lf\n", abs(v1^v2)*0.5);
	return 0;
}