#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int MAXN = 312345;
const int SQ = 550;

int n, m, k;
int s[MAXN];

#define NN v[0]
#define NP v[1]
#define PN v[2]
#define PP v[3]

struct arv {
    ll v[4];

    arv () {
        memset(v, 0, sizeof(v));
    }
} tree[MAXN*4];


arv join(arv a, arv b){
    arv c;
    for(int i=0;i<4;i++)
        c.v[i] = max(a.v[i], b.v[i]);

    c.NN = max(c.NN, max(a.NP + b.NN, a.NN + b.PN));
    c.NP = max(c.NP, max(a.NN + b.PP, a.NP + b.NP));
    c.PN = max(c.PN, max(a.PP + b.NN, a.PN + b.PN));
    c.PP = max(c.PP, max(a.PN + b.PP, a.PP + b.NP));

    return c;
}

void build(int idx, int i, int j){
    if(i == j){
        tree[idx].NN = -s[i];
        tree[idx].PP = s[i];
        tree[idx].NP = tree[idx].PN = INT_MIN;
        return;
    }

    int m =(i+j)/2;
    build(idx*2, i,m);
    build(idx*2+1,m+1,j);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

void upd(int idx, int i, int j, int l){
    if(i > l || j < l) return;
    if(i == j){
        tree[idx].NN = -s[i];
        tree[idx].PP = s[i];
        tree[idx].NP = tree[idx].PN = INT_MIN;
        return;
    }

    int m =(i+j)/2;
    upd(idx*2, i,m,l);
    upd(idx*2+1,m+1,j,l);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++)
            scanf("%d", s+a);
        build(1, 0, n-1);
        printf("%lld\n", tree[1].PP);
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            i--;j--;
            swap(s[i], s[j]);
            upd(1, 0, n-1, i);
            upd(1, 0, n-1, j);
            printf("%lld\n", tree[1].PP);
        }
    }
}
