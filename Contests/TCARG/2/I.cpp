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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];
int ss[MAXN];

struct arv {
    int i, lzi, lzk;
    arv () : i(0), lzi(0), lzk(0) {}
} tree[MAXN*4];


void unlaze(int idx, int i, int j){
    if(i != j && tree[idx].lzk > 0){
        //printf("unlaze de idx %d i %d j %d I %d k %d\n", idx, i, j, tree[idx].lzi, tree[idx].lzk);
        int m = (i +j)/2;
        int lk = min(m - i + 1, tree[idx].lzk);
        int rk = max(0, min(tree[idx].lzk - (m - i + 1), j - m));
        if(lk){
            //printf("unlaze pra L i %d k %d\n", tree[idx].lzi, lk);
            tree[idx*2].i = tree[idx].lzi;
            tree[idx*2].lzi = tree[idx].lzi;
            tree[idx*2].lzk = lk;
        }
        if(rk){
            //printf("unlaze pra R i %d k %d\n", tree[idx].lzi+(m-i+1), rk);
            tree[idx*2+1].i = tree[idx].lzi+(m-i+1);
            tree[idx*2+1].lzi = tree[idx].lzi+(m-i+1);
            tree[idx*2+1].lzk = rk;
        }
    }
    tree[idx].lzk = 0;
}

void upd(int idx, int i, int j, int l, int r, int I, int K){    
    if(i > r || j < l || K <= 0) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        //printf("upds i %d j %d com I %d K %d\n", i, j, I, K);
        tree[idx].i = I;
        tree[idx].lzi = I;
        tree[idx].lzk = K;
        return ;
    }
    int m = (i + j)/2;
    if(r <= m){
        upd(idx*2, i, m, l, r, I, K);
    }
    else if(l > m){
        upd(idx*2+1, m+1, j, l, r, I, K);
    }
    else{
        int lk = min(m - l + 1, m-i+1); 
        upd(idx*2, i, m, l, r, I, lk);
        int rk = K - lk;
        upd(idx*2+1, m+1, j, l, r, I+lk, rk);
    }

}

int qry(int idx, int i, int j, int l){
    if(i > l || j < l) return INT_MIN;
    unlaze(idx, i, j);
    if(i == j)
        return tree[idx].i;
    int m = (i + j)/2;
    return max(qry(idx*2, i, m, l), qry(idx*2+1, m+1, j, l));
}

void build(int idx, int i, int j){
    tree[idx].lzk = tree[idx].lzi = 0;
    if(i == j){
        tree[idx].i = -i-1;
        tree[idx].lzk = tree[idx].lzi = 0;
        return ;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1,m+1, j);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
	for(int a=0;a<n;a++){
        scanf("%d", ss+a);
	}
    build(1, 0, n-1);
    for(int a=0;a<m;a++){
        int t;
        scanf("%d", &t);
        if(t == 2){
            int x;
            scanf("%d", &x);
            int ind = qry(1, 0, n-1, x-1);
            //printf("ind %d\n", ind);
            if(ind < 0){
                //printf("retorna ss[%d]\n", -ind-1);
                printf("%d\n", ss[-ind-1]);
            }
            else{
                //printf("retorna s[%d]\n", ind);
                printf("%d\n", s[ind]);
            }
        }
        else{
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            x--;
            y--;
            //printf("upd %d %d %d %d\n", y, y+k-1, x, k);
            upd(1, 0, n-1, y, y+k-1, x, k);
        }
    }
}

