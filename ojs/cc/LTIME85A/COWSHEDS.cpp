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

const int MAXN = 200005;
int n, m, k;
int s[MAXN], p[MAXN];
set<pii> in[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void add(set<pii> &q, pii p){
    pii res = p;
    auto it = q.lower_bound(p);
    if(it != q.end() && it->fst == p.snd + 1){
        res.snd = it->snd;
        q.erase(it);
    }

    it = q.lower_bound(p);
    if(it != q.begin() && (--it)->snd + 1 == p.fst){
        res.fst = it->fst;
        q.erase(it);
    }

    q.insert(res);
}

inline bool join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j) return false;
    if(in[i].size() < in[j].size())
        swap(i, j);

    for(auto u: in[j]){
        add(in[i], u);
    }
    in[j].clear();
    p[j] = i;
    return true;
}

int main (){
	scanf("%d%d", &n, &m);
    int res = n;
    for(int a=1;a<=n;a++){
        p[a] = a;
        in[a].clear();
        in[a].insert({a, a});
    }
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        while(i < j){
            //printf("join i %d j %d\n", i, j);
            res -= join(i, j);
            int ri = raiz(i);
            int rj = raiz(j);
            int k = 1 + min((--in[ri].upper_bound({i, INT_MAX}))->snd  - i,
                        j - (--in[rj].upper_bound({j, INT_MAX}))->fst);
            //printf("k = 1 + min(%d - %d, %d - %d)\n", in[ri].lower_bound({i, -1})->snd, i, j, (--in[rj].upper_bound({j, INT_MAX}))->fst);
            i += k;
            j -= k;
        }
        printf("%d\n", res);
	}
}
