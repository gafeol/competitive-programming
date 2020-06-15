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

const int MAXN = 2523;
const int MAXND = 1005*1005 + 10;
const int LOGN = 25;

int n, m, k;

char M[MAXN][MAXN];
int id[MAXN][MAXN], cnt;
int rn, rm;

int vi[] = {-2, 0, 2, 0};
int vj[] = {0, 2, 0, -2};

bool valid(int i, int j){
    return (i >= 1 && j >= 1 && i < n-1 && j < m-1 && M[i][j] == ' ');
}

vector<int> adj[MAXND];

void add_edge(int i, int j){
    adj[i].pb(j);
    adj[j].pb(i);
}

void go(int i, int j){ //OK
    id[i][j] = cnt++; 
    //printf("i %d j %d id %d\n", i, j, cnt-1);
    for(int d=0;d<4;d++){
        int ii = i + vi[d], si = i + vi[d]/2, jj = j + vj[d], sj = j + vj[d]/2;
        if(valid(ii, jj) && valid(si, sj) && !id[ii][jj]){
            go(ii, jj);
            add_edge(id[i][j], id[ii][jj]);
        }
    }
}

int h[MAXND];
int pai[MAXND][LOGN];

void dfs(int u, int p){ // OK
    h[u] = h[p] + 1;
    pai[u][0] = p;
    for(int i=1;i<LOGN;i++)
        pai[u][i] = pai[pai[u][i-1]][i-1];
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        dfs(nxt, u);
    }
}

int lca(int u, int v){ // OK
    if(u == v) return u;
    if(h[u] != h[v]){
        if(h[u] < h[v])
            swap(u, v);
        for(int i=LOGN-1;i>=0;i--){
            if(h[pai[u][i]] > h[v])
                u = pai[u][i];
        }
        u = pai[u][0];
    }
    if(u == v)
        return u;
    assert(h[u] == h[v]);
    for(int i=LOGN-1;i>=0;i--){
        if(pai[u][i] != pai[v][i]){
            u = pai[u][i];
            v = pai[v][i];
        }
    }
    assert(u != v && pai[u][0] == pai[v][0]);
    return pai[u][0];
}

int move(int u, int v){ // OK
    if(u == 0) return 0;
    int lc = lca(u, v);
    return h[u]  + h[v] - 2*h[lc];
}

int main (){
	scanf("%d%d", &rn,&rm);
	for(int a=0;a<rn+1;a++){
        int i = a*2;
        for(int b=0;b<2*rm+1;b++){
            M[i][b] = ' ';
            M[i+1][b] = ' ';
            char c;
            scanf("%c", &c);
            if(c == '\n'){
                b--;
                continue;
            }
            if(c == '|')
                M[i][b] = c;
            else if(c == '_')
                M[i+1][b] = c;
        }
	}
    n = 2*(rn+1);
    m = 2*rm+1;
    cnt = 1;
    go(2, 1);
//    for(int a=0;a<n;a++){
//        for(int b=0;b<m;b++){
//            if(M[a][b] == ' ')
//                printf("%d", id[a][b]);
//            else
//                printf("%c", M[a][b]);
//        }
//        puts("");
//    }
    dfs(1, 1);
    scanf("%d", &k);
    int pos = 0;
    ll ans = 0;
    for(int a=0;a<k;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        assert(id[i*2][j*2-1]);
        ans += move(pos, id[i*2][j*2-1]);
        pos = id[i*2][j*2-1];
    }
    printf("%lld\n", ans);
}

