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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
ll f[MAXN];
vector<int> adj[MAXN];

ll go(int u, int p){
    ll ans = 1;
    int cnt = 1;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        cnt++;
        ans = mod(ans*go(nxt, u));
    }
    if(u == p)
        ans = mod(ans*mod(f[cnt-1]*n));
    else
        ans = mod(ans*f[cnt]);
    return ans;
}

int main (){
    f[0] = 1;
    for(int a=1;a<MAXN;a++)
        f[a] = mod(a*f[a-1]);
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    ll ans = go(1, 1);
    printf("%lld\n", ans);
}

