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

const int MAXN = 10034;

int n, m, k;
int s[MAXN];

vector<pii> adj[MAXN];
int cor[MAXN];
bool on[MAXN];
int C;

int qtdI[MAXN], qtdP[MAXN];
int h[MAXN];

void go(int u, int p){
    h[u] = h[p] + 1;
    cor[u] = (cor[p] == 0);
    for(pii are: adj[u]){
        int nxt = are.fst;
        int id = are.snd;
        if(nxt == p) continue;
        if(cor[nxt] == -1){
            on[id] = true;
            go(nxt, u);
            qtdI[u] += qtdI[nxt];
            qtdP[u] += qtdP[nxt];
        }
        else if(h[nxt] < h[u] && cor[nxt] == cor[u]){
            qtdI[u]++;
            qtdI[nxt]--;
            C++;
        }
        else if(h[nxt] < h[u] && cor[nxt] != cor[u]){
            qtdP[u]++;
            qtdP[nxt]--;
        }
    }
}

int main (){
	scanf("%d%d", &n, &m);
    memset(cor, -1, sizeof(cor));
    vector<pii> ar;
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb({j, a});
        adj[j].pb({i, a});
        ar.pb({i, j});
	}
    for(int a=1;a<=n;a++){
        if(cor[a] == -1){
            go(a, a);
        }

    }
    if(C == 0){
        printf("%d\n", m);
        for(int a=1;a<=m;a++)
            printf("%d ", a);
        puts("");
        return 0;
    }

    //printf("c %d\n", C);
    vector<int> ans;
    for(int id=0;id<m;id++){
        int u = ar[id].fst, v = ar[id].snd;
        if(h[u] > h[v])
            swap(u, v);
        //printf("u %d v %d on %d qtdI %d qtdP %d\n", u, v, on[id], qtdI[v], qtdP[v]);
        if(on[id]){
            if(qtdI[v] == C && qtdP[v] == 0)
                ans.pb(id+1);
        }
        else{
            if(cor[u] == cor[v] && C == 1){
                ans.pb(id+1);
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for(int x: ans)
        printf("%d ", x);
    puts("");
}

