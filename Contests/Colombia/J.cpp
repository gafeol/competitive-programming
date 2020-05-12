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

const int MAXN = 102345;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

struct arv{
    ll mn, lz, cnt;
    ll sum;
} tree[MAXN*4];

void build(int idx, int i, int j){
    if(i == j){
        tree[idx].mn = s[i];
        tree[idx].sum = s[i];
        tree[idx].cnt = 0;
        tree[idx].lz = 0;
        return ;
    }
    int m = ((i + j) >> 1);
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
    tree[idx].cnt = tree[idx*2].cnt + tree[idx*2+1].cnt;
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}

void unlaze(int idx, int i, int j){
    ll aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(i != j){
        int m = ((i+j)>>1);
        if(tree[idx*2].mn != INF){
            tree[idx*2].mn -= aux;
            tree[idx*2].lz += aux;
            tree[idx*2].sum -= aux*(m-i+1 - tree[idx*2].cnt);
        }
        if(tree[idx*2+1].mn != INF){
            tree[idx*2+1].mn -= aux;
            tree[idx*2+1].lz += aux;
            tree[idx*2+1].sum -= aux*(j-m - tree[idx*2+1].cnt);
        }
    }
}

void upd(int idx, int i, int j, int l, int r, ll x){
    if(i > r || j < l) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r && tree[idx].mn > x){
        if(tree[idx].mn < INF){
            tree[idx].mn -= x;
            tree[idx].lz += x;
            tree[idx].sum -= ((ll)j-i+1ll - tree[idx].cnt)*x;
        }
        return ;
    }
    if(i == j){
        tree[idx].cnt = 1;
        tree[idx].mn = INF;
        tree[idx].lz = 0;
        tree[idx].sum = 0;
        //printf("upd %d %d %d: %lld %lld %lld\n", idx, i, j, tree[idx].mn, tree[idx].sum, tree[idx].cnt);
        return ;
    }

    int m = ((i + j) >> 1);
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
    //printf("filho %d sum %lld fi %d sum %lld\n", idx*2, tree[idx*2].sum, idx*2+1, tree[idx*2+1].sum);
    tree[idx].cnt = tree[idx*2].cnt + tree[idx*2+1].cnt;
    //printf("upd %d %d %d: %lld %lld %lld\n", idx, i, j, tree[idx].mn, tree[idx].sum, tree[idx].cnt);
}

ll qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return 0;                
    unlaze(idx, i, j);
    if(i >= l && j <= r)
        return tree[idx].sum;
    int m = ((i + j)>>1);
    return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=0;a<n;a++)
        scanf("%d", s+a);

    build(1, 0, n-1);
	for(int a=0;a<m;a++){
        int t, i, j, x;
        scanf("%d %d %d", &t, &i, &j);
        i--;
        j--;
        if(t == 1){
            if(i <= j)
                printf("%lld\n", qry(1, 0, n-1, i, j));
            else
                printf("%lld\n", qry(1, 0, n-1, 0, j) + qry(1, 0, n-1, i, n-1));
        }
        else{
            scanf("%d", &x);
            if(i <= j){
                upd(1, 0, n-1, i, j, x); 
            }
            else{
                upd(1, 0, n-1, i, n-1, x);
                upd(1, 0, n-1, 0, j, x);
            }
        }
	}
}

