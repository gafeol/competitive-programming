#include "bits/stdc++.h"
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

const double EPS = 1e-8;
double pi = acos(-1.);

int n, m, k;
double t[MAXN], s[MAXN], ang[MAXN];

#define ADD 0 
#define RMV 1
#define TOP 2

vector<tuple<double, int, int>> ev;

void criaEv(int i){
    double del = t[i]/s[i];
    ev.pb({ang[i] - del, ADD,  i});
    ev.pb({ang[i], TOP, i});
    ev.pb({ang[i]+del, RMV, i});

    ev.pb({2*pi + ang[i] - del, ADD,  i});
    ev.pb({2*pi + ang[i], TOP, i});
    ev.pb({2*pi + ang[i]+del, RMV, i});
}

int main (){
	scanf("%d", &n);
    double cte = 0;
	for(int a=0;a<n;a++){
        scanf("%lf%lf%lf",t+a, s+a, ang+a);
        double sob = t[a] - s[a]*pi;
        if(sob > 0){
            cte += sob;
            t[a] -= sob;
        }
        if(s[a] > EPS)
            criaEv(a);
	}
    sort(ev.begin(), ev.end());

    double lstth = 0;
    double sumUp = 0, sumDw = 0;
    double ans = 0;
    double res = 0;
    for(auto [th, t, i] : ev){
        ans += (th - lstth)*(sumUp - sumDw); 
        res = max(res, ans);
        if(t == ADD)
            sumUp += s[i];
        else if(t == RMV)
            sumDw -= s[i];
        else {
            sumUp -= s[i];
            sumDw += s[i];
        }
        lstth = th;
    }
    printf("%.10f\n", res + cte);
    return 0;
}

