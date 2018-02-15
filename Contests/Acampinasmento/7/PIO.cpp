#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pii;
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

const int MAXN = 412345;

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

int n;

int sc(pti a){
	if(a.x > 0 && a.y >= 0) return 0;
	if(a.x <= 0 && a.y > 0) return 1;
	if(a.x < 0 && a.y <= 0) return 2;
	return 3;
}

bool cmp(pti a, pti b){
	pti o = pti(0, 0);
	if(sc(a) != sc(b))
		return sc(a) < sc(b);
	return cross(pti(0, 0), a, b) < 0;
}

pti s[MAXN];

namespace sol {

	struct vec {
		ll x, y;

		inline vec operator + (vec o) { return {x+o.x,y+o.y}; }
		inline vec operator - (vec o) { return {x-o.x,y-o.y}; }
		inline ll operator * (vec o) { return x*o.x + y*o.y; }
		inline ll operator ^ (vec o) { return x*o.y - y*o.x; }

		inline bool operator < (const vec & o) const {
			return (x!=o.x)?x<o.x:y>o.y;
		}
	};
	ostream& operator << (ostream & os, vec o) {
		return os << "(" << o.x << "," << o.y << ")" << endl;
	}

	inline bool compare (vec a, vec b) {
		vec o; o.x = o.y = 0;
		if ((a<o) != (b<o)) return (a<o);
		return (a^b) > 0;
	}

	const int N = 2e6+7;

	int n;
	vec v[N];

	int main () {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &v[i].x, &v[i].y);
			if (v[i].x == 0 && v[i].y == 0) {
				i--; n--;
			}
		}

		sort(v, v+n, [] (vec a, vec b) { return compare(a,b); });

		vec cur; cur.x = cur.y = 0;
		for (int i = 0; i < n; i++)
			v[i+n] = v[i];
		int r = 0;
		ll res = 0;
		for (int i = 0; i < n; i++) {
			while (r < i+n && ((v[i]^v[r])?((v[i]^v[r])>0):(v[i]*v[r]>=0))) {
				cur = cur + v[r++];
				res = max(res, cur*cur);
			}
			res = max(res, cur*cur);
			cur = cur - v[i];
			res = max(res, cur*cur);
		}
		for (int i = 0; i < n; i++)
			v[i].x = -v[i].x;

		sort(v, v+n, [] (vec a, vec b) { return compare(a,b); });
		cur.x = cur.y = 0;
		for (int i = 0; i < n; i++)
			v[i+n] = v[i];
		r = 0;
		for (int i = 0; i < n; i++) {
			while (r < i+n && ((v[i]^v[r])?((v[i]^v[r])>0):(v[i]*v[r]>=0))) {
				cur = cur + v[r++];
				res = max(res, cur*cur);
			}
			res = max(res, cur*cur);
			cur = cur - v[i];
			//res = max(res, cur*cur);
		}

		printf("%lld\n", res);
	}
}

int main (){
	scanf("%d", &n);
	pti sum = pti(0, 0);
	for(int a=0;a<n;a++){
		pti p;
		scanf("%lld%lld", &p.x, &p.y);
		if(p.x == 0 && p.y == 0){
			a--;
			n--;
			continue;
		}
		s[a] = p;
		sum = sum + p;
	}
	if(n <= 1){
		printf("%lld\n", sum*sum);
		return 0;
	}
	sort(s, s+n, cmp);
	for(int a=0;a<n;a++){
		s[a+n] = s[a];
	}
	/*	for(int a=0;a<n;a++){
		debug("a %d sc %d - %lld %lld\n", a, sc(s[a]), s[a].x, s[a].y);
		}*/ 
	int i = 0, j = 0;
	ll res = 0;
	while(i < n){
		if(i >= j){
			sum = s[i];
			j = i+1;
		}
		while(j < i+n && cross(pti(0, 0), s[i], s[j]) < 0){
			res = max(res, sum*sum);
			sum = sum + s[j];
			//		debug("i %d (%lld %lld) j %d (%lld %lld) cross %lld\n", i, s[i].x, s[i].y, j, s[j].x, s[j].y, cross(pti(0, 0), s[i], s[j]));
			j++;
		}
		res = max(res, sum*sum);
		//	debug("testa %lld %lld ate %lld %lld\n", s[i].x, s[i].y, s[j].x, s[j].y);
		sum = sum - s[i];
		i++;
	}
	sum = pti(0, 0);
	for(int a=0;a<n;a++){
		s[a] = s[a]*(-1);
		sum = sum + s[a];
	}
	i = 0;
	j = 0;
	res = 0;
	while(i < n){
		if(i >= j){
			sum = s[i];
			j = i+1;
		}
		while(j < i+n && cross(pti(0, 0), s[i], s[j]) < 0){
			res = max(res, sum*sum);
			sum = sum + s[j];
			j++;
		}
		res = max(res, sum*sum);
		sum = sum - s[i];
		i++;
	}
	printf("%lld\n", res);
}