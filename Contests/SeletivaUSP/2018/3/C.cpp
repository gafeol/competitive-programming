#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
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
typedef point<ll> ptl;
temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^ (b - a); }

int convex_hull(ptl p[], ptl st[], int n) {
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
}

int n, m, k;

ptl s[MAXN*2], cv[MAXN*2];
vector<pll> ss;
int deg;

ll v[MAXN];

multiset<ll> q;

inline void add(ll x, ll y){
	ss.pb(pll(x, y));
}

int main (){
	for_tests(t, tt){
		q.clear();
		ss.clear();
		deg = 0;
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%lld", v+a);
			q.insert(v[a]);
		}
		for(int a=0;a<n-1;a++){
			q.erase(q.find(v[a]));
			add(v[a], *q.begin());
			add(v[a], *q.rbegin());
		}
		sort(ss.begin(), ss.end());
		ss.erase(unique(ss.begin(), ss.end()), ss.end());
		for(int a=0;a<ss.size();a++)
			s[deg++] = ptl(ss[a].fst, ss[a].snd);
			
		int tam = convex_hull(s, cv, deg);
		ll area = 0;			
		for(int a=0;a<tam;a++){
			int aa = (a+1)%tam;
			area += cross(ptl(0,0), cv[a], cv[aa]);
		}
		area = abs(area);
		printf("%lld\n", area);
	}
}

