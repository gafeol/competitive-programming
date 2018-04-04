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
const int MAXX = 11234;

int n[4], m, k;

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


vector<pti> p[3];

map<int, map<int, int> > dw[2], up[2];

int sdw[2][MAXN], sup[2][MAXN];

int main (){
	int test = 1;
	while(scanf("%d%d%d", &n[0], &n[1], &n[2]) != EOF && n[0] + n[1] + n[2] >= 0){
		memset(sup, 0, sizeof(sup));
		memset(sdw, 0, sizeof(sdw));
		for(int a=0;a<2;a++){
			dw[a].clear();
			up[a].clear();
		}
		for(int a=0;a<3;a++){
			p[a].clear();
		}
		for(int t=0;t<3;t++){
			for(int a=0;a<n[t];a++){
				pti po;
				scanf("%d%d", &po.x, &po.y);
				p[t].pb(po);
			}
		}
		for(int t=0;t < 3;t++)
			sort(p[t].begin(), p[t].end());


		for(int a=0;a<n[2];a++){
			for(int t=0;t<2;t++){
				for(pti po: p[t]){
					if(po.x == p[2][a].x){
						if(po.y > p[2][a].y)
							sup[t][a]++;
						else
							sdw[t][a]++;
					}
				}
			}
		}

		for(int i=0;i<n[2];i++){
			for(int j=i+1;j<n[2];j++){
				int mn = min(p[2][i].x, p[2][j].x);
				int mx = max(p[2][i].x, p[2][j].x);
				debug("linha %d %d a %d %d\n", p[2][i].x, p[2][i].y, p[2][j].x, p[2][j].y);

				for(int t=0;t<2;t++){
					for(pti po: p[t]){
						if(po.x > mx || po.x < mn) continue;
						if(cross(p[2][i], po, p[2][j]) < 0){
							dw[t][i][j]++;
							debug("	dw (%d) %d %d\n", t, po.x, po.y);
						}
						else{
							up[t][i][j]++;
							debug("	up (%d) %d %d\n", t, po.x, po.y);
						}
					}
				}
			}
		}


		int res[2];
		res[0] = res[1] = 0;

		for(int i=0;i<n[2];i++){
			for(int j=i+1;j<n[2];j++){
				for(int k=j+1;k<n[2];k++){
					int cnt[2];
					cnt[0] = cnt[1] = 0;
					for(int t=0;t<2;t++){
						cnt[t] = abs(up[t][i][k] - up[t][i][j]  - up[t][j][k] + sup[t][j]);
					}
					if(cnt[0] > cnt[1])
						res[0]++;
					else if(cnt[1] > cnt[0])
						res[1]++;
				}
			}
		}
		printf("Case %d: %d %d\n", test++, res[0], res[1]);
	}
}
