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
vector<int> adj[MAXN][2];
int deg[MAXN];

int mrk[MAXN][2];

char ans[MAXN];

void go(int u, int d){
    mrk[u][d] = 1;
    if(ans[u] == 0)
        ans[u] = 'E';
    for(int nxt: adj[u][d]){
        if(mrk[nxt][d]) continue;
        go(nxt, d);
    }
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i,j;
        scanf("%d %d", &i, &j);
        adj[i][0].pb(j);
        adj[j][1].pb(i);
        deg[j]++;
	}

    queue<int> q;
    for(int a=1;a<=n;a++){
        if(deg[a] == 0){
            q.push(a);
        }
    }
    int vis = 0;
    while(!q.empty()){
        vis++;
        int u = q.front();
        q.pop();
        for(int nxt: adj[u][0]){
            deg[nxt]--;
            if(deg[nxt] == 0)
                q.push(nxt);
        }
    }
    if(vis != n){
        puts("-1");
        return 0;
    }

    for(int a=1;a<=n;a++){
        ans[a] = 0;
    }

    int res = 0;
    for(int a=1;a<=n;a++){
        if(ans[a] != 0){
            go(a, 0);
            go(a, 1);
        }
        else{
            res++;
            ans[a] = 'A';               
            go(a, 0);
            go(a, 1);
        }
    }
    printf("%d\n", res);
    for(int a=1;a<=n;a++){
        printf("%c", ans[a]);
    }
    puts("");

}

