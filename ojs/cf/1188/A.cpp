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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
vector<int> adj[MAXN];

void go(int u, int p){
    int sz = 0;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        sz++;
        go(nxt, u);
    }
    if(sz == 0)
        s[u] = 1;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int u, v;
        scanf("%d%d", &u,&v);
        adj[u].pb(v);
        adj[v].pb(u);
	}
    if(n == 2){
        puts("YES");
        return 0;
    }
    int u = 0;
    for(int a=1;a<=n;a++){
        if(adj[a].size() > 1)
            u = a;
    }
    go(u, u);
    for(int a=1;a<=n;a++){
        if(!s[a] && adj[a].size() < 3){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}

