// QUEBRANDO COM in2 e c
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
typedef line<ll> lni;
typedef line<double> lnd;

int convex_hull(vector<pti> &p, vector<pti> &st, int n) {
	sort(p.begin(), p.end());
	int sn = 0;
	for(int i = 0; i < n; i++) {
		while(sn >= 2 && cross(st[sn - 2], st[sn - 1], p[i]) >= 0){
			st.pop_back();
			sn--;
		}
		st.pb(p[i]);
		sn++;
	}
	int k = sn;
	for(int i = n - 2; i >= 0; i--) {
		while(sn > k && cross(st[sn - 2], st[sn - 1], p[i]) >= 0){
			st.pop_back();
			sn--;
		}
		st.pb(p[i]);
		sn++;
	}
	st.pop_back();
	sn--;
	return sn;
}

/*
int convex_hull2(pti p[], pti st[], int n) {
	sort(p, p + n);
	int sn = 0;
	for(int i = 0; i < n; i++) {
		while(sn >= 2 && cross(st[sn - 2], st[sn - 1], p[i]) >= 0)
			sn--;
		st[sn++] = p[i];
	}
	int k = sn;
	for(int i = n - 2; i >= 0; i--) {
		while(sn > k && cross(st[sn - 2], st[sn - 1], p[i]) >= 0)
			sn--;
		st[sn++] = p[i];
	}
	sn--;
	return sn;
}

vector<pti> convex2(vector<pti> pts){
	pti v[MAXN];
	pti c[MAXN];
	int n = pts.size();
	if(n < 3) return pts;
	for(int a=0;a<n;a++)
		v[a] = pts[a];
	int tam = convex_hull2(v, c, n);	
	vector<pti> ans;
	ans.clear();
	for(int a=0;a<tam;a++)
		ans.pb(c[a]);
	return ans;
}
*/

int n, m, k;
pti s[MAXN];

vector<pti> cv[30]; 

void convex(vector<pti> &pts, vector<pti> &ref){
	int n = pts.size();
	if(n < 3){ 
		ref = pts;
		return ;
	}
	int tam = convex_hull(pts, ref, pts.size());	
}

map<pti, int> in;

vector<pti> v;

void add(pti p){
	if(in.find(p) != in.end())
		return ;
	v.pb(p);
	in[p] = 1;
	vector<pti> pts;
	pts.clear();
	pts.pb(p);
	int i = 29;
	while(i > 0 && cv[i-1].size() <= pts.size()){
		for(int j=0;j<cv[i-1].size();j++)
			pts.pb(cv[i-1][j]);
		cv[i-1].clear();
		i--;
	}
	convex(pts, cv[i]); 
}

char t[MAXN];

ll A, B;

inline ll f(pti o){
	return A*o.x + B*o.y;
}


inline ll mx(vector<pti> &c, ll a, ll b){
	int i = 1, j = c.size()-1;
	pti centro = c[0];
	pti paral = c[0] + pti(-b, a);

	if(c.size() < 5){
		ll ans = LLONG_MIN;
		for(int a=0;a<c.size();a++)
			ans = max(ans, f(c[a]));
		return ans;
	}

	int sig = sign(cross(centro, c[1], paral));
	i = 2;
	while(i < j){
		int m = (i+j+1)/2;
		if(sign(cross(centro, c[m], paral))*sig < 0)
			j = m-1;	
		else
			i = m;
	}
	if(sign(cross(centro, c[i], paral)*sig < 0))
		i--;

	ll res = LLONG_MIN;

	int L = 0;
	int R = i;
	res = max(res, f(c[0]));
	res = max(res, f(c[1]));
	res = max(res, f(c[c.size()-1]));
	res = max(res, f(c[i]));
	if(i > 0)
		res = max(res, f(c[i-1]));
	if(i < c.size()-1)
		res = max(res, f(c[i+1]));
	i = 0;
	while(j - i >= 3){
		int m1 = i + (j - i)/3; 
		int m2 = j - (j - i)/3;
		if(f(c[m1]) < f(c[m2]))
			i = m1;	
		else
			j = m2;
	}
	for(int a=i;a<=j;a++)
		res = max(res, f(c[a]));
	
	i = min((int)c.size()-1, R+1);
	j = c.size()-1;
	res = max(res, f(c[i]));
	res = max(res, f(c[j]));
	while(j - i >= 3){
		int m1 = i + (j - i)/3;
		int m2 = j - (j - i)/3;
		if(f(c[m1]) < f(c[m2]))
			i = m1;
		else
			j = m2;
	}
	for(int a=i;a<=j;a++)
		res = max(res, f(c[a]));
	return res;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &s[a].x, &s[a].y);
		add(s[a]);
	}
	scanf("%d", &m);
	while(m--){
		ll x, y;
		scanf(" %s %lld %lld", t, &x, &y);
		if(t[0] == 'g'){
			A = x;
			B = y;

			ll res = LLONG_MIN;
			for(int a=0;a<30;a++){
				if(!cv[a].empty())
					res = max(res, mx(cv[a], x, y));
			}
			/*
			ll ans = LLONG_MAX;
			for(pti p: v){
				ans = max(ans, f(p));
			}
			assert(ans == res);
			*/
			printf("%lld\n", res);
		}
		else
			add(pti(x, y));
	}
}
