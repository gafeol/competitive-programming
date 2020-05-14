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
int lz[N];
void calc (int u) { // update node given children info
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
}
void unlaze (int u) {
	if(!u || !lz[u]) return;
	// code here, no recursion
    lz[u] = 0;
    swap(L[u], R[u]);
    lz[L[u]] ^= 1;
    lz[R[u]] ^= 1;
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
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; lz[i] = 0;}
	random_shuffle(Y + 1, Y + n + 1);
}

int n, m, k;
int s[MAXN];

int root = 0;

int main (){
    init();
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        X[en] = a+1;
        root = merge(root, en++);
	}
    for(int a=0;a<m;a++){
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);

        int ta, tb, tc, rest;
        split_sz(root, A, ta, rest);
        split_sz(rest, B, tb, rest);
        rest = merge(ta, rest);
        split_sz(rest, C, tc, rest);
        lz[tb] ^= 1; 
        root = merge(tc, merge(tb, rest));
    }
    while(sz[root]){
        int u;
        split_sz(root, 1, u, root);
        printf("%d ", X[u]);
    }
    puts("");
}
