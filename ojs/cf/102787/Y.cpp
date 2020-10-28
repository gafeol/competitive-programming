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

const int MAXN = 312345;

const int N = MAXN; typedef int num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
bool xo[N];
int bst[N];
int s[N][2][2];
int tot[N][2];


const int B = 0, E = 1;

void calc (int u) { // update node given children info
    if(!u) return;
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
    tot[u][0] = tot[L[u]][0] + (X[u] == 0) + tot[R[u]][0];
    tot[u][1] = tot[L[u]][1] + (X[u] == 1) + tot[R[u]][1];
    bst[u] = max(s[L[u]][E][X[u]] + 1 + s[R[u]][B][X[u]], 
                max(bst[L[u]], bst[R[u]]));
    s[u][B][0] = s[L[u]][B][0];
    s[u][B][1] = s[L[u]][B][1];
    s[u][E][0] = s[R[u]][E][0];
    s[u][E][1] = s[R[u]][E][1];

    if(s[L[u]][B][X[u]] == sz[L[u]])
        s[u][B][X[u]] = sz[L[u]] + 1 + s[R[u]][B][X[u]];
    if(s[R[u]][B][X[u]] == sz[R[u]])
        s[u][E][X[u]] = sz[R[u]] + 1 + s[L[u]][E][X[u]];

    bst[u] = max(bst[u], max(s[u][B][X[u]], s[u][E][X[u]]));
}

void unlaze (int u) {
	if(!u) return;
    if(xo[u]){
        xo[u] = 0;
        if(L[u]){
            int l = L[u];
            xo[l] ^= 1;
            X[l] ^= 1;
            for(int p=0;p<2;p++){
                swap(s[l][p][0], s[l][p][1]);
            }
            swap(tot[l][0], tot[l][1]);
        }
        if(R[u]){
            int r = R[u];
            xo[r] ^= 1;
            X[r] ^= 1;
            for(int p=0;p<2;p++){
                swap(s[r][p][0], s[r][p][1]);
            }
            swap(tot[r][0], tot[r][1]);
        }
    }
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
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
	random_shuffle(Y + 1, Y + n + 1);
}

void print(int u){
    if(!u) return ;
    //unlaze(u);
    printf("u %d X %d L %d R %d bst %d s B %d %d E %d %d\n", u, X[u], L[u], R[u], bst[u], s[u][B][0], s[u][B][1], s[u][E][0], s[u][E][1]);
    print(L[u]);
    print(R[u]);
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
        xo[r] ^= 1;
        X[r] ^= 1;
        for(int p=0;p<2;p++){
            swap(s[r][p][0], s[r][p][1]);
        }
        swap(tot[r][0], tot[r][1]);
        //puts("merge lt");
        //print(lt);
        //puts("merge r");
        //print(r);
        //puts("merge rt");
        //print(rt);
        r = merge(merge(lt, r), rt);
        printf("%d\n", bst[r]);
        //print(r);
	}
    return 0;
}

