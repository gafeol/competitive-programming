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

const int MAXN = 25534;

typedef double cood; cood eps = 1e-6; // risky: XXX, untested: TODO
const double pi = acos(-1.);
template<typename T> inline T sq(T x) { return x*x; }
struct vec {
	cood x, y;
	vec () : x(0), y(0) {} vec (cood a, cood b) : x(a), y(b) {}
	inline vec operator - (vec o) { return {x - o.x, y - o.y}; }
	inline vec operator + (vec o) { return {x + o.x, y + o.y}; }
	inline vec operator * (cood o) { return {x * o, y * o}; }
	inline vec operator / (cood o) { return {x / o, y / o}; }
	inline cood operator ^ (vec o) { return x * o.y - y * o.x; }
	inline cood operator * (vec o) { return x * o.x + y * o.y; }
	inline cood cross (vec a, vec b) { return ((*this)-a) ^ ((*this)-b); } // |(this)a||(this)b|sen(angle)
	inline cood inner (vec a, vec b) { return ((*this)-a) * ((*this)-b); } // |(this)a||(this)b|cos(angle)
	inline double angle (vec a, vec b) { return atan2(cross(a,b),inner(a,b)); } // ccw angle from (this)a to (this)b in range [-pi,pi]
	inline int ccw (vec a, vec b) { cood o = cross(a,b); return (eps < o) - (o < -eps); } // this is to the (1 left, 0 over, -1 right) of ab
	inline int dir (vec a, vec b) { cood o = inner(a,b); return (eps < o) - (o < -eps); } // a(this) is to the (1 same, 0 none, -1 opposite) direction of ab
	inline cood sq (vec o = vec()) { return inner(o,o); }
	inline double nr (vec o = vec()) { return sqrt(sq(o)); } //$
	inline vec operator ~ () { return (*this)/nr(); }
	inline vec proj (vec a, vec b) { return a + (b-a)*(a.inner((*this),b) / a.sq(b)); } // projects this onto line ab
	inline vec rotate (double a) { return vec(cos(a) * x - sin(a) * y, sin(a) * x + cos(a) * y); } // ccw by a radians
	inline vec rot90 () { return vec(-y,x); } // rotate(pi/2)$
	bool in_seg (vec a, vec b) { return ccw(a,b) == 0 && dir(a,b) <= 0; } // tips included
	double dist2_lin (vec a, vec b) { return a.sq(b) <= eps ? sq(a) : double(::sq(cross(a,b)))/a.sq(b); } // see cir.has_inter_lin
	double dist2_seg (vec a, vec b) { return a.dir((*this),b) == (b.dir((*this),a)) ? dist2_lin(a,b) : min(sq(a),sq(b)); }
	inline bool operator == (const vec & o) const { return abs(x-o.x) <= eps && abs(y-o.y) <= eps; }
	inline bool operator < (const vec & o) const { return (abs(x-o.x)>eps)?(x < o.x):(y > o.y); } // lex compare (inc x, dec y)
	// full ccw angle strict compare beginning upwards (this+(0,1)) around (*this)
	// incresing distance on ties, this is the first
	bool compare (vec a, vec b) { 
		if ((*this < a) != (*this < b)) return *this < b;
		int o = ccw(a,b); return o?o>0:((a == *this && !(a == b)) || a.dir(*this,b) < 0);
	}
}; //$
bool inter_seg (vec a, vec b, vec c, vec d) {
	if (a.in_seg(c, d) || b.in_seg(c, d) || c.in_seg(a, b) || d.in_seg(a, b)) return true;
	return (c.ccw(a, b) * d.ccw(a, b) == -1 && a.ccw(c, d) * b.ccw(c, d) == -1);
}
double dist2_seg (vec a, vec b, vec c, vec d){return inter_seg(a,b,c,d)?0.:min({ a.dist2_seg(c,d), b.dist2_seg(c,d), c.dist2_seg(a,b), d.dist2_seg(a,b) });}

int n, m, k;
int s[MAXN];
vec pos[MAXN];
vec d[MAXN]; 

vec move(int id, double t){
    return pos[id] + d[id]*(t*s[id]);
}

void print(vec a){
    printf("x %.5f y %.5f\n", a.x, a.y);
}

bool inter(double t){
    multiset<pair<vec, vec> > q;
    vector<pair<pair<vec, vec>, bool> > ev;
    for(int a=0;a<n;a++){
        vec A = pos[a];
        vec B = move(a, t);
        if(A.x > B.x || (A.x == B.x && A.y > B.y))
            swap(A, B);
        ev.pb(make_pair(make_pair(A, B), 0));
        ev.pb(make_pair(make_pair(B, A), 1));
    }
    sort(ev.begin(), ev.end());
    for(pair<pair<vec, vec>, bool> p: ev){
        vec A = p.fst.fst;
        vec B = p.fst.snd;
        if(p.snd)
            q.erase(q.find({B, A}));
        auto it = q.lower_bound(p.fst); 
        if(it != q.end()){
            vec C = it->fst;
            vec D = it->snd;
            if(inter_seg(A, B, C, D)){
                return true;
            }
        }
        if(it != q.begin()){
            it--;
            vec C = it->fst;
            vec D = it->snd;
            if(inter_seg(A, B, C, D)){
                return true;
            }
        }
        if(!p.snd)
            q.insert({A, B});
    }
    return false;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int x, y, ddx, ddy;
        scanf("%d%d%d%d%d", &x, &y, &ddx, &ddy, s+a); 
        pos[a] = vec((cood)x, (cood)y);
        double sz = sqrt(ddx*ddx + ddy*ddy);
        d[a].x = ddx/sz;
        d[a].y = ddy/sz;
	}
    double i = 0, j = 10000000;
    double inf = j - 50;
    while((j - i) > 1e-8){
        double m = (i + j)/2.; 
        if(inter(m))
            j = m;
        else
            i = m;
    }
    if(i > inf)
        puts("No show :(");
    else
        printf("%.10f\n", (i+j)/2.);
}

