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

const int MAXN = 212345;

const int N = MAXN; typedef int num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
int ans[N];
int lzans[N], lzx[N];
void calc (int u) { // update node given children info
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
}
void unlaze (int u) {
	if(!u) return;
	// code here, no recursion
    if(lzans[u]){
        ans[u] += lzans[u]; 
        if(L[u])
            lzans[L[u]] += lzans[u];
        if(R[u])
            lzans[R[u]] += lzans[u];
        lzans[u] = 0;
    }
    if(lzx[u]){
        X[u] -= lzx[u];
        if(L[u])
            lzx[L[u]] += lzx[u];
        if(R[u])
            lzx[R[u]] += lzx[u];
        lzx[u] = 0;
    }
}
void unlazeAll(int u){
    if(!u) return ;
    unlaze(u);
    unlazeAll(L[u]);
    unlazeAll(R[u]);
}
void split_val(int u, num x, int &l, int &r) { // l gets <= x, r gets > x
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(X[u] <= x) { split_val(R[u], x, l, r); R[u] = l; l = u; }
	else { split_val(L[u], x, l, r); L[u] = r; r = u; }
	calc(u);
}
void split_sz(int u, int s, int &l, int &r) { // l gets first s, r gets remaining
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < s) { split_sz(R[u], s - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
	else { split_sz(L[u], s, l, r); L[u] = r; r = u; }
	calc(u);
}
int merge(int l, int r) { // els on l <= els on r
	unlaze(l); unlaze(r); if(!l || !r) return l + r; int u;
	if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
	else { L[r] = merge(l, L[r]); u = r; }
	calc(u); return u;
}
void init(int n=N-1) { // call before using other funcs
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; ans[i] = 0; ans[i] = 0; lzans[i] = lzx[i] = 0;}
	random_shuffle(Y + 1, Y + n + 1);
}

inline int getMin(int u){
    if(!u) return INT_MAX;
    unlaze(u);
    while(L[u] != 0){
        u = L[u];
        unlaze(u);
    }
    return X[u];
}

inline int getMax(int u){
    if(!u) return INT_MIN;
    unlaze(u);
    while(R[u] != 0){
        u = R[u];
        unlaze(u);
    }
    return X[u];
}

int n, m, k;
pii s[MAXN];

int root = 0;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int c, q;
        scanf("%d %d", &c, &q);
        s[a] = {-q, c};
	}
    sort(s, s+n);
    scanf("%d", &k);
    init(k);
    for(int a=0;a<k;a++){
        int cus;
        scanf("%d", &cus);
        X[en] = cus;
        int men, big;
        split_val(root, cus, men, big);
        root = merge(merge(men, en++), big);
    }
    for(int i=0;i<n;i++){
        int c = s[i].snd;
        int sm, gt;
        split_val(root, c-1, sm, gt);
        if(!gt){
            assert(root == sm);
            continue;
        }
        lzans[gt]++;
        lzx[gt] += c;
        if(!sm){
            assert(root == gt);
            continue;
        }

        int mxSM = getMax(sm), mnGT = getMin(gt);
        while(gt && sm && sz[gt] && sz[sm] && mnGT < mxSM){
            int men;
            split_val(gt, mnGT, men, gt);
            int l, r;
            split_val(sm, mnGT, l, r);
            sm = merge(merge(l, men), r);
            mnGT = getMin(gt);
        }
        root = merge(sm, gt);
    }
    unlazeAll(root);
    for(int a=1;a<=k;a++)
        printf("%d ", ans[a]);
    puts("");
}

