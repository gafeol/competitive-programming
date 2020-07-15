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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

struct arv{
    int mx, lz;
} tree[MAXN*4];

void build(int idx, int i, int j){
    if(i == j){
        tree[idx].mx = n;
        tree[idx].lz = 0;
        return ;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
    tree[idx].lz = 0;
}

void unlaze(int idx, int i, int j){
    if(tree[idx].lz && i != j){
        int aux = tree[idx].lz;
        tree[idx*2].mx += aux;
        tree[idx*2].lz += aux;
        tree[idx*2+1].mx += aux;
        tree[idx*2+1].lz += aux;
    }
    tree[idx].lz = 0;
}

void upd(int idx, int i, int j, int l, int r, int x){
    if(i > r || j < l) return;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].mx += x;
        tree[idx].lz += x;
        return ;
    }

    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
}

int qrymx(int idx, int i, int j){
    unlaze(idx, i, j);
    if(i == j)
        return i;
    int m = (i + j)/2;
    if(tree[idx].mx == tree[idx*2].mx)
        return qrymx(idx*2, i, m);
    else
        return qrymx(idx*2+1, m+1, j);
}
int qrymx2(int idx, int i, int j){
    unlaze(idx, i, j);
    if(i == j)
        return i;
    int m = (i + j)/2;
    if(tree[idx].mx == tree[idx*2+1].mx)
        return qrymx2(idx*2+1, m+1, j);
    else
        return qrymx2(idx*2, i, m);
}

int main (){
	scanf("%d%d", &n, &m);
    build(1, 1, m);
    vector<pii> ev;
	for(int a=0;a<n;a++){
        scanf("%d", &k);
        int mxr = 0;
        while(mxr < m){
            while(k--){
                int l, r;
                scanf("%d%d", &l, &r);
                mxr = max(mxr, r);
                ev.pb({l, r});
            }
        }
	}
    ll ans = 0;
    while(tree[1].mx > 0){
        //printf("mx %lld\n", tree[1].mx);
        ans += tree[1].mx*tree[1].mx;
        int i = qrymx(1, 1, m);
        int ii = qrymx2(1, 1, m);
        //printf("i %d ii %d\n", i, ii);
        if(m - ii < i-1)
            i = ii;
        //printf("i %d\n", i);
        vector<pii> aux;
        for(int a=0;a<ev.size();a++){
            if(ev[a].snd < i || ev[a].fst > i){
                aux.pb(ev[a]); 
            }
            else{
                //printf("retira %d  %d\n", ev[a].fst, ev[a].snd);
                upd(1, 1, m, ev[a].fst, ev[a].snd, -1);
            }
        }
        ev = aux;
    }
    printf("%lld\n", ans);
}

