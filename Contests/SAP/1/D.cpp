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
const int BITMASK = (1<<22);

int n, m;
int s[MAXN];

ll dp[BITMASK], d[BITMASK], p[BITMASK], k;

vector<int> ans;

vector<tuple<ll, ll, int> > e;

ll go(int bm){
    ll &r = dp[bm];
    if(r != -1)
        return r;

    r = d[bm] + k*p[bm];
    for(int i=0;i<n;i++){
        if((1<<i)&bm) continue;
        ll x, v;
        int id;
        tie(x, v, id) = e[i];
        if(v + d[bm] >= 0 && x + p[bm] >= 0)
            r = max(r, go(bm|(1<<i)));
    }

    return r;
}

void re(int bm){
    ll &r = dp[bm];
    if(r == d[bm] + k*p[bm])
        return ;

    for(int i=0;i<n;i++){
        if((1<<i)&bm) continue;
        ll x, v;
        int id;
        tie(x, v, id) = e[i];
        if(v + d[bm] >= 0 && x + p[bm] >= 0){
            if(r == go(bm|(1<<i))){
                ans.pb(id);
                re(bm|(1<<i));
                return ;
            }
        }
    }
}

int main (){
    memset(dp, -1, sizeof(dp));
	scanf("%d%lld", &n, &k);
    ll pi, di;
    scanf("%lld %lld", &pi, &di);
	for(int a=0;a<n;a++){
        ll x, v;
        scanf("%lld%lld", &x, &v);
        e.pb({x, v, a+1});
	}
    for(int bm=0;bm < (1 << n);bm++){
        p[bm] = pi;
        d[bm] = di;
        for(int i=0;i<n;i++){
            if((bm&(1<<i)) == 0) continue; 
            ll x, v;
            int id;
            tie(x, v, id) = e[i];
            p[bm] += x;
            d[bm] += v;
        }
    }
    go(0);
    //debug("%lld\n", go(0));
    re(0);
    printf("%d\n", (int)ans.size());
    for(int x: ans){
        printf("%d ", x);
    }
    puts("");
}

