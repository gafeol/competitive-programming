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
ll modn;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, k;
int s[MAXN];
ll phi;

int sz[MAXN], mrk[MAXN];
vector<pii> adj[MAXN];


ll expo(ll base, ll e){
    if(e == 0)
        return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}
int getsz(int u, int p){
    sz[u] = 1;
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(mrk[nxt] || nxt == p) continue;
        sz[u] += getsz(nxt, u);
    }
    return sz[u];
} 

int getc(int u, int p, int tot){
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(mrk[nxt] || nxt == p) continue;
        if(sz[nxt] > tot/2){
            return getc(nxt, u, tot);
        } 
    }
    return u;
}


ll ans = 0;
ll inv[MAXN];
map<ll, ll> nw;

void qry(int u, int p, ll som, int h){
    ll x = mod((modn - som)*inv[h]);
    //printf("u %d p %d som %lld h %d x %lld\n", u, p, som, h, x);
    assert(mod(som + x*expo(10, h)) == 0);
    assert(mrk[u] == 0);
    if(nw.find(x) != nw.end()){
        ans += nw[x];
        //printf("ans += %lld\n", nw[x]);
    }
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        if(nxt == p || mrk[nxt]) continue;
        int d = ar.snd;
        qry(nxt, u, mod(som*10 + d), h+1);
    }
}

void add(int u, int p, ll som, ll dez=10){
    //printf("add u %d p %d som %lld\n", u, p, som);
    assert(mrk[u] == 0);
    nw[som]++;
    for(pii ar: adj[u]){
        int nxt  = ar.fst;
        if(nxt == p || mrk[nxt]) continue;
        int d = ar.snd;
        add(nxt, u, mod(som + dez*d), mod(dez*10));
    }
}

int decomp(int u, int prvc=-1){
    getsz(u, u);
    int c;
    c = getc(u,u,sz[u]);
    //printf("decomp u %d, c %d\n", u, c);
    ll oans = ans;
    nw.clear();
    nw[0] = 1;
    for(pii ar: adj[c]){
        int nxt = ar.fst;
        if(mrk[nxt]) continue;
        int d = ar.snd;
        qry(nxt, c, d, 1);
        add(nxt, c, d);
    }
    nw[0]--;
    ans += nw[0];
    //puts("Vai ao contrario agora");
    nw.clear();
    for(int i=adj[c].size()-1;i>=0;i--){
        pii ar = adj[c][i];
        int nxt = ar.fst;
        if(mrk[nxt]) continue;
        int d = ar.snd;
        qry(nxt, c, d, 1);
        add(nxt, c, d);
    }
    //printf("fim decomp u %d acumulou %lld\n", u, ans - oans);
    mrk[c] = true;
    for(pii ar: adj[c]){
        int nxt = ar.fst;
        if(mrk[nxt]) continue;
        int nxtc = decomp(nxt, c);
    }
    return c;
}

void reset(int n) {
    for(int a=0;a<=n;a++){
        adj[a].clear();
        mrk[a] = false;
    }
}

ll euler_totient(ll x){
    if(x == 1)
        return 1;
    ll phi = x;
    vector<ll> pri;
    ll lim = sqrt(x) + 1e-8;
    vector<int> mrk(lim+1, 0);
    for(ll i=2;i<=lim;i++){
        if(mrk[i]) continue;
        pri.pb(i);
        for(ll j=i;j*i <= lim;j++)
            mrk[j*i] = 1;
    }

    vector<ll> xprimes;
    for(int i=0;i<pri.size();i++){
        if(x % pri[i] == 0)
            xprimes.pb(pri[i]);
        while(x % pri[i] == 0)
            x /= pri[i];
    }
    if(x > 1)
        xprimes.pb(x);

    for(ll pri: xprimes){
        phi = (phi/pri)*(pri - 1);
    }
    return phi;
}

int main (){
	scanf("%d%lld", &n, &modn);
    phi = euler_totient(modn);
    inv[0] = 1;
    ll dez = 10;
    for(int i=1;i<=n;i++){
        inv[i] = expo(dez, phi-1);
    //    assert(mod(inv[i]*dez) == 1);
        dez = mod(dez*10);
    }
    reset(n);
	for(int a=1;a<n;a++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        w = mod(w);
        adj[u].pb({v, w});
        adj[v].pb({u, w});
	}
    decomp(0);
    printf("%lld\n", ans);
}

