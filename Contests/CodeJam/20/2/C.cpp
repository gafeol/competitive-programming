#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
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
typedef point<ll> ptl;
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
typedef line<ll> lnl;
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
ptl s[MAXN];

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

ll dx[MAXN][MAXN], dy[MAXN][MAXN];

map<pll, vector<pii> > p;

void join(int i, int j){
    i = raiz(i);
    j = raiz(j);

    if(i == j) return ;
    if(sz[i]  < sz[j])
        swap(i, j);
    p[j] = i;
    sz[i] += sz[j];
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            ll i, j;
            scanf("%lld%lld", &i, &j);
            s[a] = {i, j};
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll dx = s[j].x - s[i].x;
                ll dy = s[j].y - s[i].y;
                if(min(abs(dx), abs(dy)) > 0){
                    ll gc = gcd(abs(dx), abs(dy));
                    dx /= gc;
                    dy /= gc;
                }
                if(dy < 0){
                    dx *= -1;
                    dy *= -1;
                }
                p[{dx, dy}].pb({i, j});
            }
        }
        for(auto it: p){
           vector<pii> &par = it.snd; 
           for(int a=0;a<=n;a++){
               p[a] =a;
               sz[a] = 1;
               for(pii p: par){
                    join(p.fst, p.snd);
               }
           }
           for(int a=0;a<=n;a++){
               int res = 0;
               if(sz[a] > 1 && a == p[a]){
                   res += sz[a];

               }
           }
        }
    }
}
