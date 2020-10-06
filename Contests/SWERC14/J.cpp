#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
const ll modn2 = 1000000009;
ll pri = modn2;
ll pri2 = modn;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % modn2; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 2123;

int n, m, k, np, mp;
int s[MAXN];

ll h[MAXN], hh[MAXN];
ll ht, hht;
ll H[MAXN], HH[MAXN];

ll HT, HHT;
int M[MAXN][MAXN];

int main (){
	scanf("%d%d", &np, &mp);
    scanf("%d%d", &n, &m);
    ll pot = 1, pot2 = 1;
	for(int a=0;a<np;a++){
        if(a < np-1){
            pot = mod(pot*2);
            pot2 = mod2(pot2*2);
        }
        for(int b=0;b<mp;b++){
            char c;
            scanf(" %c", &c);
            int v = (c == 'o');
            H[b] = mod(H[b]*2 + v);
            HH[b] = mod2(HH[b]*2 + v);
        }
	}
    debug("pot %lld pot2 %lld\n", pot, pot2);

    ll pripot = 1, pripot2 = 1;
    for(int b=0;b<mp;b++){
        HT = mod(HT*pri + H[b]);
        HHT = mod2(HHT*pri2 + HH[b]);
        if(b < mp-1){
            pripot = mod(pripot*pri);
            pripot2 = mod2(pripot2*pri2);
        }
        debug("H %lld HH %lld\n", H[b], HH[b]);
    }
    debug("HT %lld HHT %lld\n", HT, HHT);

    int ans = 0;
    for(int a=0;a<n;a++){
        debug("lin %d\n", a);
        for(int b=0;b<m;b++){
            char c;
            scanf(" %c", &c);
            int v = (c == 'o');
            M[a][b] = v;
            h[b] = mod(h[b]*2 + v);
            hh[b] = mod2(hh[b]*2 + v);
            debug("h %lld hh %lld\n", h[b], hh[b]);
        }
        if(a >= np-1){
            ht = 0;
            hht = 0;
            for(int b=0;b<m;b++){
                ht = mod(ht*pri + h[b]);
                hht = mod2(hht*pri2 + hh[b]);
                if(b >= mp -1){
                    debug("a %d b %d ht %lld hht %lld\n", a, b, ht, hht);
                    ans += (ht == HT && hht == HHT);
                    ht = mod(ht - pripot*h[b-mp+1]);
                    ht = mod(ht + modn);
                    hht = mod2(hht - pripot2*hh[b-mp+1]);
                    hht = mod2(hht + modn2);
                }
            }
            for(int b=0;b<m;b++){
                debug("sub %lld %lld\n", pot*M[a-np+1][b], pot2*M[a-np+1][b]);
                h[b] = mod(h[b] - pot*M[a-np+1][b]);
                h[b] = mod(modn + h[b]);
                hh[b] = mod2(hh[b] - pot2*M[a-np+1][b]);
                hh[b] = mod2(modn2 + hh[b]);
            }
        }
    }
    printf("%d\n", ans);
}

