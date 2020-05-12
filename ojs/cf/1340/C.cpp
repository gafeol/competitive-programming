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

const int MAXN = 10004, MAXD = 1003;

int n, m, k;
int s[MAXN];

int thisLevel;
int lvl[MAXN][MAXD];
vector<int> st[MAXN];
vector<int> nxt;
int len, G, R;

inline void add(int u, int dis){
    if(dis > G) return ;

    if(lvl[u][(dis%G)] != -1)
        return ;

    if(dis == G){
        lvl[u][0] = thisLevel + 1;
        nxt.pb(u);
    }
    else{
        lvl[u][dis] = thisLevel;
        st[dis].pb(u);
    }
}

int main (){
	scanf("%d%d", &len, &n);
    memset(lvl, -1, sizeof(lvl));
	for(int a=0;a<n;a++)
        scanf("%d", s+a);
    sort(s, s+n);
    scanf("%d%d", &G, &R);
    lvl[0][0] = 0;
    st[0].pb(0);
    thisLevel = 0;
    nxt.pb(0);
    while(!nxt.empty()){
        st[0] = nxt;
        nxt.clear();
        for(int a=0;a<MAXN;a++){
            if(st[a].empty()) continue;
            int step = a;
            for(int u: st[a]){
                if(u > 0)
                    add(u-1, step + s[u] - s[u-1]);
                if(u+1 < n)
                    add(u+1, step + s[u+1] - s[u]);
            }
            st[a].clear();
        }
        thisLevel++;
    }

    ll ans = LLONG_MAX;
    for(int dis=0;dis < MAXD;dis++){
        if(lvl[n-1][dis] == -1) continue;
        ans = min(ans, dis + lvl[n-1][dis]*((ll)G + R));
    }
    if(lvl[n-1][0] != -1)
        ans = min(ans, lvl[n-1][0]*((ll)G + R) - R);
    if(ans == LLONG_MAX)
        puts("-1");
    else
        printf("%lld\n", ans);
}

