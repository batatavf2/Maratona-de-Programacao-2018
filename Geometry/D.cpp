#include <bits/stdc++.h>

using namespace std;

class vec
{
public:
	double x, y;//Default constructor
	vec() 
	{
		x = 0;
		y = 0;
	}
	vec(double _x, double _y)//Constructor
	{
		x = _x;
		y = _y;
	}
	double mod()
	{
		return pow(x*x + y*y, 0.5);
	}

	vec scale(double r)
	{
		return vec(this->x * r, this->y * r);
	}

	void print()
	{
		printf("%.9lf %.9lf\n", this->x, this->y);
	}

	vec operator + (vec v1)
	{
		return vec(v1.x + this->x, v1.y + this->y);
	}

	double operator * (vec v1)
	{
		return (this->x)*v1.x + (this->y)*v1.y;
	}

	double operator ^ (vec v1)//Cross Product
	{
		return (this->x)*v1.y - (this->y)*v1.x; 
	}
};

class point
{
public:
	double x, y;//Parameters
	point()//Default Constructor
	{
		x = 0;
		y = 0;
	}
	point(double _x, double _y)//Contructor
	{
		x = _x;
		y = _y;
	}

	vec getVec(point p1)
	{
		return vec(this->x - p1.x, this->y - p1.y);
	}

	double dist(point p1)
	{
		return this->getVec(p1).mod();
	}

	void print()
	{
		printf("%lf %lf ", this->x, this->y);
	}

	point operator * (double r) 
	{
		return point((this->x)*r, (this->y)*r);
	}

	point operator + (point v1)
	{
		return point(v1.x + this->x, v1.y + this->y);
	}

	double dist2seg(segment l1)
	{

	}

};

class segment
{
	point p1, p2;
	segment()
	{
		p1 = point(0, 0);
		p2 = point(0, 0);
	}

	segment(point _p1, point _p2)
	{
		p1 = _p1;
		p2 = _p2;
	}

	
};

point baricenter(point p1, point p2, point p3)
{
	return point((p1.x + p2.x + p3.x)/3, (p1.y + p2.y + p3.y)/3);
}

point incenter(point p1, point p2, point p3)
{
	double a, b, c;
	a = p2.dist(p3);
	b = p3.dist(p1);
	c = p1.dist(p2);
	p1 = p1*a;
	p2 = p2*b;
	p3 = p3*c;

	return (p1 + p2 + p3)*(1/(a+b+c));
}

double heron(point p1, point p2, point p3)
{
	double a, b, c, s;
	a = p2.dist(p3);
	b = p3.dist(p1);
	c = p1.dist(p2);
	s = 0.5*(a+b+c);
	return pow((s)*(s-a)*(s-b)*(s-c), 0.5);
}

double triPeri(point p1, point p2, point p3)
{
	double a, b, c, s;
	a = p2.dist(p3);
	b = p3.dist(p1);
	c = p1.dist(p2);
	return (a+b+c);
}

int main()
{
	double x1, y1, x2, y2, x3, y3, a, b, c;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	point p1(x1, y1), p2(x2, y2), p3(x3, y3);

	point I = incenter(p1, p2, p3);
	double area = heron(p1, p2, p3);
	I.print();
	printf("%lf\n", 2*area/triPeri(p1, p2, p3));
	return 0;
}