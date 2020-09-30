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

const int MAXN = 1000006;

struct arv {
    int mn;
    int lz = 0;

    void soma(int x){
        mn += x;
        lz += x;
    }

} tree[MAXN*4];

int s[MAXN], f[MAXN];

arv join(arv a, arv b){
    arv c;
    c.lz = 0;
    c.mn = min(a.mn, b.mn);
    return c;
}

void unlaze(int idx, int i, int j){
    if(tree[idx].lz == 0) return ;
    int aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(i != j){
        tree[idx*2].soma(aux);
        tree[idx*2+1].soma(aux);
        return ;
    }
}
 

void upd(int idx, int i, int j, int l, int r, int x){
    if(i > r || j < l) return;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].soma(x);
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

int qry(int idx, int i, int j){
    unlaze(idx, i, j);
    if(i == j)
        return (tree[idx].mn < 0 ? i : -1);    
    int m = (i + j)/2;
    if(tree[idx*2+1].mn < 0)
        return qry(idx*2+1, m+1, j);
    else
        return qry(idx*2, i, m);
}

int n, m, k;
int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        upd(1, 1, MAXN-1, 1, s[a], -1);
        ///printf("upd %d - oo com -1\n", s[a]);
	}
    for(int a=0;a<m;a++){
        scanf("%d", f+a);
        upd(1, 1, MAXN-1, 1, f[a], 1);
        ///printf("upd 1 - %d com 1\n", f[a]);
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int t, i, x;
        scanf("%d%d%d", &t, &i, &x); 
        i--;
        if(t == 1){
            upd(1, 1, MAXN-1, 1, s[i], 1);
            //printf("upd %d - oo com 1\n", s[i]);
            s[i] = x;
            upd(1, 1, MAXN-1, 1, s[i], -1);
            //printf("upd %d - oo com -1\n", s[i]);
        }
        else{
            upd(1, 1, MAXN-1, 1, f[i], -1);
            f[i] = x;
            upd(1, 1, MAXN-1, 1, f[i], 1);
        }
        //printf("tree[1] %d %d %d\n", tree[1].r, tree[1].tot, tree[1].lz);
        printf("%d\n", qry(1, 1, MAXN-1));
    }
}

