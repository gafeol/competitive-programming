#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<double, double> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const double EPS = 1e-11;

// area de calota 2.pi.R.h (h altura)
// volume de calota pi.h/6 * (3r^2 + h^2)

#include <cmath>
#define temp template<typename num>
#define ptn point<num>
temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num operator * (ptn o) const { return x * o.x + y * o.y; }
	num operator ^ (ptn o) const { return x * o.y - y * o.x; }
	ptn operator * (num i) const { return ptn(x * i, y * i); }
	ptn operator / (num i) const { return ptn(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num dist_sqr(ptn o) const { return (*this - o) * (*this - o); }
	bool operator < (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};
typedef point<int> pti;
typedef point<double> ptd;
temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^ (b - a); }
// o ponto c esta no segmento [a, b]?
temp inline bool between_seg(ptn a, ptn b, ptn c) { return cross(a, b, c) == 0 && ((b - c) * (a - c) <= 0); }
// sqr dist de c pro segmento [a, b]
temp double dist_seg_sqr(ptn a, ptn b, ptn c) {
	if((b - a) * (c - b) > 0) return b.dist_sqr(c);
	if((a - b) * (c - a) > 0) return a.dist_sqr(c);
	double d = (b - a) ^ (c - a);
	return d * d / ((b - a) * (b - a));
}
temp int sign(num x) { return (x > 0) - (x < 0); }
// [a, b] intersecta [c, d]?
temp bool inter_seg(ptn a, ptn b, ptn c, ptn d) {
	if(between_seg(a, b, c) || between_seg(a, b, d) || between_seg(c, d, a) || between_seg(c, d, b)) return true;
	if((sign(cross(a, b, c)) * sign(cross(a, b, d)) == -1) && (sign(cross(c, d, a)) * sign(cross(c, d, b)) == -1)) return true;
	return false;
}

temp struct line {
	num a, b, c;
	line() {}
	line(num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	line(ptn s, ptn e) : a(e.y - s.y), b(s.x - e.x), c(a*s.x + b*s.y) {}
	line pass(ptn p) { return line(a, b, a*p.x + b*p.y); }
	bool parallel(const line &o) const { return a * o.b - o.a * b == 0; }
	point<double> inter(line o) {
		double d = a * o.b - o.a * b;
		if(d == 0) return point<double>(0, 0); // fudeu
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};
typedef line<int> lni;
typedef line<double> lnd;

// convex hull - modifique como necessario
void convex_hull(pti p[], pti st[], int n) {
	sort(p, p + n);
	int sn = 0;
	for(int i = 0; i < n; i++) {
		while(sn >= 2 && cross(st[sn - 2], st[sn - 1], p[i]) > 0)
			sn--;
		st[sn++] = p[i];
	}
	int k = sn;
	for(int i = n - 2; i >= 0; i--) {
		while(sn > k && cross(st[sn - 2], st[sn - 1], p[i]) > 0)
			sn--;
		st[sn++] = p[i];
	}
	sn--;
	// st[0..sn-1] agora tem o convex hull dos pontos p
}

int n, m, k;
pii le, ri, s[MAXN], v[MAXN];

ptd l, r;

pii mv(int i, double t){
	pii x;
	x.fst = s[i].fst + t*v[i].fst;
	x.snd = s[i].snd + t*v[i].snd;
	return x;
}

bool insideNoB(pii a){
	return (a.fst >= le.fst && a.fst <= ri.fst && a.snd >= le.snd && a.snd <= ri.snd); 
}

const int PASSOU = 2;
const int DENTRO = 1;
const int ANTES = 0;

int in(pii i, pii j){
	int ans = 0;
	ptd ini, fim;
	ini.x = i.fst;
	ini.y = i.snd;
	fim.x = j.fst;
	fim.y = j.snd;
	ptd n1 = l;
	ptd n2 = l;
	n2.y = r.y;
	ptd n3 = r;
	ptd n4 = r;
	n4.y = l.y;
	ans += inter_seg(ini, fim, n1, n2);
	ans += inter_seg(ini, fim, n2, n3);
	ans += inter_seg(ini, fim, n3, n4);
	ans += inter_seg(ini, fim, n4, n1);
	if(between_seg(ini, fim, n1))
		ans--;
	if(between_seg(ini, fim, n2))
		ans--;
	if(between_seg(ini, fim, n3))
		ans--;
	if(between_seg(ini, fim, n4))
		ans--;
	if(insideNoB(i)){
		if(ans > 1.1)
			return PASSOU;
		else
			return DENTRO;
	}
	ans = min(ans, 2);
	return ans;
}

int go(double t){
	int mn = 5, mx = -1;
	for(int a=0;a<n;a++){
		pii p = mv(a, t);
		int val = in(s[a], p);
		//		debug("a %d s[a] %.3f %.3f p %.3f %.3f val %d\n", a, s[a].fst, s[a].snd, p.fst, p.snd, val);
		mn = min(mn, val);
		mx = max(mx, val);
	}
	if(mn == ANTES && mx == PASSOU){
		//		debug("em t %.5f\n", t);
		puts("-1");
		exit(0);
	}
	else if(mn == DENTRO)
		return mx;
	else
		return mn;
}

int main (){
	clock_t clk = clock();
	scanf("%d", &n);
	double x, xx, y, yy;
	scanf("%lf %lf %lf %lf", &x, &y, &xx, &yy); 
	if(x > xx)
		swap(x, xx);
	if(y > yy)
		swap(y, yy);
	le = pii(x, y);
	ri = pii(xx, yy);
	l.x = le.fst;
	l.y = le.snd;
	r.x = ri.fst;
	r.y = ri.snd;
	for(int a=0;a<n;a++){
		scanf("%lf %lf %lf %lf", &s[a].fst, &s[a].snd, &v[a].fst, &v[a].snd);
	}
	double i = 0, j = 1e13;
	while(((double)clock() - clk)/CLOCKS_PER_SEC < 1.8){
		double m = (i + j)/2;
		if(go(m) == ANTES)
			i = m;
		else
			j = m;
	}
	double m = (i + j)/2;
	debug("%.20f %d\n", m, go(m)); 
	if(go(m) != 1){
		puts("-1");
		return 0;
	}
	printf("%.20f\n", m);
}
