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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 312345;

int n, m, k;
pii s[MAXN];
ll fat[MAXN], inv[MAXN];

ll expo(ll base, ll e){
    if(e == 0)
        return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

ll ch(ll x, ll y){
    return mod(fat[x]*mod(inv[y]*inv[x-y]));
}
int ev[MAXN];

ll chs[MAXN][42];
ll acc[MAXN][42];

int main (){
	scanf("%d%d", &n,&m);
    fat[0] = 1;
    for(ll a=1;a<=n;a++)
        fat[a] = mod(fat[a-1]*a);
    inv[n] = expo(fat[n], modn-2);
    for(ll a=n-1;a>=0;a--)
        inv[a] = mod(inv[a+1]*(a+1));
    assert(inv[0] == 1);
	for(int a=0;a<n;a++)
        scanf("%d%d", &s[a].fst, &s[a].snd);
    vector<pii> ar(m);
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        ar[a] = {i, j};
    }
    ll ans = 0;
    memset(ev, 0, sizeof(ev));
    for(int a=0;a<n;a++){
        ev[s[a].fst]++;
        ev[s[a].snd+1]--;
    }
    int p = 0;
    for(int np=1;np<=n;np++){
        p += ev[np];
        //printf("p %d np %d\n", p, np);
        for(int k=0;k<=2*m;k++){
            if(p < np || np - k < 0)
                chs[np][k] = 0;
            else
                chs[np][k] = ch(p-k, np-k);
            //printf("chs[%d][%d] %lld\n", np, k, chs[np][k]);
            acc[np][k] = acc[np-1][k] + chs[np][k];
        }
    }

    for(int bm=0;bm<(1<<m);bm++){
        int L = 1, R = n;  
        set<int> v;
        for(int i=0;i<m;i++){
            if((bm>>i)&1){
                int u = ar[i].fst;
                int uu = ar[i].snd;
                L = max(L, max(s[u].fst, s[uu].fst));
                R = min(R, min(s[uu].snd, s[u].snd));
                v.insert(u);
                v.insert(uu);
            }
        }
        if(L > R)
            continue;
        int sign = (__builtin_popcount(bm)&1 ? -1 : 1);
        int sz = v.size();
        //printf("v sz %d L %d R %d ans + %lld (%d * (%lld - %lld))\n", sz, L, R,  sign*(acc[R][sz] - acc[L-1][sz]), sign, acc[R][sz], acc[L-1][sz]);
        ans = mod(ans + sign*(acc[R][sz] - acc[L-1][sz]));
    }
    ans = mod(ans + modn);
    printf("%lld\n", ans);
}

