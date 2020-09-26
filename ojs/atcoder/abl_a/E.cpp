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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
struct arv{
    ll s, lz;
} tree[MAXN*4];
ll pot[MAXN]; 

ll join(arv a, int sza, arv b, int szb){
    return mod(mod(a.s*pot[szb]) + b.s);
}

void build(int idx, int i, int j){
    tree[idx].lz = 0;
    if(i == j){
        tree[idx].s = 1;
        return ;
    }
    int m = (i+j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx].s = join(tree[idx*2], m-i+1, tree[idx*2+1], j-m);
}

ll som[10][MAXN];

void unlaze(int idx, int i, int j){
    if(tree[idx].lz){
        int d = tree[idx].lz; 
        tree[idx].lz = 0;
        if(i != j){
            int m = (i+j)/2;
            tree[idx*2].lz = d;
            tree[idx*2].s = som[d][m-i+1];
            tree[idx*2+1].lz = d;
            tree[idx*2+1].s = som[d][j-m];
        }
    }
}

void upd(int idx, int i, int j, int l, int r, int d){
    if(i > r || j < l) return;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].lz = d;
        tree[idx].s = som[d][j -i +1];
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, d);
    upd(idx*2+1, m+1, j, l, r, d);
    tree[idx].s = join(tree[idx*2], m-i+1, tree[idx*2+1], j-m);
}

int main (){
	scanf("%d%d", &n, &m);
    pot[0] = 1;
    for(int a=1;a<=n;a++)
        pot[a] = mod(pot[a-1]*10);
    for(int d=1;d<=9;d++){
        som[d][0] = 0;
        for(int a=1;a<=n;a++){
            som[d][a] = mod(som[d][a-1]*10 + d);
        }
    }
    build(1, 0, n-1);
	for(int a=0;a<m;a++){
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        i--;j--;
        upd(1, 0, n-1, i, j, k);
        printf("%lld\n", tree[1].s);
	}
}

