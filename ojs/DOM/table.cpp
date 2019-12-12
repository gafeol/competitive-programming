#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#define mp make_pair
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2023;

int n, m, k;
int X,Y;
int M[MAXN][MAXN], xm[MAXN][MAXN];

pll bit[MAXN];

pll operator+(const pll &a, const pll &b){
    return mp(a.fst + b.fst, a.snd + b.snd);
}

void upd(int i, int val){
    debug("upd %d %d\n", i, val);
    int sz = i;
    i += 2;
    while(i > 0){
        bit[i] = bit[i] + mp(1*val, sz*val);
        i -= (i&-i); 
    }
}

pll qry(int i){
    i += 2;
    pll ans = mp(0ll, 0ll);
    while(i < MAXN){
        ans = ans + bit[i];        
        i += (i&-i);
    }
    return ans;
}

ll resp(ll sz){
    pll q = qry(sz); 
    debug("qtd maior que %lld : %lld soma %lld\n", sz, q.fst, q.snd);
    return q.snd - q.fst*(sz-1ll);
}

int pai[MAXN*MAXN], sz[MAXN*MAXN];

int ind(int x, int y){
    return x*(Y+1) + y;
}

int raiz(int u){
    if(pai[u] == u) return u;
    return pai[u] = raiz(pai[u]);
}

void join(int i, int j){
    if(min(sz[i], sz[j]) == 0) return;
    i = raiz(i);
    j = raiz(j);
    if(i == j) return;
    debug("join %d %d\n", i, j);
    upd(sz[i], -1);
    upd(sz[j], -1);
    if(sz[i] < sz[j])
        swap(i, j);
    pai[j] = i;
    sz[i] += sz[j];
    upd(sz[i], 1);
}

void add(int x, int y){
    debug("add %d %d\n", x, y);
    upd(1, 1);
    pai[ind(x, y)] = ind(x, y);
    sz[ind(x, y)] = 1;
    if(y > 0)
        join(ind(x, y), ind(x, y-1));
    if(y < Y)
        join(ind(x, y), ind(x, y+1));
}

int main (){
	scanf("%d%d%d%d", &X, &Y, &m, &n);
    X--;
    Y--;
	for(int a=0;a<m;a++){
        int x, xx, y, yy;
        scanf("%d%d%d%d", &x, &xx, &y, &yy);
        for(int a=x;a<xx;a++){
            for(int b=y;b<yy;b++){
                M[a][b] = -1;
            }
        }
	}
    for(int a=0;a<=X;a++)
        xm[a][Y+1] = a;
    for(int b=0;b<=Y;b++)
        xm[X+1][b] = X+1;
   
    vector<pair<int, pii>> pos;
    for(int a=X;a>=0;a--){
        for(int b=Y;b>=0;b--){
            if(M[a][b] == -1)
                xm[a][b] = a;
            else{
                xm[a][b] = xm[a+1][b];
                pos.pb(mp(xm[a][b] - a, mp(a, b)));
                debug("pos %d %d val %d\n", a, b, xm[a][b] - a);
            }
        }
    }
    sort(pos.begin(), pos.end(), greater<pair<int, pii>>());
    vector<pair<pii, int>> dish;
    vector<ll> ans(n);
    for(int a=0;a<n;a++){
        int x, y;
        scanf("%d%d", &x, &y);
        dish.pb(mp(mp(x, y), a));
    }
    sort(dish.begin(), dish.end(), greater<pair<pii, int>>()); 
    int i = 0;
    for(pair<pii, int> d: dish){
        int idx = d.snd;
        int x = d.fst.fst, y = d.fst.snd; 
        debug("dish %d %d %d\n", idx, x, y);
        if(i < pos.size())
            debug("pos[%d].fst %d >= %d\n", i, pos[i].fst, x);
        while(i < pos.size() && pos[i].fst >= x){
            add(pos[i].snd.fst, pos[i].snd.snd);
            i++;
            if(i < pos.size())
                debug("pos[%d].fst %d >= %d\n", i, pos[i].fst, x);
        }
        ans[idx] = resp(y);
    }
    for(int a=0;a<n;a++){
        printf("%lld\n", ans[a]);
    }
}

