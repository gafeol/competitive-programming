#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


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
typedef point<ll> ptl;
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
typedef pair<ptl, ptl> seg;


lnl l[MAXN];

seg s[MAXN];

ll gcd(ll a, ll b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

bool ehint(lnl u, lnl o){
	ll d = u.a * o.b - o.a * u.b;
	if(d == 0) return false;
	ll X = (o.b * u.c - u.b * o.c);
	ll Y = (u.a * o.c - o.a * u.c);
	if(X%d == 0 && Y%d == 0) return true;
	return false;
}

ptl it(lnl u, lnl o){
	ll d = u.a * o.b - o.a * u.b;
	ll X = (o.b * u.c - u.b * o.c);
	ll Y = (u.a * o.c - o.a * u.c);
	return ptl(X/d, Y/d);
}

map<ptl, bool> mrk;

map<int, map<ptl, bool> > des;

int main (){
	scanf("%d", &n);
	ll ans = 0;
	for(int a=0;a<n;a++){
		ptl x, y;
		scanf("%lld %lld %lld %lld", &x.x, &x.y, &y.x, &y.y);
		s[a] = seg(x, y);
		l[a] = lnl(x, y);
		ll dx = abs(x.x - y.x);
		ll dy = abs(x.y - y.y);
		ll old = ans;
		if(dx == 0)
			ans += dy + 1;
		else if(dy == 0)
			ans += dx + 1;
		else
			ans += gcd(dx, dy) + 1;
		//printf("a %d soma %lld\n", a, ans - old);
	}
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			//printf("inter seg %d %d = %d\n", a, b, inter_seg(s[a].fst, s[a].snd, s[b].fst, s[b].snd));
			//printf("eh int %d\n",  ehint(l[a], l[b]));
			if(inter_seg(s[a].fst, s[a].snd, s[b].fst, s[b].snd) && ehint(l[a], l[b])){
				ptl x = it(l[a], l[b]);
				if(mrk.find(x) != mrk.end()){
					if(des[a][x] == 0){
						ans--;
						des[a][x] = 1;
					}
					if(des[b][x] == 0){
						ans--;
						des[b][x] = 1;
					}
				}
				else{
					mrk[x] = a;
					des[a][x] = 1;
					des[b][x] = 1;
					ans--;
				}
			}
		}
	}
	printf("%lld\n", ans);
}

