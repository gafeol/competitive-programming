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
const int MAXB = 2100;

int n, m, k;
int sz;
int s[70];
int base;

inline void conv(ll x){
    sz = 0;
    while(x > 0){
        s[sz++] = x%base;
        x /= base;
    }
    if(sz == 0)
        s[sz++] = 0;
}

int tim[66][2100][2][2];
int tempo = 0;
ll dp[66][2100][2][2];


ll ncomb[11][66][2100];
ll gocomb(int base, int sz, int bm){
    ll &r = ncomb[base][sz][bm];
    if(r != -1)
        return r;
    r = 0;
    if(sz == 0)
        return r = (bm == 0);
    for(int d=0;d<base;d++)
        r += gocomb(base, sz-1, bm^(1<<d));
    return r;
}

ll go(int i, int x, bool lo, bool canz){
    if(i == -1)
        return (x == 0);
    ll &r = dp[i][x][lo][canz];
    if(tim[i][x][lo][canz] != tempo){
        tim[i][x][lo][canz] = tempo;
        r = -1;
    }
    if(r != -1)
        return r;
    r = 0;

    if(lo && canz)
        return r = gocomb(base, i+1, x);
    for(int d=0;d<base;d++){
        if(!lo && s[i] < d) break;
        bool nlo = (lo || (d < s[i]));
        bool ncz = (canz || (d > 0));
        int nx = x;
        if(d > 0 || (d == 0 && canz))
            nx ^= (1<<d);
        r = r + go(i-1, nx, nlo, ncz);
    }
    return r;
}


int main (){
    memset(ncomb, -1, sizeof(ncomb));

    for(int base=2;base<=10;base++){
        for(int sz=0;sz<66;sz++){
            for(int bm=0;bm<MAXB;bm++){
                ncomb[base][sz][bm] = gocomb(base, sz, bm);
            }
        }
    }

    for_tests(t, tt){
        ll l, r;
        scanf("%d%lld%lld", &base, &l, &r);
        conv(r);
        tempo++;
        ll ans = go(sz-1, 0, 0, 0);
        conv(l-1);
        tempo++;
        ans -= go(sz-1, 0, 0, 0);
        printf("%lld\n", ans);
	}
}

