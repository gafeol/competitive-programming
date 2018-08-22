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

const int MAXN = 212345;

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

// convex hull - modifique como necessario
int convex_hull(pti p[], pti st[], int n) {
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
	return sn;
}


int n, m, k;

pti s[MAXN];

set<pii> q;

void add(int i, int j){
	pii p = pii(i, j);
	auto it = q.lower_bound(p);
	while(1){
		auto bef = it;
		if(q.begin() == bef) 
			break;
		bef--;
		if(bef->snd > p.snd)
			break;
		debug("erase %d %d\n", bef->fst, bef->snd);
		q.erase(bef);
	}
	if(it != q.end() && it->snd >= p.snd) return;
	debug("insert %d %d\n", i, j);
	q.insert(p);
}



pti cv[MAXN];
pti ss[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		s[a] = pti(i, j);
		ss[a] = s[a];
	}
	int tam = convex_hull(ss, cv, n);

	for(int a=0;a<tam;a++){
		debug("cv %d %d\n", cv[a].x, cv[a].y);
		add(cv[a].x, cv[a].y);
	}

	for(int a=0;a<n;a++){
		debug("a %d\n", a);
		if(q.find(pii(s[a].x, s[a].y)) != q.end()){
			debug("find %d %d\n", s[a].x, s[a].y);
			printf("%d ", a+1);
		}
	}
	puts("");
}
