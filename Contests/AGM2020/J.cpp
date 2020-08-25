#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int MAXN = 100006;

int n, m, k;
ll M[10][MAXN];

ll acc[10][10][MAXN];

struct arv{
    ll sl, sr;
    ll bst, tot;
} tree[11*5][4*MAXN];

int id[10][10];

ll INV = LLONG_MAX;
arv join(arv a, arv b){
    if(a.tot == INV)
        return b;
    if(b.tot == INV)
        return a;
    arv c;
    c.sl = max(a.sl, a.tot + b.sl);
    c.sr = max(b.sr, b.tot + a.sr);
    c.tot = a.tot + b.tot;
    c.bst =    max(a.bst, 
                max(b.bst, 
                max(a.sr + b.sl,
                max(c.tot, 
                max(c.sl, c.sr)))));
    return c;
}

void upd(int t, int tt, int idx, int i, int j, int l, ll x){
    arv &r = tree[id[t][tt]][idx];
    //unlaze(t, tt, idx, i, j);
    if(i == j){
        r.sl = r.sr = r.tot = r.bst = x;
        return ;
    }
    int m = (i + j)/2;
    if(l > m)
        upd(t, tt, idx*2+1, m+1, j, l, x); 
    else
        upd(t, tt, idx*2, i, m, l, x);
    r = join(tree[id[t][tt]][idx*2], tree[id[t][tt]][idx*2+1]);
}

arv qry(int t, int tt, int idx, int i, int j, int l, int r){
    if(i > r || j < l) 
        return {INV, INV, INV, INV};
    //unlaze(t, tt, idx, i, j);
    if(i >= l && j <= r)
        return tree[id[t][tt]][idx];
    int m = (i + j)/2;  
    return join(qry(t, tt, idx*2, i, m, l, r),
                qry(t, tt, idx*2+1, m+1, j, l, r));
}

int main (){
    int idd = 0;
    for(int a=0;a<10;a++){
        for(int b=a;b<10;b++){
            id[a][b] = idd++;
        }
    }
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=1;b<=m;b++){
            scanf("%lld", &M[a][b]);
        }
	}
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int a=1;a<=m;a++){
                acc[i][j][a] = (j > i ? acc[i][j-1][a] : 0) + M[j][a];
                upd(i, j, 1, 1, m, a, acc[i][j][a]);
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int i, j;
            ll x;
            scanf("%d%d%lld", &i, &j, &x);
            i--;
            for(int a=0;a<=i;a++){
                for(int b=i;b<n;b++){
                    acc[a][b][j] += x - M[i][j];
                    upd(a, b, 1, 1, m, j, acc[a][b][j]);
                }
            }
            M[i][j] = x;
        }
        else{
            int i, ii, j, jj;
            scanf("%d%d%d%d", &i, &j, &ii, &jj);
            i--;ii--;
            ll ans = LLONG_MIN;
            for(int b=i;b<=ii;b++){
                for(int u=b;u<=ii;u++){
                    //printf("b %d u %d j-1 %d - jj %d qry mn %lld mx %lld tot %lld bst %lld\n", b, u, j-1, jj, q.mn, q.mx, q.tot, q.bst);
                    ans = max(ans, qry(b, u, 1, 1, m, j, jj).bst);
                }
            }
            printf("%lld\n", ans);
        }
    }
}

