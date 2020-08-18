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

const int MAXN = 500005;

int n, m, k;
int s[MAXN];
int cnt[MAXN];
ll res[MAXN];
ll tree[MAXN*4];

ll qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l || l > r) return 1ll;
    if(i >= l && j <= r)
        return tree[idx];
    int m = (i + j)/2;
    return mod(qry(idx*2, i, m, l, r) * qry(idx*2+1, m+1, j, l, r));
}

void upd(int idx, int i, int j, int l, ll x){
    if(l < i || l > j) return ;
    if(i == j){
        tree[idx] = mod(tree[idx] + x);
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, x);
    upd(idx*2+1, m+1, j, l, x);
    tree[idx] = mod(tree[idx*2] * tree[idx*2+1]);
}

ll fat[MAXN], ifat[MAXN];

ll ch(ll x, ll y){
    return mod(mod(fat[x] * ifat[y]) * ifat[x-y]);
}

ll expo(ll base, ll e){
    if(e == 0) return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1) ans = mod(ans*base);
    return ans;
}

int main (){
    fat[0] = 1;
    ifat[0] = 1;
    for(int a=1;a<MAXN;a++){
        fat[a] = mod(a*fat[a-1]);
        ifat[a] = expo(fat[a], modn-2);
    }
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n;a++){
            cnt[a] = 0;
            res[a] = 0;
        }
        for(int a=0;a<4*n;a++)
            tree[a] = 0; 
        vector<int> ind;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            cnt[s[a]]++;
            ind.pb(s[a]);
        }
        sort(ind.begin(), ind.end());
        ind.erase(unique(ind.begin(), ind.end()), ind.end());
        for(int x=1;x<=n;x++)
            upd(1, 1, n, x, 1);
        vector<int> nind;
        int sz = 1;
        while(!ind.empty()){
            for(int i=ind.size()-1;i>=0;i--){
                int x = ind[i];
                ll q = ch(cnt[x], sz);
                ll aft = qry(1, 1, n, x+1, n);
                ll bef = qry(1, 1, n, 1, x-1);
                //printf("sz %d x %d sx %lld aft %lld bef %lld\n", sz, x, q, aft, bef);
                res[x] = mod(res[x] + mod(mod(q*aft)*bef));
                upd(1, 1, n, x, q);
                if(cnt[x] > sz)
                    nind.pb(x);
            }
            reverse(nind.begin(), nind.end());
            ind = nind;
            nind.clear();
            sz++;
        }
        for(int a=1;a<=n;a++){
            printf("%lld ", res[a]);
        }
        puts("");
    }
}

