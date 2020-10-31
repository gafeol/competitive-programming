#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 512345;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int tree[MAXN*4];

void build(int idx, int i, int j){
    tree[idx] = INF;
    if(i == j){
        return ;
    }
    int m =(i+j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
}

int qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return INF;
    if(i >= l && j <= r)
        return tree[idx];
    int m =(i+j)/2;
    return min(qry(idx*2, i, m, l, r), 
                qry(idx*2+1, m+1, j, l, r));
}

void upd(int idx, int i, int j, int l, int v){
    if(i > l || j < l) return;
    if(i == j){
        tree[idx] = v;
        return ;
    }
    int m = (i+j)/2;
    upd(idx*2, i, m, l, v);
    upd(idx*2+1, m+1, j, l, v);
    tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

int main (){
    vector<pair<int, int>> v;
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
        scanf("%d", s+a);
        v.eb(s[a]-a, a);
	}
    v.eb(INT_MAX, n+1);
    vector<int> fx(m);
    for(int a=0;a<m;a++){
        int i;
        scanf("%d", &i);
        fx[a] = i;
    }
    fx.pb(0);
    fx.pb(n+1);
    sort(fx.begin(), fx.end());
    sort(v.begin(), v.end());
    build(1, 0, n+1);
    upd(1, 0, n+1, 0, 0);
    int res;
    for(pii p: v){
        int bef =  *(--lower_bound(fx.begin(), fx.end(), p.snd));
        int x = qry(1, 0, n+1, bef, p.snd-1);
        res = x + p.snd - 1;
        //printf("res pos %d eh %d\n", p.snd, res);
        upd(1, 0, n+1, p.snd, res-p.snd);
    }
    if(res >= INF)
        puts("-1");
    else
        printf("%d\n", res);
    return 0;
}

