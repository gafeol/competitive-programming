#include "bits/stdc++.h"
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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

vector<tuple<char, int, int>> ev;
vector<int> ot;
map<int, map<int, int>> at;

void add(int t, int i, int j){
    if(i < j) swap(i, j);
    if(t == '?'){
        ot.pb(ot.size());
    }
    else if(t == '+'){
        at[i][j] = ev.size();
        ot.pb(-1);
    }
    else {
        ot[at[i][j]] = ev.size();
        ot.pb(at[i][j]);
    }
    ev.emplace_back(t, i, j);
}

void fixOt(){
    for(int i=0;i<ev.size();i++){
        if(ot[i] == -1){
            ot[i] = ev.size();
            ot.pb(i);
            ev.emplace_back('-', get<1>(ev[i]), get<2>(ev[i]));
        }
    }
}

vector<int> ans;
int comp;

int p[MAXN], sz[MAXN];

int raiz(int u){
    return (u == p[u] ? u : raiz(p[u]));
}

stack<pii> chg;

bool join(int u, int v){
    //printf("join(%d %d):\n", u, v);
    u = raiz(u);
    v = raiz(v);

    if(u == v) return false;

    if(sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    p[v] = u;
    chg.push({u, v});
    //printf("OK liga %d %d\n", u, v);
    return true;
}

void rollback(){
    auto [u, v] = chg.top();
    chg.pop();
    //printf("rollback %d %d\n", u, v);
    sz[u] -= sz[v];
    p[v] = v;
}

void solve(int i, int j){
    if(i == j){
        char t;
        int u, v;
        tie(t, u, v) = ev[i];
        if(t != '?')
            return;
        printf("%d\n", comp);
        return ;
    }

    int nchg = 0;
    int m = (i + j)/2;
    for(int a=m+1;a<=j;a++){
        if(ot[a] < i){
            auto [ignore, u, v] = ev[a];
            if(join(u, v)){
                nchg++;
                comp--;
            }
        }
    }
    solve(i, m);
    while(nchg > 0){
        rollback();
        comp++;
        nchg--;
    }
    for(int a=i;a<=m;a++){
        if(ot[a] > j){
            auto [ignore, u, v] = ev[a];
            if(join(u, v)){
                nchg++;
                comp--;
            }
        }
    }
    solve(m+1, j);
    while(nchg > 0){
        rollback();
        comp++;
        nchg--;
    }
}

int main (){
	scanf("%d%d", &n, &m);
    if(m == 0)
        return 0;
    comp = n;
    for(int a=1;a<=n;a++){
        p[a] = a;
        sz[a] = 1;
    }
	for(int a=0;a<m;a++){
        char t;
        int i, j;
        scanf(" %c", &t);
        if(t != '?')
            scanf("%d%d", &i, &j);
        add(t, i, j);
	}
    fixOt();
    /*
    for(int a=0;a<ev.size();a++){
        auto [t, i, j] = ev[a];
        printf("ev[%d]: %c %d %d ot %d\n",a, t, i, j, ot[a]);
    }
    */
    ans.resize(ev.size());
    solve(0, ev.size()-1);
}

