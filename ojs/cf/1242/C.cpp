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

const int MAXN = 21, BMASK = (1 << 20);


int n, m, k;
ll sum[MAXN];
vector<ll> s[MAXN];

map<ll, int> from;

map<int, int> nxt; 
int tempo;
map<int, int> mrk;

int dp[BMASK];
vector<int> has[BMASK];

void getCycle(int u){
    int bm = 0;
    bm |= (1 << from[u]);
    int v = nxt[u];
    vector<int> aux = {u};
    while(v != u){
        int f = from[v];
        if(bm&(1<<f))
            return ;
        bm |= (1<<f);
        aux.pb(v);
        v = nxt[v];
    }
    has[bm] = aux;
    dp[bm] = 1;
}

void dfs(int x, int ini){
    mrk[x] = tempo;
    if(nxt.find(x) != nxt.end()){
        if(mrk[nxt[x]] == tempo){
            getCycle(x);
            return ;
        }
        if(mrk[nxt[x]] == 0)
            dfs(nxt[x], ini);
    }
}

void findCycles(){
    for(int a=0;a<n;a++){
        for(int x: s[a]){
            if(mrk[x]) continue;
            tempo++;
            dfs(x, x); 
        }
    }
}

int go(int bm){
    if(dp[bm] != -1) return dp[bm];
    if(bm == 0) return dp[bm] = false;
    dp[bm] = false;
    for(int sbm = bm; sbm > 0; sbm = (sbm-1)&bm){
        if(go(sbm) && go(sbm^bm)){
            dp[bm] = true;
            break;
        }
    }
    return dp[bm];
}


pii ans[MAXN];
void re(int bm){
    if(!has[bm].empty()){
        for(int i=0;i<has[bm].size();i++){
            int orig = has[bm][i];
            int ii = (i + 1)%has[bm].size();
            int novo = has[bm][ii];
            ans[from[novo]] = {novo, from[orig]};
        }
    }
    for(int sbm = bm; sbm > 0; sbm = (sbm-1)&bm){
        if(go(sbm) && go(sbm^bm)){
            re(sbm);
            re(sbm^bm);
            break;
        }
    }
}

int main (){
	scanf("%d", &n);
    ll S = 0;
	for(int a=0;a<n;a++){
        scanf("%d", &m);
        while(m--){
            ll x;
            scanf("%lld", &x);
            from[x] = a;
            sum[a] += (ll)x;
            s[a].pb(x);
            S += (ll)x;
        }
	}
    if(S % n != 0){
        puts("No");
        return 0;
    }
    ll val = S/n;
    for(int a=0;a<n;a++){
        for(ll x: s[a]){
            ll o = val - sum[a] + x;
            if(from.find(o) != from.end())
                nxt[x] = o;
        }
    }  
    memset(dp, -1, sizeof(dp));
    findCycles();
    if(!go((1<<n)-1)){
        puts("No");
        return 0;
    }
    re((1<<n)-1);
    puts("Yes");
    for(int a=0;a<n;a++){
        printf("%d %d\n", ans[a].fst, ans[a].snd+1);
    }
}
