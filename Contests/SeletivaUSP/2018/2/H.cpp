// Fence - CEOI 2008
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

const int MAXN = 112;
const int INF = 0x3f3f3f3f;

int n, m, k;

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
	return sn;
	// st[0..sn-1] agora tem o convex hull dos pontos p
}

pti s[MAXN], cv[MAXN], pt[MAXN];
int d[MAXN][MAXN], adj[MAXN][MAXN];

vector<pti> p;
int tam;

inline bool in(pti x){
	//debug("in %d %d\n", x.x, x.y);
	for(int a=0;a<tam;a++){
		int aa = (a+1)%tam;
		//debug("cross((%d, %d), (%d, %d) = %d\n", cv[a].x, cv[a].y, cv[aa].x, cv[aa].y, cross(cv[a], cv[aa], x));
		if(cross(cv[a], cv[aa], x) > 0)
			return false;
	}
	return true;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++)
		scanf("%d %d", &s[a].x, &s[a].y); 
	for(int a=0;a<m;a++)
		scanf("%d %d", &pt[a].x, &pt[a].y); 
	if(n < 3){
		printf("%d\n", 111*m);
		return 0;
	}
	tam = convex_hull(s, cv, n);
	for(int a=0;a<m;a++){
		if(in(pt[a])){
			p.pb(pt[a]);
			//debug("inp %d %d\n", pt[a].x, pt[a].y);
		}
	}
	if(p.empty()){
		printf("%d\n", 111*m);
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j) continue;
			int ok = 1;
			for(int a=0;a<p.size();a++){
				if(cross(s[i], s[j], p[a]) > 0)
					ok = 0;
			}
			if(ok){
				d[i][j] = 1;
				debug("i %d -> j %d\n", i, j);
			}
		}
	}
	int cyc  = INT_MAX;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i == j && j == k) continue;
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				if(i == j)
					cyc = min(cyc, d[i][k]+d[k][j]);
			}
		}
	}
	assert(cyc != INT_MAX);
	printf("%d\n", 20*cyc + 111*(m-(int)p.size()));
	debug("cyc %d m %d psz %d\n", cyc, m, (int)p.size());
}

