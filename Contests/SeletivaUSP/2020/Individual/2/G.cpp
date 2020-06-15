#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

int n, m, k;
ll s[2][MAXN];
ll S[2][MAXN];


vector<pair<vector<pll>, vector<double>>> cht;
ll dp[MAXN][MAXN];

ll sq(ll x){
    return x*x;
}

ll qry(int t, ll x){
    vector<double> &from = cht[t].snd;
    vector<pll> &ret = cht[t].fst;
    int i = upper_bound(from.begin(), from.end(), x) - from.begin() - 1; 
    return ret[i].fst*x + ret[i].snd;
}

double inter(pll a, pll b){
    //printf("inter (%lld %lld) (%lld %lld) : ", a.fst, a.snd, b.fst, b.snd);
    if(a.fst == b.fst){
        //printf("%.3f\n", (a.snd <= b.snd ? -DBL_MAX : DBL_MAX)); 
        return (a.snd < b.snd ? -DBL_MAX : DBL_MAX);
    }
    //printf("%.3f\n", ((double)a.snd - b.snd)/(b.fst - a.fst)); 
    return ((double)a.snd - b.snd)/(b.fst - a.fst);
}

void add(int t, ll m, ll b){ 
    vector<double> &from = cht[t].snd;
    vector<pll> &ret = cht[t].fst;
    while(!ret.empty() && inter(ret.back(), {m, b}) <= from.back()){
        ret.pop_back();
        from.pop_back();
    }

    if(ret.empty()){
        //debug("add %d %lld %lld\n", t, m, b);
        from.pb(0);
        ret.pb({m, b});
    }
    else if(inter(ret.back(), {m,b}) < DBL_MAX){
        //debug("add %d %lld %lld\n", t, m, b);
        from.pb(inter(ret.back(), {m,b}));
        ret.pb({m, b});
    }
}

int main (){
	scanf("%d", &n);
    for(int t=0;t<2;t++){
        for(int a=1;a<=n;a++){
            scanf("%lld", s[t]+a);
            S[t][a] = S[t][a-1] + s[t][a];
        }
    }

    cht = vector<pair<vector<pll>,vector<double>>>(n+1);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cht[0].fst.clear();
        cht[0].snd.clear();
        for(int j=1;j<=n;j++){
            dp[i][j] = s[0][i]*s[1][j];
            if(i > 1 && j > 1){
                add(0, 2*S[1][j-1], dp[i-1][j-1] - sq(S[1][j-1]));
                ll dpi = -sq(S[1][j-1]) + qry(0, S[1][j-1]); // pegando i-1
                ll dpj = -sq(S[0][i-1]) + qry(j, S[0][i-1]); // pegando j-1
                dp[i][j] += max(dpi, dpj);
                //printf("dp[%d][%d] = %lld + maX(%lld %lld) = %lld\n", i, j, s[0][i]*s[1][j], dpi, dpj, dp[i][j]);
            }
            else {
                dp[i][j] += -sq(S[1][j-1]) - sq(S[0][i-1]);
            }
            ans = max(ans, dp[i][j] - sq(S[0][n] - S[0][i]) - sq(S[1][n] - S[1][j]));
        }
        for(int j=2;j<=n;j++){
            add(j, 2*S[0][i], dp[i][j-1] - sq(S[0][i]));
        }
    }
    printf("%lld\n", ans);
}

