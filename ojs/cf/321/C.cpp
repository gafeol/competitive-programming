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

int n, m, k;
char ans[MAXN];
int sz[MAXN], mrk[MAXN];
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

void decomp(int u, char car){
    if(car > 'Z'){
        puts("Impossible!");
        exit(0);
    }
    getsz(u, u);
    int c = getc(u,u,sz[u]);
    mrk[c] = true;
    ans[c] = car;
    for(int nxt: adj[c]){
        if(mrk[nxt]) continue;
        decomp(nxt, car+1);
    }
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    decomp(1, 'A');
    for(int a=1;a<=n;a++){
        printf("%c%c", ans[a], " \n"[a==n]);
    }
}

