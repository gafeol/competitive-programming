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

const int MAXN = 212345;
const int LOGN = 32;

int n, m, k;
int s[MAXN], sz[MAXN], mrk[MAXN];
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


ll cnt[LOGN];
int tot;

void add(int x){
    //printf("add %d\n", x);
    tot++;
    int i =0;
    while(x > 0){
        cnt[i] += (x&1);
        x/=2;
        i++;
    }
}

void rmv(int x){
    //printf("rmv %d\n", x);
    tot--;
    int i =0;
    while(x > 0){
        cnt[i] -= (x&1);
        x/=2;
        i++;
    }
}

ll getd(int x){
    /*printf("getd %d tot %d:\n", x, tot);
    for(int i=0;i<LOGN;i++){
        printf("%lld ", cnt[i]);
    }
    puts(""); */
    ll ans = 0;
    for(int i=0;i<LOGN;i++){
        ll pot = (1ll << ((ll)i));
        if(x&1){
            ans += pot*(tot-cnt[i]);
        }
        else
            ans += pot*cnt[i];
        x/=2;
    }
    //printf("ans: %lld\n", ans);
    return ans;
}

void clean(){
    tot = 0;
    for(int a=0;a<LOGN;a++)
        cnt[a] = 0;
}

void goadd(int u, int p, int d=0){
    d ^= s[u];  
    //printf("goadd u %d d %d\n", u, d);
    add(d);
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        goadd(nxt, u, d);
    }
}

void gormv(int u, int p, int d=0){
    d ^= s[u];
    //printf("gormv u %d d %d\n", u, d);
    rmv(d);
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        gormv(nxt, u, d);
    }
}

ll goans(int u, int p, int d=0){
    d ^= s[u];
    ll ans = getd(d);
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        ans += goans(nxt, u, d);
    }
    return ans;
}

ll decomp(int u=1){
    int c = getc(u,u,sz[u]);
    //printf("decomp %d cent %d\n", u, c);
    mrk[c] = true;
    ll ans = 0;
    add(s[c]);
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        goadd(nxt, c, s[c]);
    }
    ans += getd(0); 
    rmv(s[c]);
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        gormv(nxt, c, s[c]); 
        ans += goans(nxt, c);  
    }
    clean();
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        getsz(nxt, c);
        ans += decomp(nxt);
    }
    //printf("decomp %d cent %d ans %lld\n", u, c, ans);
    return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
        scanf("%d", s+a);
	}
    for(int a=1;a<n;a++){
        int i, j;
        scanf("%d %d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
    }
    getsz(1,1);
    ll ans = decomp(1);
    printf("%lld\n", ans);
}

