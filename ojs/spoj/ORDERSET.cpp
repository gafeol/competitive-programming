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

const int N = MAXN; typedef ll num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
num mx[N], mn[N], mxd[N], mnd[N];
//               123456789
const num INF = 3000000000LL;
void calc (int u) { // update node given children info
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
    mnd[u] = INF;
    mxd[u] = -INF;
    mn[u] = mx[u] = X[u];
    if(L[u]){
        mn[u] = min(mn[u], mn[L[u]]);
        mnd[u] = min(mnd[u], X[u] - mx[L[u]]);
        if(sz[L[u]] > 1)
            mnd[u] = min(mnd[u], mnd[L[u]]);
    }
    if(R[u]){
        mx[u] = max(mx[u], mx[R[u]]);
        mnd[u] = min(mnd[u], mn[R[u]] - X[u]);
        if(sz[R[u]] > 1)
            mnd[u] = max(mnd[u], mnd[R[u]]);
    }
    if(sz[u] > 1)
        mxd[u] = mx[u] - mn[u];
}

void split_val(int u, num x, int &l, int &r) { // l gets <= x, r gets > x
	if(!u) return (void) (l = r = 0);
	if(X[u] <= x) { split_val(R[u], x, l, r); R[u] = l; l = u; }
	else { split_val(L[u], x, l, r); L[u] = r; r = u; }
	calc(u);
}
void split_sz(int u, int s, int &l, int &r) { // l gets first s, r gets remaining
	if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < s) { split_sz(R[u], s - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
	else { split_sz(L[u], s, l, r); L[u] = r; r = u; }
	calc(u);
}
int merge(int l, int r) { // els on l <= els on r
	if(!l || !r) return l + r; int u;
	if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
	else { L[r] = merge(l, L[r]); u = r; }
	calc(u); return u;
}
void init(int n=N-1) { // call before using other funcs
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; mx[i] = mxd[i] = -INF; mn[i] = mnd[i] = INF;}
	random_shuffle(Y + 1, Y + n + 1);
}

int n, m;
int root;
int s[MAXN];

void print(int u){
    if(!u) return ;
    printf("u %d X %lld\n", u, X[u]);
    printf("sz %d mn %lld mx %lld mnd %lld mxd %lld\n", sz[u], mn[u], mx[u], mnd[u], mxd[u]);
    printf("L %d R %d\n", L[u], R[u]);
    print(L[u]);
    print(R[u]);
}

int main (){
	scanf("%d", &n);
    init();
    root = 0;
	for(int a=0;a<n;a++){
        ll x;
        char c;
        scanf(" %c", &c);
        scanf("%lld", &x);
        if(c == 'D'){
            int i, j, k;   
            split_val(root, x-1, i, j);
            split_val(j,      x, j, k);
            root = merge(i, k);
            //print(root);
        }
        else if(c == 'I'){
            int i, j, k;   
            split_val(root, x-1, i, j);
            if(j && mn[j] == x){
                root = merge(i, j);
            }
            else{
                X[en] = x;
                mx[en] = mn[en] = x;
                root = merge(merge(i,en++), j);
            }
            //print(root);
        }
        else if(c == 'K'){
            int i, j;
            split_sz(root, x, i, j);
            if(sz[i] < x)
                puts("invalid");
            else
                printf("%lld\n", mx[i]);
            root = merge(i, j);
        }
        else{
            int i, j;
            split_val(root, x-1, i, j);
            printf("%d\n", sz[i]);
            root = merge(i, j);
        }
	}
}

