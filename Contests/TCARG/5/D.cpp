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

const int MAXN = 8123;
const int MAXC = 112;
const int MAXM = 112345;

const int N = MAXN*MAXC; typedef int num;
int en = 1, p[N], sz[N], pp[N]; bool lzswp[N];
int C[N][2]; // {left, right} children
inline void calc(int u) { // update node given children info
	sz[u] = sz[C[u][0]] + 1 + sz[C[u][1]];
	// code here, no recursion
}
inline void unlaze(int u) {
	if(!u) return;
	if(lzswp[u]) {
		swap(C[u][0], C[u][1]);
		if(C[u][0]) lzswp[C[u][0]] ^= 1;
		if(C[u][1]) lzswp[C[u][1]] ^= 1;
		lzswp[u] = 0;
	}
}
int rotate(int u, int dir) { // pulls C[u][dir] up to u and returns it
	int v = C[u][dir];
	swap(pp[v], pp[u]);
	C[u][dir] = C[v][!dir];
	if(C[u][dir]) p[C[u][dir]] = u;
	C[v][!dir] = u; p[v] = p[u];
	if(p[v]) C[p[v]][C[p[v]][1] == u] = v;
	p[u] = v; calc(u); calc(v);
	return v;
}
void unlz_back(int u) { if(!u) return; unlz_back(p[u]); unlaze(u); }
void splay(int u) { // pulls node u to root
	unlz_back(u);
	while(p[u]) {
		int v = p[u], w = p[p[u]];
		int du = (C[v][1] == u);
		if(!w) { rotate(v, du); assert(!p[u]); }
		else {
			int dv = (C[w][1] == v);
			if(du == dv) { rotate(w, dv); assert(C[v][du] == u); rotate(v, du); }
			else { rotate(v, du); assert(C[w][dv] == u); rotate(w, dv); }
		}
	}
}
int find_sz(int u, int s) { // returns s-th node (0-index)
	unlaze(u);
	while(sz[C[u][0]] != s) {
		if(sz[C[u][0]] < s) { s -= sz[C[u][0]] + 1; u = C[u][1]; }
		else u = C[u][0];
		unlaze(u);
	}
	splay(u); return u;
}
int new_node() {
	int i = en++; assert(i < N);
	pp[i] = C[i][0] = C[i][1] = p[i] = 0;
	lzswp[i] = 0; sz[i] = 1; return i;
}
int access(int u) {
	if(!u) return u;
	splay(u);
	if(int v = C[u][1]) { p[v] = 0; pp[v] = u; C[u][1] = 0; }
	calc(u);
	while(pp[u]) {
		int w = pp[u]; splay(w);
		if(int v = C[w][1]) { p[v] = 0; pp[v] = w; }
		C[w][1] = u; p[u] = w; pp[u] = 0; calc(w); splay(u);
	}
	return u;
}
int find_root(int u) { // root o u's tree
	access(u);
	while(C[u][0]) { unlaze(u = C[u][0]); }
	access(u); return u;
}
int get_parent(int u) { // u's parent, rootify might change it
	access(u);
	if(!C[u][0]) return pp[u];
	unlaze(u = C[u][0]);
	while(C[u][1]) unlaze(u = C[u][1]);
	access(u); return u;
}
bool link(int u, int v) { // adds edge from u to v, v must be root
	if(find_root(u) == find_root(v)) return false;
	access(u); access(v);
	assert(C[v][0] == 0 && pp[v] == 0 && sz[v] == 1); // v must be root
	C[u][1] = v; p[v] = u; calc(u);
    return true;
}
// XXX cut + rootify require get_parent, cut unlinks u from parent, rootify makes u root
void cut(int u) { access(u); assert(C[u][0]); p[C[u][0]] = 0; C[u][0] = 0; calc(u); }
void rootify(int u) { access(u); lzswp[u] = 1; access(u); } 
void init() { en = 1; } // XXX initialize


int ind[MAXC][MAXN];
int deg[MAXC][MAXN];
unordered_map<int, map<int, int>> has;

int main (){
    int n, m, c, t;
    while(scanf("%d%d%d%d", &n, &m, &c, &t) != EOF && n+m+c+t > 0){
        has.clear();
        init();
        for(int a=1;a<=c;a++){
            for(int b=1;b<=n;b++){
                ind[a][b] = new_node();
                deg[a][b] = 0;
            }
        }
        for(int a=0;a<m;a++){
            int u, v, k;
            scanf("%d%d%d",&u, &v, &k);
            if(u > v)
                swap(u, v);
            has[u][v] = k;
            deg[k][u]++;
            deg[k][v]++;
            rootify(ind[k][v]);
            link(ind[k][u], ind[k][v]);
        }
        for(int a=0;a<t;a++){
            int u, v, k;
            scanf("%d%d%d",&u, &v, &k);
            if(u > v)
                swap(u, v);
            if(has[u].find(v) == has[u].end()){
                puts("No such cable.");
            }
            else if(has[u][v] == k){
                puts("Already owned."); 
            }
            else if(deg[k][u] >= 2 || deg[k][v] >= 2){
                puts("Forbidden:  monopoly.");
            }
            else if(find_root(ind[k][u]) == find_root(ind[k][v])){
                puts("Forbidden:  redundant.");
            }
            else {
                rootify(ind[k][v]);
                assert(link(ind[k][u], ind[k][v]));
                deg[k][u]++;
                deg[k][v]++;
                int o = has[u][v];
                if(get_parent(ind[o][v]) == ind[o][u])
                    cut(ind[o][v]);
                else{
                    assert(get_parent(ind[o][u]) == ind[o][v]);
                    cut(ind[o][u]);
                }
                deg[o][u]--;
                deg[o][v]--;
                has[u][v] = k;
                puts("Sold.");
            }
        }
        puts("");
    }
}
