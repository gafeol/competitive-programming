#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pil;
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

int n, m, k;
int s[MAXN];
vector<pil> adj[MAXN];
ll ans[MAXN];

void go(int u, int p, ll mn){
    ans[u] = mn;
    for(pil ar: adj[u]){
        int nxt = ar.fst;
        ll c = ar.snd;
        if(nxt == p) continue;
        go(nxt, u, min(mn, c));
    }
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int i, j;
        ll c;
        scanf("%d%d%lld", &i, &j, &c);
        adj[i].pb({j, c});
        adj[j].pb({i, c});
	}
    go(n, n, LLONG_MAX);
    for(int a=1;a<n;a++)
        printf("%lld%c", ans[a], " \n"[a==n-1]);
}

