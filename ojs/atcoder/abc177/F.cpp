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
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, k;

struct arv{
    ll mn;
    ll lz, lzr;
} tree[MAXN*4];


void build(int idx, int i, int j){
    tree[idx].mn = 0;
    tree[idx].lz = 0;
    tree[idx].lzr = 0;
    if(i == j)
        return ;
    int m = (i + j)/2;
    build(idx*2,i,m);
    build(idx*2+1,m+1, j);
}

void unlaze(int idx, int i, int j){
    if(i == j){
        tree[idx].lz = 0;
        tree[idx].lzr = 0;
        return ;
    }
    if(tree[idx].lz != 0 || tree[idx].lzr != 0){
        ll l = tree[idx].lz;
        l = min(INF, l);
        ll r = tree[idx].lzr;
        r = min(INF, r);

        //printf("unlaze de %d (i %d j %d) lz %lld lzr %lld\n", idx, i, j, l, r);
        int m = (i + j)/2;
        if(l >= INF){
            tree[idx*2].mn = INF;
            tree[idx*2].lz = INF;
            tree[idx*2].lzr = 0;
            tree[idx*2+1].mn = INF;
            tree[idx*2+1].lz = INF;
            tree[idx*2+1].lzr = 0;
        }
        else{
            tree[idx*2].mn = l;
            tree[idx*2].lz += l;
            tree[idx*2].lzr += r;

            l += r*(m+1-i);
            tree[idx*2+1].mn = l;
            tree[idx*2+1].lz += l;
            tree[idx*2+1].lzr += r;

        }
        tree[idx].lz = 0;
        tree[idx].lzr = 0;

    }
}

arv join(arv a, arv b){
    arv c;
    c.lz = c.lzr = 0;
    c.mn = min(a.mn, b.mn);
    return c;
}

void upd(int idx, int i, int j, int l, int r, ll x){
    if(j < l || i > r) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        if(x == INF){
            tree[idx].mn = INF; 
            tree[idx].lz = INF;
            tree[idx].lzr = 0;
        }
        else{
            tree[idx].mn = x + (i - l + 1); 
            tree[idx].lz += x + (i - l + 1);
            tree[idx].lzr++;
        }
        return;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1,j,l, r, x);
    tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

ll qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l || l > r)
        return INF;
    unlaze(idx, i, j);
    if(i >= l && j <= r)
        return tree[idx].mn;
    int m = (i + j)/2;
    return min(qry(idx*2, i, m, l, r), 
                qry(idx*2+1,m+1, j, l, r));
}

int main (){
	scanf("%d%d", &n, &m);
    int L = 0, R = m-1;
	for(int a=0;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        ll val = INF;
        if(i > 0)
            val = qry(1, 0, m-1, i-1, i-1);
            //printf("coloca de i %d a j %d pa comecando em val %lld\n", i, j, val);
        upd(1, 0, m-1, i, j, val);
        /*
        printf("depois do upd L %d R %d\n", L, R);
        for(int i=0;i<=R;i++){
            printf("%lld ", qry(1, 0, m-1, i,i));
        }
        puts("");
        */
        

        ll ans = qry(1, 0, m-1, L, R);
        if(ans >= INF)
            puts("-1");
        else
            printf("%lld\n", ans+a+1);
	}
}

