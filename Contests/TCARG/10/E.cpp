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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 112345;

struct Line{
    mutable ll m, k, p;
    bool operator <(const Line &o) const { return m<o.m; }
    bool operator <(ll x) const { return p <x;}
};

struct Cht : multiset<Line, less<>> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b){
        return a/b - ( (a^b)<0 and a%b);
    }

    bool bad2(iterator x, iterator y){
        if(y == end()){
            x->p = inf;
            return 0;
        }
        if(x->m == y->m) x->p = (x->k>y->k)? inf : -inf;
        else x->p = div(x->k - y->k, y->m - x->m);
        return x->p >= y->p;
    }

    void add(ll m, ll k){
        auto z = insert({m, k, 0}), y = z++, x = y;
        while(bad2(y,z)) z = erase(z);
        if(x!=begin() and bad2(--x, y)) bad2(x,erase(y));
        while((y=x)!=begin() and (--x)->p >= y->p) bad2(x, erase(y));
    }

    ll qry(ll x){
        assert(!empty());
        auto l = *lower_bound(x);
        return x*l.m + l.k;
    }
};

int n, m, k, p;
ll s[MAXN];
ll dacc[MAXN];
ll d[MAXN];
ll dp[2][MAXN];
int h;
ll acc[MAXN];

int main (){
	scanf("%d%d%d", &n, &m, &p);
	for(int a=2;a<=n;a++){
        scanf("%lld", d+a);
	}
    for(int a=1;a<=n;a++){
        dacc[a] = dacc[a-1] + d[a];
    }

    ll ans = 0;
    for(int a=1;a<=m;a++){
        scanf("%d%lld", &h, s+a);
        s[a] -= dacc[h];
        /*
        if(s[a] < 0){
            ans += abs(s[a]);
            s[a] = 0;
        }
        */
    }
    sort(s+1, s+m+1);
    for(int a=1;a<=m;a++){
        //printf("s %d %lld\n", a, s[a]);
        acc[a] = acc[a-1] + s[a];
    }

    for(int k=1;k<=p;k++){
        Cht cht;
        int t = (k&1);
        if(k == 1){
            for(ll i=1;i<=m;i++){
                dp[t][i] = s[i]*i - acc[i];
                //printf("dp[%d][%lld] %lld\n", t, i, dp[t][i]);
            }
            continue;
        }
        for(ll i=1;i<=m;i++){
            ll j = i-1;
            //printf("cht add %lld, %lld, - %lld\n", j, -dp[1-t][j], acc[j]);
            cht.add(j, -dp[1-t][j] - acc[j]);
            dp[t][i] = -acc[i] + i*s[i] - cht.qry(s[i]);
            //printf("dp[%d][%lld] = %lld + %lld - %lld = %lld\n", t, i, -acc[i], i*s[i], cht.qry(s[i]), dp[t][i]);
        }
    }
    printf("%lld\n", ans + dp[(p&1)][m]);
}

