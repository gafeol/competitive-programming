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
int s[MAXN];
vector<int> adj[MAXN];

int mrk[MAXN];

void blc(int u, int c){
    mrk[u] = 1;
    for(int nxt: adj[u]){
        if(nxt == c || mrk[nxt]) continue;
        blc(nxt, c);
    }
}

int mxd, v;

void dfs(int u, int p, int d){
    if(d > mxd){
        mxd = d;
        v = u;
    }
    for(int nxt: adj[u]){
        if(nxt == p || mrk[nxt]) continue;
        dfs(nxt, u, d+1);
    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        adj[i].pb(j);
        adj[j].pb(i);
    }
    int u = 0;
    while(1){
        mxd = -1;
        dfs(u, u, 0);
        u = v;
        mxd = -1;
        dfs(u, u, 0);
        if(u == v){
            printf("! %d\n", u+1);
            fflush(stdout);
            return 0;
        }
        printf("? %d %d\n", u+1, v+1);
        fflush(stdout);
        int c;
        scanf("%d", &c);
        if(c == -1)
            return 0;
        c--;
        if(c != u)
            blc(u, c);
        if(c != v)
            blc(v, c);

        u = c;
    }
}

