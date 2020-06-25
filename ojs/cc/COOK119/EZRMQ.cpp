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

const int MAXN = 5123;
const ll INF = 3e17;

int n, m;
ll s[MAXN];
ll dp[MAXN][MAXN];
int sz[MAXN];
int L[MAXN], R[MAXN];

inline bool valid(int x){ return (x >= 0 && x< n); }

ll go(int u, int k){
    if(k <= 0) return 0;
    ll &r = dp[u][k];
    //printf("go u %d k %d r %lld\n", u, k, r);
    if(r != -1) return r;
    if(sz[u] < k) return r = INF;  

    r = INF;
    if(valid(L[u]) && valid(R[u])){
        int LMIN = max(0, k - sz[R[u]] - 1);
        int LMAX = min(sz[L[u]], k);
        for(int l=LMIN;l<=LMAX;l++){
            int qtdL = l;
            int qtdR = k - l;
            if(qtdL >= 0 && qtdL <= k && qtdR >= 0 && qtdR <= k)
                r = min(r, go(L[u], qtdL) + go(R[u], qtdR) + (qtdL*qtdR)*s[u]);
            qtdL = l;
            qtdR = k-l-1;
            if(qtdL >= 0 && qtdL <= k && qtdR >= 0 && qtdR <= k)
                r = min(r, go(L[u], qtdL) + go(R[u], qtdR) + (qtdL*qtdR)*s[u] + k*s[u]);
        }
    }
    else if(valid(L[u])){
        r = min(r, go(L[u], k));
        r = min(r, go(L[u], k-1) + s[u]*k);
    }
    else if(valid(R[u])){
        r = min(r, go(R[u], k));
        r = min(r, go(R[u], k-1) + s[u]*k);
    }
    else 
        r = s[u];
    //printf("u %d k %d r %lld\n", u, k, r);
    return r;
}

inline int dfs(int u){
    if(!valid(u)) return 0;    
    return sz[u] = 1 + dfs(L[u]) + dfs(R[u]);
}

int ind[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<=n;a++){
            L[a] = -1;
            R[a] = n;
            for(int b=0;b<=n;b++){
                dp[a][b] = -1;
            }
        }
        for(int a=0;a<n;a++){
            ind[a] = a;
            scanf("%lld", s+a);
        }
        sort(ind, ind+n, [&](int a, int b) { return s[a] < s[b]; });
        set<int> q;
        q.insert(-1);
        q.insert(n);
        for(int a=n-1;a>=0;a--){
            int pos = ind[a];
            auto it = q.lower_bound(pos);
            //printf("lower bound %d\n", *it);
            if(valid(*it) && !valid(L[*it]))
                L[*it] = pos;
            --it;
            //printf("lower bound-- %d\n", *it);
            if(valid(*it) && !valid(R[*it]))
                R[*it] = pos;
            q.insert(pos);
            //printf("insere %d\n", pos);
        }
        //puts("");
        //for(int a=0;a<n;a++){
            //printf("pos %d L %d R %d\n", a,L[a], R[a]);
        //}
        dfs(ind[n-1]);
        ll ans = LLONG_MAX;
        for(int k=m;k<=n;k++){
            ans = min(ans, go(ind[n-1], k));
            //printf("ans k %d: ans %lld\n", k, ans);
        }
        printf("%lld\n", ans);
    }
}

