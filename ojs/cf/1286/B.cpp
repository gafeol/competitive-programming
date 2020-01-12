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

const int MAXN = 2123;

int n, m, k;
int p[MAXN], c[MAXN], sz[MAXN], h[MAXN];
int ans[MAXN];
vector<int> adj[MAXN];

int go(int u){
    sz[u] = 0;
    for(int nxt: adj[u]){
        h[nxt] = h[u] + 1;
        sz[u] += go(nxt) + 1;
    }
    return sz[u];
}

stack<int> solve;
int cnt = 1;

void up(int u){
    while(u != 0){
        if(!ans[u]){
            c[u]--; 
            assert(c[u] >= 0);
            if(!c[u])
                solve.push(u);
        }
        u = p[u];
    }
}

void upd(){
    while(!solve.empty()){
        int u = solve.top();
        ans[u] = cnt++;
        solve.pop();
        up(u);
    }
}

int main (){
	scanf("%d", &n);
    int r = 0;
    set<tuple<int, int, int>> q;
	for(int a=1;a<=n;a++){
        scanf("%d%d", p+a, c+a);
        if(!p[a])
            r = a;
        else{
            adj[p[a]].pb(a);
        }
	}
    h[r] = 0;
    go(r);
    for(int a=1;a<=n;a++){
        if(sz[a] < c[a]){
            puts("NO");
            return 0;
        }
        q.insert({c[a], h[a], a});
    }
    while(!q.empty()){
        int u;
        tie(ignore, ignore, u) = *q.begin();        
        q.erase(q.begin());
        if(ans[u]) continue;
        solve.push(u);
        upd();
    }
    puts("YES");
    for(int a=1;a<=n;a++){
        printf("%d ", ans[a]);
    }
    puts("");
}

