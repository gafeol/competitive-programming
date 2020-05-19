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

const int N = MAXN; typedef char num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
int lz[N];
void calc (int u) { // update node given children info
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
}
void unlaze (int u) {
	if(!u) return;
	// code here, no recursion
    if(lz[u]){
        lz[u] = 0;
        swap(L[u], R[u]);
        lz[L[u]] ^= 1;
        lz[R[u]] ^= 1;
    }
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
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0;  lz[i] = 0;}
	random_shuffle(Y + 1, Y + n + 1);
}

int n, m, k;
char s[MAXN];
int root;

inline char qry(int pos){
    int u = root;
    while(u != 0){
      //  printf("u %d\n", u);
        unlaze(u);
        if(sz[L[u]] + 1 < pos){
            pos -= sz[L[u]] + 1;
            u = R[u];
        }
        else if(sz[L[u]] + 1 == pos)
            return X[u];
        else
            u = L[u];
    }
    //puts("nao retornou nada");
}

int id[MAXN];

int main (){
    init();
    int l, r;
	scanf("%d%d%d", &n, &l, &r);
	for(int a=1;a<=n;a++){
        scanf(" %c", s+a);
        X[a] = s[a];
        id[a] = a;
        if(a >= l && a <= r)
            root = merge(root, a);
	}
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        char t;
        scanf(" %c", &t);
        if(t == 'Q'){
            char p;
            scanf(" %c", &p);     
            printf("%c", qry((p == 'L' ? 1 : sz[root])));
        }
        else if(t == 'R'){
            lz[root] ^= 1;
        }
        else{
            int el;
            char p, d;
            scanf(" %c %c", &p, &d);
            if(p == 'L'){
                if(d == 'L'){
                    root = merge(id[l-1], root);
                }
                else{
                    split_sz(root, 1, el, root);
                    id[l] = el;
                }
            }
            else{
                if(d == 'L'){
                    split_sz(root, sz[root]-1, root, el);
                    id[r] = el;
                }
                else
                    root = merge(root, id[r+1]);
            }
            int &pos = (p == 'L' ? l : r);
            int del = (d == 'L' ? -1 : 1);
            pos += del;
        }
    }
    puts("");
}

