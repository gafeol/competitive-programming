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

const int MAXN = 61;

const double EPS = 1e-8;

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

temp double dist_seg_sqr(ptn a, ptn b, ptn c) {
	if((b - a) * (c - b) > 0) return b.dist_sqr(c);
	if((a - b) * (c - a) > 0) return a.dist_sqr(c);
	double d = (b - a) ^ (c - a);
	return d * d / ((b - a) * (b - a));
}

pair<pti, ll> s[MAXN];

bool hit(int i, pti a, pti b){
    return ((double)s[i].snd*s[i].snd + EPS >= dist_seg_sqr(a, b, s[i].fst));
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            ll x, y, r;
            scanf("%lld%lld%lld", &x, &y, &r);
            pti p = pti(x, y);
            s[a] = {p, r};
        }
        ll lx, ly;
        vector<int> tg;
        for(int a=0;a<m;a++){
            ll x, y;
            scanf("%lld %lld", &x, &y);
            if(a > 0){
                for(int i=0;i<n;i++){
                    if(hit(i, pti(lx, ly), pti(x, y)))
                        tg.pb(i);
                }
            }
            lx = x;
            ly = y;
        }
        sort(tg.begin(), tg.end());
        tg.erase(unique(tg.begin(), tg.end()), tg.end());
        printf("Compound #%d: ", tt);
        if(tg.empty())
            puts("undetected");
        else{
            printf("triggered cameras: ");
            for(int x: tg)
                printf("%d ", x+1);
            puts("");
        }

    }
}

