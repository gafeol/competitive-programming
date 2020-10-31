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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 312345;

const int N = MAXN; typedef int num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
bool xo[N];
int st[N];
bool inv[N];

int bst[N];
int s[N][2][2];
int tot[N][2];

const int B = 0, E = 1;

void print(int u){
    if(!u) return ;
    //unlaze(u);
    printf("u %d X %d L %d R %d bst %d s B %d %d E %d %d\n", u, X[u], L[u], R[u], bst[u], s[u][B][0], s[u][B][1], s[u][E][0], s[u][E][1]);
    print(L[u]);
    print(R[u]);
}
void unlaze (int u) {
	if(!u) return;
    if(st[u]){
        int v = st[u] - 1;
        //printf("set u %d v %d\n", u, v);
        st[u] = 0; 
        tot[u][v] = sz[u];
        tot[u][1-v] = 0;
        bst[u] = sz[u];
        X[u] = v;
        s[u][B][v] = s[u][E][v] = sz[u];
        s[u][B][1-v] = s[u][E][1-v] = 0;
        if(L[u]){
            st[L[u]] = v+1;
            xo[L[u]] = 0;
        }
        if(R[u]){
            st[R[u]] = v+1;
            xo[R[u]] = 0;
        }
    }
    if(xo[u]){
        xo[u] = 0;
        X[u] ^= 1;
        for(int p=0;p<2;p++)
            swap(s[u][p][0], s[u][p][1]);
        swap(tot[u][0], tot[u][1]);
        if(L[u]){
            xo[L[u]] ^= 1;
        }
        if(R[u]){
            xo[R[u]] ^= 1;
        }
    }

    if(inv[u]){
        inv[u] = 0;
        for(int t=0;t<2;t++)
            swap(s[u][B][t], s[u][E][t]);
        swap(L[u], R[u]);
        if(L[u])
            inv[L[u]] ^= 1;
        if(R[u])
            inv[R[u]] ^= 1;
    }
    //printf("depois de unlaze %d\n", u);
    //print(u);
}
void calc (int u) { // update node given children info
    if(!u) return;
    unlaze(u);
    unlaze(L[u]);
    unlaze(R[u]);
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
    tot[u][0] = tot[L[u]][0] + (X[u] == 0) + tot[R[u]][0];
    tot[u][1] = tot[L[u]][1] + (X[u] == 1) + tot[R[u]][1];
    bst[u] = max(s[L[u]][E][X[u]] + 1 + s[R[u]][B][X[u]], 
                max(bst[L[u]], bst[R[u]]));

    if(L[u]){
        s[u][B][0] = s[L[u]][B][0];
        s[u][B][1] = s[L[u]][B][1];
    }
    else{
        s[u][B][X[u]] = 1 + s[R[u]][B][X[u]];
        s[u][B][1-X[u]] = 0;
    }
    if(R[u]){
        s[u][E][0] = s[R[u]][E][0];
        s[u][E][1] = s[R[u]][E][1];
    }
    else{
        s[u][E][X[u]] = 1 + s[L[u]][E][X[u]];
        s[u][E][1-X[u]] = 0;
    }

    if(L[u] && s[L[u]][B][X[u]] == sz[L[u]])
        s[u][B][X[u]] = sz[L[u]] + 1 + s[R[u]][B][X[u]];
    if(R[u] && s[R[u]][E][X[u]] == sz[R[u]])
        s[u][E][X[u]] = sz[R[u]] + 1 + s[L[u]][E][X[u]];
    bst[u] = max(bst[u], max(s[u][B][X[u]], s[u][E][X[u]]));
}


void split_sz(int u, int S, int &l, int &r) { // l gets first s, r gets remaining
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < S) { split_sz(R[u], S - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
	else { split_sz(L[u], S, l, r); L[u] = r; r = u; }
	calc(u);
}

int merge(int l, int r) { // els on l <= els on r
    debug("merge %d %d\n", l, r);
	unlaze(l); unlaze(r); if(!l || !r) return l + r; int u;
	if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
	else { L[r] = merge(l, L[r]); u = r; }
	calc(u); return u;
}

void init(int n=N-1) { // call before using other funcs
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
	random_shuffle(Y + 1, Y + n + 1);
}


int n, m, k;
int main (){
	scanf("%d%d", &n, &m);
    init(n);
    int r = 0;
    for(int a=1;a<=n;a++){
        char c;
        scanf(" %c", &c);
        X[a] = (c == '1');
        calc(a);
        r = merge(r, a);
    }
    int lt, rt;
    calc(r);
	for(int a=0;a<m;a++){
        int t, i, j;
        scanf("%d%d%d", &t, &i, &j);
        split_sz(r, j, r, rt);
        split_sz(r, i-1, lt, r);
        if(t == 1)
            xo[r] ^= 1;
        else if(t == 2)
            inv[r] ^= 1;
        else {
            int z = tot[r][0];    
            int zt, ot;
            debug("z %d\n", z);
            split_sz(r, z, zt, ot);
            st[zt] = 1;
            xo[zt] = 0;
            debug("bst zt %d\n", bst[zt]);
            st[ot] = 2;
            xo[ot] = 0;
            debug("bst ot %d\n", bst[ot]);
            //print(zt);
            //print(ot);
            debug("lt %d zt %d ot %d rt %d\n", lt, zt, ot, rt);
            r = merge(zt, ot);
            debug("r %d\n", r);
        }
        r = merge(merge(lt, r), rt);
        //print(r);
        //calc(r);
        unlaze(r);
        printf("%d\n", bst[r]);
	}
    return 0;
}

