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

int n, m, k;
char s[MAXN];
ll pot[MAXN], inv;

ll expo(ll base, ll e){
    if(e == 0)
        return 1ll;
    ll ans = expo(base, e/2ll);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

struct arv{
    int l, r, sz;
    ll h; 
} tree[4*MAXN], z;

void rmvL(arv &a){
    a.l = 0;
    if(a.sz == 1)
        a.r = 0;
    a.h = mod(inv * mod(modn + a.h - 1));
    a.sz--;
}

void rmvR(arv &a){
    a.r = 0;
    if(a.sz == 1)
        a.l = 0;
    a.h = mod(modn + mod(a.h - pot[a.sz-1]));
    a.sz--;
}

void print(arv a){
    printf("l %d r %d sz %d h %lld", a.l, a.r, a.sz, a.h);
}

arv join(arv a, arv b){
    if(a.r == 1 && b.l == 1){
        rmvR(a);
        rmvL(b);
        assert(a.r == 0 && b.l == 0);
    }
    if(a.sz == 0)
        return b;
    if(b.sz == 0)
        return a;
//    printf("join ");
//    print(a);
//    printf(" and ");
//    print(b);
    arv c;
    c.sz = a.sz + b.sz;
    c.l = a.l;
    c.r = b.r;
    c.h = mod(a.h + mod(pot[a.sz]*b.h));
//    printf("\nresults in ");
//    print(c);
//    printf("\n");
    return c;
}

void build(int idx, int i, int j){
    if(i == j){
        tree[idx].sz = 1;
        tree[idx].h = tree[idx].l = tree[idx].r = (s[i]-'0');
        return ;
    }
    int m = ((i+j)>>1);
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
    //printf("i %d j %d sz %d l %d r %d h %lld\n", i, j, tree[idx].sz, tree[idx].l, tree[idx].r, tree[idx].h);
}


arv qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) 
        return z;
    if(i >= l && j <= r){
        return tree[idx];
    }
    int m = ((i+j)>>1);
    return join(qry(idx*2, i, m, l, r),
                qry(idx*2+1, m+1, j, l, r));
}


int main (){
    z.l = z.r = z.sz = z.h = 0;
    inv = expo(2, modn-2);
    pot[0] = 1;
    for(int a=1;a<MAXN;a++)
        pot[a] = mod(pot[a-1]*2ll);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf(" %c", s+a);
	}
    build(1, 0, n-1);
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d%d", &i, &j, &k); 
        i--;j--;
        arv A = qry(1, 0, n-1, i, i+k-1);
        arv B = qry(1, 0, n-1, j, j+k-1);
        if(A.h == B.h && A.sz == B.sz)
            puts("Yes");
        else
            puts("No");
    }
}

