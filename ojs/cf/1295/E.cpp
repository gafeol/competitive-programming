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
ll s[MAXN];
int p[MAXN], pos[MAXN];
ll acc[MAXN];

struct arv{
    ll mn;
    ll lz;
} tree[MAXN*4];

void unlaze(int idx, int i, int j){
    ll aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(i != j && aux){
        tree[idx*2].lz += aux;
        tree[idx*2].mn += aux;

        tree[idx*2+1].lz += aux;
        tree[idx*2+1].mn += aux;
    }
}

void build(int idx, int i, int j){
    if(i == j){
        tree[idx].mn = acc[i];
        tree[idx].lz = 0;
        return ;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
}

void upd(int idx, int i, int j, int l, int r, ll x){
    if(j < l || i > r || l > r)
        return;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].mn += x;         
        tree[idx].lz += x;
        return ;
    }
    int m = (i+j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", p+a);
        pos[p[a]] = a;
	}
    ll sum =0;
    for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        sum += s[a];
        acc[a] = sum;
        //printf("%lld ", acc[a]);
    }
    //puts("");
    
    build(1, 0, n-2);
    ll ans = tree[1].mn;
    for(int val=1;val<=n;val++){
        //printf("upd (%d, %d) += %lld\n", pos[val], n-2, -s[pos[val]]);
        upd(1, 0, n-2, pos[val], n-2, -s[pos[val]]);
        //printf("upd (%d, %d) += %lld\n", 0, pos[val]-1, s[pos[val]]);
        upd(1, 0, n-2, 0, pos[val]-1, s[pos[val]]);
        ans = min(ans, tree[1].mn);     
        //printf("mn %lld\n", tree[1].mn);
    }
    printf("%lld\n", ans);
}

