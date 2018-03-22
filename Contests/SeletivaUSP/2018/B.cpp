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

pti s[MAXN];
ll acu[MAXN];
pti z;

ll inter(int i, int j){
	if(i > j) swap(i, j);
	debug("inter %lld + %lld\n", acu[j-1] - (i > 0 ? acu[i-1] : 0), -cross(z, s[i], s[j]));
	return acu[j-1] - (i > 0 ? acu[i-1] : 0) - cross(z, s[i], s[j]);
}

int main (){
	int ini = 1;
	while(scanf("%d%d", &n, &m) != EOF && n + m > 0){
		if(!ini) puts("");
		ini = 0;
		ll sum = 0;
		z = pti(0ll, 0ll);
		for(int a=0;a<n;a++)
			scanf("%lld %lld", &s[a].x, &s[a].y);

		for(int a=0;a<n;a++){
			ll val = cross(z, s[a], s[(a+1)%n]);
			sum += val;
			acu[a] = 0;
			if(a > 0)
				acu[a] = acu[a-1];
			acu[a] += val;
			debug("acu %d = %lld\n", a, acu[a]);
		}
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			ll ar = abs(sum - inter(i, j));
			debug("ar %lld\n", ar);
			ar = min(ar, abs(abs(sum) - ar));
			if(ar&1)
				printf("%lld.5\n", ar/2);
			else
				printf("%lld.0\n", ar/2);
		}
	}
}

