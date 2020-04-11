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

const int MAXN = 312345;

struct arv{
    int lz, mx;
} tree[MAXN*4];

int n, m, k;
int s[MAXN];
int b[MAXN];

void unlaze(int idx, int i, int j){
    int aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(i != j){
        tree[idx*2].mx += aux;
        tree[idx*2].lz += aux;
        tree[idx*2+1].mx += aux;
        tree[idx*2+1].lz += aux;
    }
}

void upd(int idx, int i, int j, int l, int r, int val){
    if(i > r || j < l) return ;
    if(tree[idx].lz != 0)
        unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].mx += val;
        tree[idx].lz += val;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, val);
    upd(idx*2+1, m+1, j, l, r, val);
    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
}

int pos[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        pos[s[a]] = a;
    }
    for(int a=0;a<n;a++){
        scanf("%d", b+a);
        b[a]--;
    }
    int ib = 0;
    for(int res = n;res>=1;res--){
        upd(1, 0, n-1, 0, pos[res], 1);
        while(ib < n && tree[1].mx > 0){
            printf("%d ", res);
            upd(1, 0, n-1, 0, b[ib], -1); 
            ib++;
        }
    }
    puts("");
}

