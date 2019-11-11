#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<ll, int, int> ares;
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

int n, m;
pii s[MAXN];
ll c[MAXN];
ll k[MAXN];


ll cust(int i, int j){
    return (k[i] + k[j])*(abs(s[i].fst - s[j].fst) + abs(s[i].snd - s[j].snd)); 
}

int p[MAXN], sz[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

bool join(int u, int v){
    u = raiz(u);
    v = raiz(v);
    if(u == v) return false;

    if(sz[u] < sz[v])
        swap(u, v);

    p[v] = u;
    sz[u] += sz[v];
    return true;
}


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int x, y;
        scanf("%d %d", &x, &y);
        s[a] = {x, y};
	}
    for(int a=0;a<n;a++)
        scanf("%lld", c+a);
    for(int a=0;a<n;a++)
        scanf("%lld", k+a);

    vector<ares> ar;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           ar.pb({cust(i, j), i, j}); 
        }
    }
    for(int a=0;a<n;a++){
        ar.pb({c[a], a, n});
    }
    for(int a=0;a<=n;a++){
        p[a] = a;
        sz[a] = 1;
    }
    sort(ar.begin(), ar.end());
    ll ans = 0;
    vector<int> pwr;
    vector<pii> lig;
    for(ares e: ar){
        int i, j;
        ll cus;
        tie(cus, i, j) = e;
        if(join(i, j)){
            ans += cus;
            if(i > j) swap(i, j);   
            if(j == n)
                pwr.pb(i+1);
            else
                lig.pb({i+1, j+1});
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", pwr.size());
    for(int x: pwr){
        printf("%d ", x);
    }
    puts("");
    printf("%d\n", lig.size());
    for(pii par : lig)
        printf("%d %d\n", par.fst, par.snd);
   puts(""); 
}

