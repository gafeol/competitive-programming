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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const ll INF = (ll)0x3f3f3f3f3f3f3f3f;

int n, m, k;
ll s[MAXN];

template<typename T> inline T sq(T x) { return x*x; }


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
typedef point<double> ptd;

ll sq(ll a){ return a*a; }

// v is the pointset, w is auxiliary with size at least equal to v's
ll closest_pair (ptl * v, ptl * w, int l, int r, bool sorted = 0) { // nlg | r is exclusive 
	if (l + 1 >= r) return INF;
	if (!sorted) sort(v+l,v+r,[](ptl a, ptl b){ return a.x < b.x; });
	int m = (l+r)/2; ll x = v[m].x;
	ll res = min(closest_pair(v,w,l,m,1),closest_pair(v,w,m,r,1));
	merge(v+l,v+m,v+m,v+r,w+l,[](ptl a, ptl b){ return a.y < b.y; });
	for (int i = l, s = l; i < r; i++) if (sq((v[i] = w[i]).x - x) < res) {
		for (int j = s-1; j >= l && sq(w[i].y - w[j].y) < res; j--)
			res = min(res, w[i].dist_sqr(w[j]));
		w[s++] = v[i];
	}
	return res;
}

ptl v[MAXN], w[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		if(a > 0)
			s[a] += s[a-1];
		v[a] = ptl(a, s[a]);
	}
	printf("%lld\n", closest_pair(v, w, 0, n));
}

