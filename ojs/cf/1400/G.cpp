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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 312345;

int n, m, k;
pii s[MAXN];

ll fat[MAXN], inv[MAXN];

ll expo(ll base, ll e){
    if(e == 0)
        return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

int mrk[MAXN], del[MAXN];

ll ch(ll x, ll y){
    return mod(fat[x]*mod(inv[y]*inv[x-y]));
}

ll go(int l, int r){
    map<int, int> ev;
    ll res = 0;
    for(int a=0;a<n;a++){
        if(mrk[a] || del[a]) continue;
        ev[s[a].fst]++;
        ev[s[a].snd+1]--;
    }
    int cnt = 0;
    for(int np=1;np<=n;np++){
        int bal = ev[np];
        cnt += bal;
        if(np >= l && np <= r){
            // tem que incluir pivo            
            if(cnt < np) continue;
            res = mod(res + ch(cnt-1, np-1));
        }
    }
    return res;
}

vector<int> adj[MAXN];
int main (){
	scanf("%d%d", &n,&m);
    fat[0] = 1;
    inv[0] = 1;
    for(ll a=1;a<=n;a++){
        fat[a] = mod(fat[a-1]*a);
        inv[a] = expo(fat[a], modn-2);
    }
	for(int a=0;a<n;a++)
        scanf("%d%d", &s[a].fst, &s[a].snd);
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);
        adj[j].pb(i);
    }
    ll ans = 0;
    for(int a=0;a<n;a++){
        if(adj[a].empty())
            continue;
        // sol com a
        for(int nxt: adj[a]){
            mrk[nxt] = true;
        }
        ans = mod(ans + go(s[a].fst, s[a].snd));
        for(int nxt: adj[a]){
            mrk[nxt] = false;
        }
        del[a] = true;
    }
    map<int, int> ev;
    for(int a=0;a<=n;a++)
        ev[a] = 0;
    for(int a=0;a<n;a++){
        if(del[a]) continue;
        ev[s[a].fst]++;
        ev[s[a].snd+1]--;
    }
    int cnt = 0;
    for(int np=1;np<=n;np++){
        int bal = ev[np];
        cnt += bal;
        if(cnt < np) continue;
        ans = mod(ans + ch(cnt, np));
        //printf("livres np %d cnt %d ans += %lld\n", np, cnt, ch(cnt, np));
    }
    printf("%lld\n", ans);
}

