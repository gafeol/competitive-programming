#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
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

const int MAXN = 2123;

const int INF = 0x3f3f3f3f;

int n, m;
ll k;
ll dp[MAXN][MAXN];
vector<pil> adj[MAXN];
ll mx[MAXN];

double inter(pll a, pll b){
    if(a.snd == b.snd){
        if(a.fst <= b.fst)
            return -1;
        else
            return (double)LLONG_MAX;
    }
    double x = ((double)a.fst - b.fst)/(b.snd - a.snd);
    return x;
}

ll expo(ll base, ll e){
    if(e == 0)
        return 1ll;
    ll ans = expo(base, e/2ll);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

ll PA(ll de, ll ate, pll ln){
    //printf("PA %lld %lld %lld %lld\n", de, ate, ln.fst, ln.snd);
    if(de > ate) return 0; 
    ll cte = mod(ln.fst*(ate - de + 1));
    ll f = mod(ln.snd*ate);
    ll s = mod(ln.snd*de);
    //printf("= %lld  + %lld\n", cte, mod(mod(((f + s)*(ate-de+1)))*expo(2, modn-2)));
    return mod(cte + mod(((f + s)*(ate-de+1)))*expo(2, modn-2));
}

int main (){
	scanf("%d%d%lld", &n, &m, &k);
	for(int a=0;a<m;a++){
        int i, j;
        ll c;
        scanf("%d%d%lld", &i, &j, &c);
        adj[i].pb({j, c});
        adj[j].pb({i, c});
        mx[i] = max(mx[i], c);
        mx[j] = max(mx[j], c);
	}
    for(int a=0;a<=n;a++){
        for(int b=0;b<=m;b++){
            dp[a][b] = -INF;
        }
    }
    dp[1][0] = 0;
    ll res = 0;
    for(int a=1;a<=min(m, (int)k);a++){
        ll mx = 0;
        for(int u=1;u<=n;u++){
            if(dp[u][a-1] == -INF) continue;
            for(pil ar: adj[u]){
                int nxt = ar.fst;
                ll c = ar.snd;
                dp[nxt][a] = max(dp[nxt][a], dp[u][a-1] + c);
                mx = max(mx, dp[nxt][a]);
            }
        }
        //printf("a %d mx %lld\n", a, mx);
        res = mod(res + mx);
    }
    //printf("res %lld\n", res);
    if(m < k){
        pll bst = {-1, -1};
        int ind[MAXN];
        for(int a=1;a<=n;a++)
            ind[a] = a;
        sort(ind+1, ind+n+1, [&](int a, int b){ return (mx[a] < mx[b] || (mx[a] == mx[b] && dp[a][m] < dp[b][m])); });

        vector<pll> lns;
        vector<double> from;
        for(int aa=1;aa<=n;aa++){
            int a = ind[aa];
            if(dp[a][m] == -INF) continue;
            pll l = {dp[a][m], mx[a]};
            while(!lns.empty() && inter(lns.back(), l) < from.back()){
     //           printf("remove linha anterior inter %.4f\n", inter(lns.back(), l));
                lns.pop_back();
                from.pop_back();
            }
            if(lns.empty())
                from.pb(1);
            else
                from.pb(inter(lns.back(), l));
      //      printf("adicionei linha %lld %lld com from %.4f\n",l.fst, l.snd, from.back());
            //printf("dp[%d][%d] %lld mx %lld\n", a, m, dp[a][m], mx[a]);
            lns.pb(l);
        }

        /*
        puts("========================\nLines:");
        for(pll p: lns){
            printf("%lld %lld\n", p.fst, p.snd);
        }
        puts("========================");
        */

        ll ult = 1;
        for(int i=0;i<lns.size();i++){
            ll ate = (i + 1 < from.size() ? (ll)from[i+1] : k-m);
            ate = min(ate, k-m);
            //printf("de %lld ate %lld\n", ult, ate);
            //printf("usar reta %lld %lld\n", lns[i].fst, lns[i].snd);
            // fazer soma de pa
            res = mod(res + PA(ult, ate, lns[i]));
            ult = ate + 1;
        }
    }
    printf("%lld\n", res);
}

