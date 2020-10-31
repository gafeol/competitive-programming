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
const ull pri = 1000000007;
const ull pri2 = 1000000009;
#define IOS() ios::sync_with_stdio(0),cin.tie(0)


const int MAXN = 312345;

int n, m, k;
char s[MAXN];

const int N = 2*MAXN; typedef int num;
ull pot[N], pot2[N];
int en = 1, Y[N], sz[N], L[N], R[N];
ull he[N], hd[N];
ull he2[N], hd2[N];
void calc (int u) { // update node given children info
    if(!u) return ;
    num szL = sz[L[u]];
    num szR = sz[R[u]];
    //printf("calc u %d %d sz %d R  %d sz %d\n", u, L[u], szL, R[u], szR);
	sz[u] = szL + 1 + szR;
    he[u] = he[L[u]]*pot[szR + 1] + (ull)(s[u-1] - 'a') * pot[szR] + he[R[u]];
    hd[u] = hd[R[u]]*pot[szL + 1] + (ull)(s[u-1] - 'a') * pot[szL] + hd[L[u]];
    he2[u] = he2[L[u]]*pot2[szR + 1] + (ull)(s[u-1] - 'a') * pot2[szR] + he2[R[u]];
    hd2[u] = hd2[R[u]]*pot2[szL + 1] + (ull)(s[u-1] - 'a') * pot2[szL] + hd2[L[u]];
	// code here, no recursion
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
    sz[0] = 0;
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
	random_shuffle(Y + 1, Y + n + 1);
    pot[0] = 1;
    pot2[0] = 1;
    for(int a=1;a<=n;a++){
        pot[a] = pot[a-1]*pri;
        pot2[a] = pot2[a-1]*pri2;
    }
}


int main (){
	scanf("%d%d", &n, &m);
    init();
    scanf(" %s", s);
    for(int a=1;a<=n;a++)
        calc(a);
    int r = 1;
    for(int a=2;a<=n;a++){
        r = merge(r, a);
    }
    //printf("inir %d\n", r);
	for(int a=0;a<m;a++){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int L, R;
            scanf("%d%d", &L, &R);
            int lt, rt;
            split_sz(r, L-1, lt, r);
            split_sz(r, R - L + 1, r, rt);
            r = merge(lt, rt);
        }
        else if(t == 2){
            char c;
            int p;
            scanf(" %c %d", &c, &p);
            s[n++] = c;
            calc(n);
            int o;
            split_sz(r, p-1, o, r);
            r = merge(merge(o, n), r);
        }
        else{
            int lt, rt;
            int L, R;
            scanf("%d%d", &L, &R);
            split_sz(r, L-1, lt, r);
            //printf("split l sz %d    L %d sz %d R %d %d\n", L-1, lt, sz[lt], r, sz[r]);
            split_sz(r, R - L + 1, r, rt);
            //printf("split r sz %d    R %d sz %d R %d %d\n", R-L+1,  r, sz[r], rt, sz[rt]);
            calc(r);
            //printf("r %d %llu %llu %llu %llu\n", r, he[r], hd[r], he2[r], hd2[r]);
            if(he[r] == hd[r] && he2[r] ==  hd2[r])
                puts("yes");
            else
                puts("no");
            r = merge(lt, merge(r, rt));
        }
	}
    return 0;
}

