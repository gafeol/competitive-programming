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

const int MAXN = 1123456;
const ll INF = 100000000000LL;

int n, m;
ll k;
ll d[MAXN][2];
ll tree[MAXN*4];


ll qry(int idx, int i, int j, int l, int r){
    if(l > r) return INF;
    if(i > r || j < l) return INF;
    if(i >= l && j <= r){
        return tree[idx];
    }
    int m = ((i+j)>>1);
    return min(qry(idx*2, i, m, l, r), qry(idx*2+1, m+1, j, l, r));
}

void upd(int idx, int i, int j, int l){
    if(i > l || j < l) return;
    if(i == j){
        tree[idx] = d[i][0];
        return ;
    }
    int m = ((i+j)>>1);
    upd(idx*2, i, m, l);
    upd(idx*2+1, m+1, j, l);
    tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

int main (){
	scanf("%d%lld", &n, &k);
    vector<ll> s;
    s.pb(1);
	for(int a=1;a<=n;a++){
        ll x;
        scanf("%lld", &x);
        s.pb(x);
	}
    s.pb(k);
    ll x, y;
    for(int a=0;a<=s.size()-1;a++){
        d[a][0] = d[a][1] = INF;
    }
    scanf("%lld%lld", &x, &y);
    d[s.size()-1][0] = 0;
    upd(1, 0, s.size()-1, s.size()-1);
    for(int i = s.size()-2;i>=0;i--){
        ll nxtsh, nxtlg;  
        nxtsh = (--upper_bound(s.begin(), s.end(), s[i]+x)) - s.begin();
        ll mn0 = qry(1, 0, s.size()-1, i+1, nxtsh);
        d[i][0] = min(d[i][0], min(mn0, d[nxtsh][1])+1);
        nxtlg = (--upper_bound(s.begin(), s.end(), s[i]+y)) - s.begin();
        mn0 = qry(1, 0, s.size()-1, i+1, nxtlg);
        d[i][1] = min(d[i][1], mn0+1);
        upd(1, 0, s.size()-1, i);
        //printf("i %d si %lld nxtsh %lld nxtlg %lld\n", i, s[i], nxtsh, nxtlg);
        //printf("D0 %d d1 %d\n", d[i][0], d[i][1]);
    }
    ll ans = min(d[0][0], d[0][1]);
    if(ans >= INF)
        puts("-1");
    else
        printf("%lld\n", ans);
}

