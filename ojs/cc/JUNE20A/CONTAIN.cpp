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


typedef ll cood; cood eps = 0; // risky: XXX, untested: TODO
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

int convex_hull (vec * v, int n, int border_in) { // nlg | border_in (should border points stay?)
	swap(v[0], *min_element(v,v+n)); int s, i;
	sort(v+1, v+n, [&v] (vec a, vec b) { int o = b.ccw(v[0], a); return (o?o==1:v[0].sq(a)<v[0].sq(b)); });
	if (border_in) {
		for (s = n-1; s > 1 && v[s].ccw(v[s-1],v[0]) == 0; s--);
		reverse(v+s, v+n);
	}
	for (i = s = 0; i < n; i++) if (!s || !(v[s-1] == v[i])) {
		for (; s >= 2 && v[s-1].ccw(v[s-2],v[i]) >= border_in; s--);
		swap(v[s++],v[i]);
	}
	return s;
}//$

int n, m, k;
vec s[MAXN];
vector<int> ini;

ll cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}

bool in(int i, vec p){
    int sz = (i + 1 >= ini.size() ? n : ini[i+1]) - ini[i];
    /*
    printf("in i %d on: ", i);
    for(int a=0;a<sz;a++){
        printf("(%lld %lld) ", s[ini[i]+a].x, s[ini[i]+a].y);
    }
    puts("?");
    */
    for(int a=0;a<sz;a++){
        vec u = s[ini[i]+a];
        vec v = s[ini[i]+((a+1)%sz)];
        //printf("u %lld %lld v %lld %lld  p %lld %lld\n", u.x, u.y, v.x, v.y, p.x, p.y);
        //printf("ccw %lld\n", u.cross(v, p));
        if(u.cross(v, p) <= 0){
            //puts("NAO");
            return false;
        }
    }
    //puts("SIM");
    return true;
}

int main (){
    for_tests(t, tt){
        ini.clear();
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            scanf("%lld%lld", &s[a].x, &s[a].y);
        }
        int i = 0;
        int sz;
        while(i < n){
            ini.pb(i);
            sz = convex_hull(s+i, n-i, true); 
            //printf("ini pb %d sz %d\n", i, sz);
            i += sz; 
        }
        for(int a=0;a<m;a++){
            vec p;
            scanf("%lld%lld", &p.x, &p.y);
            if(!in(0, p)){
                puts("0");
                continue;
            }
            int i = 0, j = ini.size()-1;
            while(i < j){
                int m = (i + j+1)/2;
                if(in(m, p))
                    i = m;
                else
                    j = m-1;
            }
            printf("%d\n", i+1);
        }
    }
}

