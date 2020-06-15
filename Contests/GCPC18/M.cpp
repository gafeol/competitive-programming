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

const int MAXN = 262345;
const int LOGN = 27;

int n, m, k;
int M[510][510];

int pai[MAXN], sz[MAXN];

bool valid(int i, int j){
    return (i>=0 && i < n && j>=0 && j < m);
}

int raiz(int u){
    return pai[u] = (pai[u] == u ? u : raiz(pai[u]));
}

bool join(int u, int v){
    u = raiz(u); v = raiz(v);
    if(u == v) return false;
    if(sz[u] < sz[v])
        swap(u, v);

    pai[v] = u;
    sz[u] += sz[v];
    return true;
}

vector<pii> adj[MAXN];

int p[MAXN][LOGN], h[MAXN];
int mx[MAXN][LOGN];

void go(int u, int bef, int cus=0){
    h[u] = h[bef] + 1;
    p[u][0] = bef; 
    mx[u][0] = cus;
    for(int i=1;i<LOGN;i++){
        p[u][i] = p[p[u][i-1]][i-1];
        mx[u][i] = max(mx[u][i-1], mx[p[u][i-1]][i-1]);
    }
    for(pii ar: adj[u]){
        if(ar.fst == bef) continue;
        go(ar.fst, u, ar.snd);
    }
}

int val(int u, int v){
    int ans = INT_MIN;
    if(h[u] != h[v]){
        if(h[u] < h[v])
            swap(u, v);
        for(int i=LOGN-1;i>=0;i--){
            if(h[p[u][i]] > h[v]){
                ans = max(ans, mx[u][i]);
                u = p[u][i];
            }
        }
        ans = max(ans, mx[u][0]);
        u = p[u][0];
    }
    if(u != v){
        for(int i=LOGN-1;i>=0;i--){
            if(p[u][i] != p[v][i]){
                ans = max(ans, max(mx[u][i], mx[v][i]));
                u = p[u][i];
                v = p[v][i];
            }
        }
        ans = max(ans, max(mx[u][0], mx[v][0]));
    }
    return ans;
}

int id(int i, int j){
    return i*m + j;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf("%d", &M[a][b]); 
            pai[id(a, b)] = id(a, b);
            sz[id(a, b)] = 1;
        }
	}
    int vi[] = {0, 1, 0, -1};
    int vj[] = {1, 0, -1, 0};
    vector<tuple<int, int, int> > ed;
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            for(int d=0;d<4;d++){
                int aa = a + vi[d], bb = b + vj[d];
                if(valid(aa, bb) && M[a][b] >= M[aa][bb]){
                    ed.pb({M[a][b], id(a, b), id(aa, bb)}); 
                }
            }
        }
    }
    sort(ed.begin(), ed.end());
    for(tuple<int, int, int> tp: ed){
        int i, j, cus;
        tie(cus, i,j) = tp;
        if(join(i, j)){
            //printf("join %d (%d %d) %d (%d %d) com cus %d\n", i, i/m, i%m, j, j/m, j%m, cus);
            adj[i].pb({j, cus});
            adj[j].pb({i, cus});
            //printf("i %d j %d cus %d\n", i, j, cus);
        }
    }
    go(0, 0);
    for(int a=0;a<k;a++){
        int i, ii, j, jj;
        scanf("%d%d%d%d", &i, &j, &ii, &jj);
        i--;j--;ii--;jj--;
        int u = id(i, j); int v = id(ii, jj);
        if(u == v){
            printf("%d\n", M[i][j]);
        }
        else{
            printf("%d\n", val(u, v));
        }
    }
}

