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

const int MAXN = 51234;

int n, m, k;
int s[MAXN];

//                       to prev centroid
int sz[MAXN], mrk[MAXN], link[MAXN];
vector<int> adj[MAXN];

int getsz(int u, int p){
    sz[u] = 1;
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        sz[u] += getsz(nxt, u);
    }
    return sz[u];
} 

int getc(int u, int p, int tot){
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        if(sz[nxt] > tot/2){
            return getc(nxt, u, tot);
        } 
    }
    return u;
}


map<int, int> cnt;
ll ans;

void qry(int u, int p, int d=1){
    if(d > k) return ;
    ans += cnt[k-d];
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        qry(nxt, u, d+1);
    }
}

void add(int u, int p, int d=1){
    cnt[d]++;
    if(d > k) return ;
    for(int nxt: adj[u]){
        if(mrk[nxt] || nxt == p) continue;
        add(nxt, u, d+1);
    }
}

int decomp(int u, int prvc=-1){
    getsz(u, u);
    int c;
    c = getc(u,u,sz[u]);
    link[c] = prvc;
    mrk[c] = true;
    cnt.clear();
    cnt[0] = 1;
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        qry(nxt, c);
        add(nxt, c);
    }
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        int nxtc = decomp(nxt, c);
    }
    return c;
}

void reset(int n) {
    ans = 0;
    for(int a=0;a<=n;a++){
        adj[a].clear();
        mrk[a] = false;
    }
}

int main (){
	scanf("%d%d", &n, &k);
    reset(n);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);
        adj[j].pb(i);
	}
    decomp(0);
    printf("%lld\n", ans);
}

