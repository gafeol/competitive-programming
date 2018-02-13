#include <bits/stdc++.h>
using namespace std;
#define pb push_back

typedef long long ll;

const double EPS = 1e-8;

struct pti{
	ll x, y;
	pti operator+ (pti o) const {
		return {x+o.x, y+o.y};
	}
	pti operator- (pti o) const {
		return {x-o.x, y-o.y};
	}
	pti operator- () const {
		return {-x, -y};
	}
	ll operator~ () const {
		return x*x + y*y;
	}
	ll operator^ (pti o) const {
		return x*o.y - y*o.x;
	}
};

struct ptd{
	double x, y;
	ptd operator+ (ptd o) const {
		return {x+o.x, y+o.y};
	}
	ptd operator- (ptd o) const {
		return {x-o.x, y-o.y};
	}
	ptd operator- () const {
		return {-x, -y};
	}
	ptd operator/ (double k) const {
		return {x/k, y/k};
	}
	double operator~ () const {
		return x*x + y*y;
	}
	double operator* (ptd o) const {
		return x*o.x+y*o.y;
	}
	ptd operator* (double k) const {
		return {x*k, y*k};
	}
	double operator^ (ptd o) const {
		return x*o.y - y*o.x;
	}
};

double dist_seg_sqr(ptd a, ptd b, ptd c){
	if((b-a)*(c-b) > 0) return sqrt(~(b - c));
	if((a-b)*(c-a) > 0) return sqrt(~(a - c));
	double d = (b - a) ^ (c - a);
	return d * d / ((b-a) * (b-a));
}

struct line{
	double a, b, c;
	line () {}
	line (double aa, double bb, double cc) : a(aa), b(bb), c(cc) {}
	line(ptd s, ptd e) : a(e.y-s.y), b(s.x - e.x), c(a*s.x + b*s.y) {}		
	ptd inter(line o){
		double d = a*o.b - o.a*b;
		return {(o.b*c-b*o.c)/d, (a*o.c-o.a*c)/d}; 
	}
};

int sign(ll x){
	return (x > 0) - (x < 0);
}

struct segi{
	pti u, v;
};

double bb(pti pp, pti aa, pti bb, pti vv){
	ptd p = {(double)pp.x, (double)pp.y};
	ptd a = {(double)aa.x, (double)aa.y};
	ptd b = {(double)bb.x, (double)bb.y};
	ptd v = {(double)vv.x, (double)vv.y};
	double i = 0, j = 1e6;	
	clock_t clk = clock();
	line l = line(a, b);
	int sig = sign(l.a*p.x + l.b*p.y + l.c);
	printf("sig %d\n", sig);
	while((clock() - clk)/CLOCKS_PER_SEC < 0.4){
		double m = (i+j)/2.;
		ptd np = p + v*m;
		if(sign(l.a*np.x + l.b*np.y + l.c) != sig)
			j = m;
		else
			i = m;
	}
	double d = dist_seg_sqr(a, b, p);
	printf("d %.5f\n", d);
	if(!(d < EPS && d > -EPS))
		d = DBL_MAX;
	return d;
}

int main (){
	segi l1, l2;
	ll x1, y1, x2, y2;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2); 
	pti p1 = {x1, y1};
	pti p2 = {x2, y2};
	l1 = {p1, p2};
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2); 
	p1 = {x1, y1};
	p2 = {x2, y2};
	l1 = {p1, p2};
	scanf("%lld%lld", &x1, &y1);
	pti v1 = {x1, y1};
	scanf("%lld%lld", &x1, &y1);
	pti v = {x1, y1};
	v = v - v1;
	
	if(((l1.u - l1.v)^(l2.u - l2.v)) == 0){
		if((v^(l1.u - l2.u)) != 0){
			puts("-1");
			return 0;
		}
		else{
			ll d = min(min(~(l1.u - l2.u), ~(l1.u - l2.v)),
						min(~(l1.v - l2.u), ~(l1.v - l2.v)));
			printf("%.10f\n", ((double)sqrt(d))/((double)sqrt(~v))); 
			return 0;
		}
	}
	else{
		double res = bb(l2.u, l1.u, l1.v, v);
		res = min(res, bb(l2.v, l1.u, l1.v, v));
		res = min(res, bb(l1.u, l2.u, l2.v, -v));
		res = min(res, bb(l1.v, l2.u, l2.v, -v));
		printf("%.10f\n", res);
	}

}
