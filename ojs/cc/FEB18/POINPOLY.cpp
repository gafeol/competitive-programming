#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

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
typedef point<ll> pti;
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

const int MAXN = 212345;

int n, m, k;
pti s[MAXN];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll ext(pti a, pti b){
	if(a.x == b.x)
		return abs(a.y - b.y) - 1;
	if(a.y == b.y)
		return abs(a.x - b.x) - 1;
	ll dx = abs(a.x - b.x);
	ll dy = abs(a.y - b.y);
	return gcd(dx, dy) - 1;
}

vector<pti> res;

void extc(pti a, pti b){
	debug("extc %lld %lld - %lld %lld\n", a.x, a.y, b.x, b.y);
	if(a.x == b.x){
		ll ini = min(a.y, b.y);
		ll fim = max(a.y, b.y);
		for(ll i=1;ini + i < fim && res.size() < n/10;i++){
			debug("add %lld %lld\n", a.x, ini+i);
			res.pb(pti(a.x, ini+i));	
		}
		return ;
	}
	if(a.y == b.y){
		ll ini = min(a.x, b.x);
		ll fim = max(a.x, b.x);
		debug("x ini %lld fim %lld\n", ini, fim);
		for(ll i=1;ini + i < fim && res.size() < n/10;i++){
			debug("add %lld %lld\n", ini+i, a.y);
			res.pb(pti(ini+i, a.y));	
		}
		return ;
	}
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	ll g = gcd(dx, dy);
	pti st = pti(dx/g, dy/g);
	if((a.x < b.x && st.x < 0) || (a.x > b.x && st.x > 0))
		st = st*(-1);
	a = a + st;
	while(a.x != b.x  && res.size() < n/10){
		debug("add %lld %lld\n", a.x, a.y);
		res.pb(a);
		a = a + st;
	}
}


map<pti, int> mrk;

bool in(pti a, pti b, pti c, pti o){
	debug("point %lld %lld inside %lld %lld %lld %lld %lld %lld : %d\n", o.x, o.y, a.x, a.y, b.x, b.y, c.x, c.y, (int)(sign(cross(a, b, o)) == sign(cross(b, c, o)) && sign(cross(b, c, o)) == sign(cross(c, a, o))));
	if(cross(a, b, o) == 0 || cross(b, c, o) == 0 || cross(c, a, o) == 0) return false;
	return (sign(cross(a, b, o)) == sign(cross(b, c, o)) && sign(cross(b, c, o)) == sign(cross(c, a, o)));
}

pti d[] = {pti(1, 1), pti(-1, -1), pti(1, -1), pti(-1, 1), pti(0, 1), pti(1, 0), pti(-1, 0), pti(0, -1)};


void go(pti a, pti b, pti c){
	if(cross(a, b, c) == 0) return ;
	queue<pti> q;
	q.push(a);	
	q.push(b);
	q.push(c);
	while(!q.empty() && res.size() < n/10){
		pti u = q.front();
		q.pop();
		for(int i=0;i<8;i++){	
			pti v = u + d[i];
			if(in(a, b, c, u + d[i]) && mrk.find(u+d[i]) == mrk.end()){
				mrk[v] = 1;
				q.push(v);
				res.pb(v);
			}
		}
	}
}

int main (){
	for_tests(t, tt){
		mrk.clear();
		scanf("%d", &n);
		ll e = 0;
		ll ar = 0;
		for(int a=0;a<n;a++){
			scanf("%lld %lld", &s[a].x, &s[a].y);
			if(a > 0)
				e += ext(s[a], s[a-1]);		
			if(a > 1)
				ar += abs(cross(s[0], s[a], s[a-1]));
		}
		e += ext(s[n-1], s[0]);
		e += n;
		ll in = (ar - e)/2 + 1;
		if(in < n/10){
			puts("-1");
			continue;
		}
		for(int a=2;a<n;a++){
			if(a != n-1 && cross(s[0], s[a-1], s[a]) != 0 && cross(s[0], s[a], s[a+1]) != 0)
				extc(s[a], s[0]);
			go(s[0], s[a-1], s[a]);		
		}
		for(int a=0;a<res.size();a++){
			debug("%lld %lld\n", res[a].x, res[a].y);
		}
		debug("ans \n");
		for(int a=0;a<n/10;a++)
			printf("%lld %lld\n", res[a].x, res[a].y);
		res.clear();
	}
}

