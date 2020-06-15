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

int n, m, k;
int s[MAXN];

typedef double cood;
cood eps = 1e-8;

const double pi = acos(-1.);
template<typename T> inline T sq(T x) { return x*x; }

struct vec {
    cood x, y;
    vec() : x(0), y(0) {} vec (cood a, cood b) :x(a), y(b) {}
    inline vec operator - (vec o) { return { x - o.x, y - o.y }; }
    inline vec operator + (vec o) { return { x + o.x, y + o.y};  }
    inline vec operator * (cood o) { return { x*o,   y * o}; } 
    inline vec operator / (cood o) { return { x/o, y/o}; }
    inline cood operator ^ (vec o) { return x*o.y - y*o.x;  }
    inline cood operator * (vec o) { return x*o.x + y*o.y; }
    inline double nr (vec o = vec()) { return sqrt(sq(o)); }
    inline vec operator ~ () { return (*this)/nr(); }
    inline cood cross(vec a, vec b) { return ((*this)-a) ^ ((*this)-b); }
    inline cood inner(vec a, vec b) { return ((*this)-a) * ((*this)-b); }
    inline cood sq(vec o = vec()) { return inner(o, o); }
    inline double angle(vec a, vec b) { return atan2(cross(a, b), inner(a,b));}
    inline vec rotate (double a) { return vec(cos(a)*x - sin(a)*y, sin(a)*x + cos(a)*y); }
};


struct cir{
    vec c; cood r; 
    cir () {} cir(vec v, cood d) : c(v), r(d) {} 
    inline bool contains(vec w) { return c.sq(w) <= sq(r) + eps; }
    inline bool border(vec w) { return abs(c.sq(w) - sq(r)) <= eps; }
    inline double arc_len(vec a, vec b) { return c.angle(a, b)*r; }
    pair<vec, vec> tan(vec v) {
        if(contains(v) && !border(v)) throw 0;
        cood d2 = c.sq(v); double s = sqrt(d2 - r*r); s = (s==s)?s:0;
        double al = atan2(r, s); vec t = (~(c-v));
        return pair<vec, vec>(v + t.rotate(al)*s, v + t.rotate(-al)*s);
    }
};

int main (){
    int xi, yi, xd, yd;
    int xc, yc, rc;
    scanf("%d%d", &xi, &yi);
    scanf("%d%d", &xd, &yd);
    scanf("%*d%*d%*d");
    scanf("%d%d%d", &xc, &yc, &rc);
    vec i = vec(xi, yi); 
    vec d = vec(xd, yd);
    vec cc = vec(xc, yc);
    cir c = cir(cc, rc);
    pair<vec, vec> ti = c.tan(i);
    vector<vec> A = {ti.fst, ti.snd};
    pair<vec, vec> td = c.tan(d);
    vector<vec> B = {td.fst, td.snd};
    double ans = DBL_MAX;
    for(int a=0;a<2;a++){
        for(int b=0;b<2;b++){
            double ri = sqrt((A[a] - i)*(A[a]-i));
            double rd = sqrt((B[b] - d)*(B[b]-d));
            ans = min(ans, ri + rd + abs(c.arc_len(A[a], B[b])));
        }
    }
    printf("%.10f\n", ans);
     
}

