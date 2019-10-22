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

const int MAXN = 412345;

int n, m, k;
int s[MAXN];

int p[MAXN], sz[MAXN], ans[MAXN];

int ind[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void join(int i, int j){
    if(i == -1 || j == -1) return;
    i = raiz(i);
    j = raiz(j);
    if(i == j) return ;
    if(sz[i] > sz[j])
        swap(i, j);
    p[i] = j;
    sz[j]+=sz[i];
}

int main (){
	scanf("%d%d", &n, &m);
    if(n == 1){
        puts("0");
        return 0;
    }
	for(int a=0;a<m;a++){
        scanf("%d", s+a);
        s[a]--;
	}

    memset(ind, -1, sizeof(ind));
    for(int a=0;a<n;a++)
        ind[a] = a;

    // find left bounds
    for(int a=0;a<=m+n+3;a++){
        p[a] = a;
        sz[a] = 1;
    }
    for(int a=0;a<m;a++){
        int xb = s[a] + a + 1;
        //printf("xb %d ind %d\n", xb, ind[xb]);
        if(ind[xb] == -1) continue;
        join(ind[xb], ind[xb+1]);
        ind[xb+1] = raiz(ind[xb]);
        ind[xb] = -1;
    }
    ll ans = 0;
    for(int a=0;a<=m+n+3;a++){
        //printf("A %d\n", a);
        if(ind[a] != -1){
            int l = max(0, a-m-1);
            //printf("l %d sz %d\n", l, sz[ind[a]]);
            ans -= ((ll)sz[raiz(ind[a])])*(l - 1);
            //printf("ans %lld\n", ans);
        }
    }
    
    for(int a=0;a<m;a++){
        s[a] = n-1 - s[a];
    }
    memset(ind, -1, sizeof(ind));
    for(int a=0;a<n;a++)
        ind[a] = a;

    // find right bounds
    for(int a=0;a<=m+n+3;a++){
        p[a] = a;
        sz[a] = 1;
    }
    for(int a=0;a<m;a++){
        int xb = s[a] + a + 1;
        //printf("xb %d ind %d\n", xb, ind[xb]);
        if(ind[xb] == -1) continue;
        join(ind[xb], ind[xb+1]);
        ind[xb+1] = raiz(ind[xb]);
        ind[xb] = -1;
    }
    for(int a=0;a<=m+n+3;a++){
        //printf("A %d\n", a);
        if(ind[a] != -1){
            int r = n-1 - max(0, a-m-1);
            //printf("r %d sz %d\n", r, sz[ind[a]]);
            ans += ((ll)sz[raiz(ind[a])])*r;
        }
    }
    printf("%lld\n", ans);
}
