#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 100010;

int n;

const double EPS = 1e-8;

struct ptd{
	double x, y;

	ptd operator+ (ptd o) const {
		return {x+o.x, y+o.y};
	}
	ptd operator- (ptd o) const {
		return {x-o.x, y-o.y};
	}
	ptd operator/ (double k) const {
		return {x/k, y/k};
	}
	double operator~ () const {
		return hypot(x, y);
	}
	double operator^ (ptd o) const{
		return x*o.y - y*o.x;
	}
};

double ds(ptd a, ptd b){ // AO QUADRADO
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

struct circle{
	ptd c;
	double r;
};

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

bool in(ptd p, circle c){
	if(ds(p, c.c) <= c.r*c.r + EPS) // Imprecisao
		return 1;
	return 0;
}

vector<ptd> v;

circle cover3(ptd p, ptd q, ptd r){
	//printf("p %f %f q %f %f r %f %f\n", p.x, p.y, q.x, q.y, r.x, r.y);
	line a = line(p, q);
	line b = line(q, r);
	ptd ma = (p+q)/2.;
	ptd orta = {a.a, a.b};
	ptd oa = ma + orta;
	ptd mb = (r+q)/2.;
	ptd ortb = {b.a, b.b};
	ptd ob = mb + ortb;

	line pa = line(ma, oa);
	line pb = line(mb, ob);
	ptd c = pa.inter(pb);
	double ra = sqrt(ds(c, p));
	//printf("CIRCLE x %f y %f r %f\n", c.x, c.y, ra);
	return {c, ra};
}

circle cover2(vector<ptd> points, ptd q, ptd r){
	//printf("cover2 %f %f %f %f\n", q.x, q.y, r.x, r.y);
	circle c = {(q + r)/2., (~(q - r))/2.};
	//printf("circle c %f %f r %f\n", c.c.x, c.c.y, c.r);
	random_shuffle(points.begin(), points.end());	
	for(ptd p: points){
		if(in(p, c)) continue;
		c = cover3(p, q, r);
	}
	return c;
}

circle cover1(vector<ptd> points, ptd q){
	circle c = {q, 0};
	random_shuffle(points.begin(), points.end());	
	for(int i=0;i<points.size();i++){
		ptd p = points[i];
		vector<ptd> aux;
		if(in(p, c)) continue;
		for(int j=0;j<i;j++)
			aux.pb(points[j]);
		c = cover2(aux, q, p);
	}
	return c;
}

circle cover(vector<ptd> points){
	circle c = {points[0], 0};
	random_shuffle(points.begin(), points.end());
	for(int i=0;i<points.size();i++){
		ptd p = points[i];
		if(in(p, c)) continue;
		vector<ptd> aux;
		for(int j=0;j<i;j++)
			aux.pb(points[j]);
		c = cover1(aux, p);
	}
	return c;
}

typedef long long ll;

typedef pair<ll, ll> pii;
#define fst first
#define snd second

ll cross(pii a, pii b, pii c){
	return (b.fst - a.fst)*(c.snd - a.snd) - (b.snd - a.snd)*(c.fst - a.fst);
}

pii s[MAXN];

ll dist(int i, int j){
	return (s[i].fst - s[j].fst)*(s[i].fst - s[j].fst) + (s[i].snd - s[j].snd)*(s[i].snd - s[j].snd);
}

int main (){
	scanf("%d", &n);
	int ok = 0;
	for(int a=0;a<n;a++){
		double x, y;
		ll xx, yy;
		scanf("%lld %lld", &xx, &yy);
		x = (double)xx;
		y = (double)yy;
		s[a] = pii(xx, yy);
		ptd p = {x, y};
		v.push_back(p);
		//printf("v[%d] %.5Lf %.5Lf\n", a, v[a].x, v[a].y);
		if(a > 1){
			if(cross(s[0], s[1], s[a]) != 0)
				ok = 1;
		}
	}
	circle res;
	if(ok == 0){
		int o = 0;
		ll mx = LLONG_MIN, mxu;
		for(int i=1;i<n;i++){
			if(mx < dist(o, i)){
				mx = dist(o, i);
				mxu = i;
			}
		}
		o = mxu;
		ptd p = v[o];
		mx = LLONG_MIN;
		for(int i=0;i<n;i++){
			if(mx < dist(o, i)){
				mx = dist(o, i);
				mxu = i;
			}
		}
		ptd q = v[mxu];
		res = {(q + p)/2., (~(q - p))/2.};
	}
	else
		res = cover(v);
	printf("%.20f\n%.20f\n%.20f\n", res.c.x, res.c.y, res.r);
}

