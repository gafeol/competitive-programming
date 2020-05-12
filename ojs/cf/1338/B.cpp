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
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
int mrk[MAXN];
int mx[MAXN][3][2];

vector<int> adj[MAXN];

int go(int u, int p, int val, bool ap){
    int cnt = 0;
    int &r = mx[u][val][ap];
    if(r != -1) return r;
    r = 0;
    if(val == 0){
        for(int nxt: adj[u]){
            if(nxt == p) continue;
            r += 1+go(nxt, u, 1, 0);
            cnt++; 
        }
    }
    else if(val == 1){
        for(int nxt: adj[u]){
            if(nxt == p) continue;
            r += max(1+go(nxt, u, 2, 0), go(nxt, u, 0, 0));
            cnt++; 
        }
    }
    else{
        if(ap){
            bool ok = false;
            for(int nxt: adj[u]){
                if(nxt == p) continue;
                int nop = go(nxt, u, 0, 0); 
                int pay = 1 + go(nxt, u, 2, 0);
                if(nop >= pay)
                    ok = true;
                r += max(nop, pay);
                cnt++;
            }
            if(!ok)
                r = -INF;
        }
        else{
            r = max(r, go(u, p, val, 1) + 1);
            int aux = 0;
            for(int nxt: adj[u]){
                if(nxt == p) continue;
                aux += 1 + go(nxt, u, 2, 0);
                cnt++; 
            }
            r = max(r, aux);

        }

    }
    if(r < -1)
        r = -INF;

    if(cnt == 0){
        if(val == 0)
            r = 0;
        else
            r = -INF;
    }
    printf("u %d val %d ap %d dp %d\n", u, val, ap, mx[u][val][ap]);
    return r;
}

bool imp;

void dfs(int u, int p, int d){
    int cnt = 0;
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        dfs(nxt, u, d+1);
        cnt++;
    }
    if(!cnt && (d&1))
       imp = true; 
}

int main (){
    memset(mx, -1, sizeof(mx));
	scanf("%d", &n);
	for(int a=1;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
	}

    imp = false;
    int f =0;
    for(int a=1;a<=n;a++){
        if(adj[a].size() == 1){
            mrk[a] = 1;
            f = a;
        }
    }
    dfs(f, f, 0);
	
    int ans = n-1;
	
    for(int a=1;a<=n;a++){
        if(mrk[a]) continue;
        int cnt = 0;
        for(int nxt: adj[a])
            cnt += mrk[nxt];
        if(cnt)
            ans -= (cnt-1);
        //printf("a %d cnt %d\n", a, cnt);
    }

    printf("%d %d\n", (imp ? 3: 1), ans);
}

