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
int s[MAXN];
int p[MAXN];
vector<int> adj[MAXN];
int h[MAXN];

vector<int> ans;

void geth(int u){
    for(int nxt: adj[u]){
        geth(nxt);
        h[u] = max(h[u], h[nxt]);
    }
    sort(adj[u].begin(), adj[u].end(), [&](int a, int b){ return h[a] < h[b]; });
    h[u]++;
}

void go(int u){
    printf("%d ", u);
    bool pri = true;
    int lst = -1;
    for(int nxt: adj[u]){
        go(nxt);
        if(pri){
            pri = false;
        }
        else{
            while(h[lst]--){
                ans.pb(nxt);
            }
        }
        lst = nxt;
    }
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        scanf("%d", p+a);
        adj[p[a]].pb(a);
	}
    geth(0);
    go(0);
    puts("");
    printf("%d\n", (int)ans.size());
    for(int x: ans)
        printf("%d ", x);
    puts("");
}

