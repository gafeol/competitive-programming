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

const int MAXN = 512345;

vector<tuple<char, int, int>> ev;
vector<int> ot;

int add(int t, int i, int j, int o=-1){
    if(t == '?')
        ot.pb(ot.size());
    else if(t == '+')
        ot.pb(-1);
    else {
        ot[o] = ev.size();
        ot.pb(o);
    }
    ev.emplace_back(t, i, j);
    return ev.size()-1;
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

int p[MAXN], sz[MAXN];

int raiz(int u){
    return (u == p[u] ? u : raiz(p[u]));
}

stack<pii> chg;

bool join(int u, int v){
    u = raiz(u);
    v = raiz(v);

    if(u == v) return false;

    if(sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    p[v] = u;
    chg.push({u, v});
    return true;
}

void rollback(){
    auto [u, v] = chg.top();
    chg.pop();
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
        printf("%d\n", sz[raiz(u)]);
        return ;
    }

    int nchg = 0;
    int m = (i + j)/2;
    for(int a=m+1;a<=j;a++){
        if(ot[a] < i){
            auto [ignore, u, v] = ev[a];
            if(join(u, v)){
                nchg++;
            }
        }
    }
    solve(i, m);
    while(nchg > 0){
        rollback();
        nchg--;
    }
    for(int a=i;a<=m;a++){
        if(ot[a] > j){
            auto [ignore, u, v] = ev[a];
            if(join(u, v)){
                nchg++;
            }
        }
    }
    solve(m+1, j);
    while(nchg > 0){
        rollback();
        nchg--;
    }
}

int n, m, k;

int main (){
	scanf("%d%d%d", &n, &m, &k);
    for(int a=1;a<=n;a++){
        p[a] = a;
        sz[a] = 1;
    }
    int dia = 0;
    queue<tuple<int, int, int, int>> q;
	for(int a=0;a<m;a++){
        int t;
        char tipo;
        int i, j;
        scanf(" %d", &t);
        if(t == 1){
            scanf("%d%d", &i, &j);
            tipo = '+';
            int pos = add('+', i, j);
            q.push({dia, pos, i, j});
        }
        else if(t == 2){
            tipo = '?';
            scanf("%d", &i);
            add('?', i, i);
        }
        else {
            dia++;
            while(!q.empty() && get<0>(q.front()) <= dia-k){
                add('-', get<2>(q.front()), get<3>(q.front()), get<1>(q.front()));
                q.pop();
            }
        }
	}
    fixOt();
    solve(0, ev.size()-1);
}
