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

const int MAXN = 52;
const int MAXM = 1123;

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

inline long long sq(ll x){
    return x*x;
}

inline long double dist(pti a, pti b){
    return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}


int n, m, k;
pti s[MAXN], sp[MAXM];
long double dp[MAXN][MAXN][3];

bool check(pti a, pti b){
    for(int i=0;i<m;i++)
        if(cross(a, sp[i], b) >= 0)
            return false;
    return true;
}

long double INF = 1e15 + (long double)1;

long double go(int i, int beg, int t){
    long double &r = dp[i][beg][t];
    if(r >= 0)
        return r;
    r = INF;
    if(t == 2 && check(s[i], s[beg])){
        r = min(r, dist(s[i], s[beg]));
    }
    for(int j = i+1;j < n;j++){
        if(!check(s[i], s[j])) 
            break;   
        r = min(r, go(j, beg, min(2, t+1)) + dist(s[i], s[j]));
    }
    return r;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        int x, y;
        scanf("%d%d", &x, &y);
        s[a] = pti(x, y);
	}

    for(int a=0;a<m;a++){
        int x, y;
        scanf("%d%d", &x, &y);
        sp[a] = pti(x, y);
    }

    if(m == 0){
        long double ans = DBL_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(cross(s[k], s[i], s[j]) != 0){
                        ans = min(ans, dist(s[i], s[j]) + dist(s[j], s[k]) + dist(s[k], s[i])); 
                    }
                }
            }
        }
        printf("%.2Lf\n", ans);
        return 0;
    }

    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int t=0;t<3;t++){
                dp[a][b][t] = -1;
            }
        }
    }
    long double ans = DBL_MAX;
    for(int a=0;a<n-1;a++)
        ans = min(ans, go(a, a, 0)); 
    printf("%.2Lf\n", ans);
}

