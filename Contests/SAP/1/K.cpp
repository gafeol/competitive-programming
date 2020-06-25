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

const int MAXN = 1123;

const long double EPS = 0.00000001;
const long double INF = DBL_MAX;

int n, m, k;
int s[MAXN];

long double dp[MAXN][MAXN];
bool mrk[MAXN][MAXN];
vector<tuple<ll, ll, ll> > ev;

ll sq(ll x){
    return x*x;
}
long double dist(ll x, ll y, ll xx, ll yy){
    return sqrt(sq(xx - x) + sq(yy - y));
}

long double move(int i, int j){
    if(i == 0 || j == n+1) return 0.;
    ll ti, xi, yi;
    tie(ti, xi, yi) = ev[i];
    ll tj, xj, yj;
    tie(tj, xj, yj) = ev[j];
    if(ti == tj){
        if(xi == xj && yi == yj) return 0.;
        else return INF;
    }
    return dist(xi, yi, xj, yj)/((long double)tj - ti);
}

// t pode ser igual
long double go(int i, int o){
    if(i == n+1) return 0.;   
    long double &r = dp[i][o];
    if(mrk[i][o])
        return r;
    
    mrk[i][o] = true;
    long double sd = move(i, i+1);
    r = min(r, max(sd, go(i+1, o)));
    sd = move(o, i+1);
    r = min(r, max(sd, go(i+1, i)));
    return r;
}


int main (){
	scanf("%d", &n); // n pode ser 0
    ev.pb({-1, 0, 0});
	for(int a=0;a<n;a++){
        ll i, j, k;
        scanf("%lld%lld%lld", &i, &j, &k);
        ev.pb({k, i, j});
	}
    sort(ev.begin(), ev.end()); 
    for(int a=0;a<=n;a++){
        for(int b=0;b<=n;b++){
            mrk[a][b] = false;
            dp[a][b] = INF;
        }
        
    }
    printf("%.10Lf\n", go(1,0));
}

