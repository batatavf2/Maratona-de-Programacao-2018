#include <bits/stdc++.h>
#define push_back pb
using namespace std;

typedef long double ld;
const double EPS = 1e-9, PI = acos(-1.);

// Change long double to long long if using integers
typedef double type;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
	type x, y;

	point() : x(0), y(0) {}
	point(type x, type y) : x(x), y(y) {}

	point operator -() { return point(-x, -y); }
	point operator +(point p) { return point(x+p.x, y+p.y); }
	point operator -(point p) { return point(x-p.x, y-p.y); }

	point operator *(type k) { return point(k*x, k*y); }
	point operator /(type k) { return point(x/k, y/k); }

	type operator *(point p) { return x*p.x + y*p.y; }
	type operator %(point p) { return x*p.y - y*p.x; }

	int dir(point o, point p) {
		type x = (*this - o) % (p - o);
		return ge(x,0) - le(x,0);
	}

	bool point_inside_convex_poly(int l, int r, vector<point> v, point p) {
		bool ans = false;
		while(l <= r) {
			// int m = (l+r)/2;
			// if (p.dir(v[0], v[m])) r = m;
			// else l = m;
			ans  = ans || point_inside_triangle(p, v[0], v[l], v[r]);
		}
		return ans;
	}
}
int main()
{
	int s, r, m, n;
	vector<point> S, R, M;
	point eq;
	type x, y;

	//Scan Walls
	scanf("%d %d %d", &s, &r, &m);
	for(int i = 1; i <= s; i++)
	{
		scanf("%lf %lf", &x, &y);
		S.pb(point(x, y));
	}
	for(int i = 1; i <= r; i++)
	{
		scanf("%lf %lf", &x, &y);
		R.pb(point(x, y));
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%lf %lf", &x, &y);
		M.pb(point(x, y));
	}

	//Scan Equipaments
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &x, &y);
		eq = point(x, y);
		
	}

	return 0;
}