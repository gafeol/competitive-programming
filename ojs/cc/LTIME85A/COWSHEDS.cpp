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
const int PRI =  200003;

int n, m, k;
int s[MAXN], p[MAXN];
ull pot[MAXN];

struct arv{
    ull h, invh;
    int tot;
} tree[MAXN*4];

inline arv join(arv a, arv b){
    arv c;
    c.h = pot[b.tot]*a.h + b.h;
    c.invh = pot[a.tot]*b.invh + a.invh;
    c.tot = a.tot + b.tot;
    return c;
}

arv qry(int idx, int i, int j, int l, int r){
   if(i > r || j < l)
       return {0ull, 0ull, 0};
   if(i >= l && j <= r)
        return tree[idx];
   int m = (i + j)/2;
   return join(qry(idx*2, i, m, l, r), 
                qry(idx*2+1,m+1, j, l, r));
}

void upd(int idx, int i, int j, int l, int x){
    if(i > l || j < l) return;
    if(i == j){
        tree[idx] = {(ull)x, (ull)x, 1};
        return ;
    }

    int m = (i + j)/2;
    upd(idx*2, i, m, l, x);
    upd(idx*2+1, m+1, j, l, x);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}


void build(int idx, int i, int j){
    if(i == j){
        tree[idx].h = tree[idx].invh = i;
        tree[idx].tot = 1;
        return ;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

vector<int> in[MAXN];

inline bool join(int i, int j){
i = raiz(i);
    j = raiz(j);
    if(i == j) return false;
    if(in[i].size() < in[j].size())
        swap(i, j);

    for(int u: in[j]){
        upd(1, 1, n, u, i);
        in[i].pb(u);
        p[u] = i;
    }
    in[j].clear();
    p[j] = i;
    return true;
}

int main (){
    pot[0] = 1;
    for(int a=1;a<MAXN;a++)
        pot[a] = pot[a-1]*PRI;
	scanf("%d%d", &n, &m);
    int res = n;
    for(int a=1;a<=n;a++){
        p[a] = a;
        in[a].pb(a);
    }
    build(1, 1, n);
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        int de = i, ate = (i + j)/2;
        while(de <= (i+j)/2){
            res -= join(de, j - (de - i));
            ate = (i + j)/2;
            while(de < ate){
                int mid = (de+ate+1)/2;
                int k = mid - i;
                if(qry(1, 1, n, i, i+k).h == qry(1, 1, n, j-k, j).invh)
                    de = mid;
                else
                    ate = mid-1;
            }
            de++;
        }
        printf("%d\n", res);
	}
}
