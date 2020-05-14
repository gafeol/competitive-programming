#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2523;

int n, m, k;
char s[MAXN];

char t[MAXN];

ll L[MAXN], R[MAXN];
int X[MAXN], Y[MAXN];
ll sz[MAXN];

map<pll, ll> ev[MAXN];

ll cnt[MAXN];

int main (){
	scanf("%d", &n);
    scanf(" %s", s);
    sz[0] = strlen(s);
	for(int a=1;a<n;a++){
        char op[10];
        scanf(" %s %d", op, &X[a]);
        t[a] = op[0];
        if(t[a] == 'S'){
            scanf("%lld%lld", &L[a], R+a);            
            sz[a] = R[a] - L[a];
        }
        else{
            scanf("%d", &Y[a]);
            sz[a] = sz[X[a]] + sz[Y[a]];
        }
	}
    ev[n-1][{0, 0}] = 1ll;
    for(int a=n-1;a>=1;a--){
        debug("a %d\n", a);
        for(auto it: ev[a]){
            pll p = it.fst;
            ll count = it.snd;
            debug("ev %lld %lld\n", p.fst, p.snd);
            if(t[a] == 'S'){
                pll newp = p; 
                newp.fst += L[a];
                newp.snd += (sz[X[a]] - R[a]);
                ev[X[a]][newp] += count;
            }
            else{
                if(sz[X[a]] > p.fst && sz[Y[a]] > p.snd){
                    ev[X[a]][{p.fst, 0}] += count;
                    ev[Y[a]][{0, p.snd}] += count;
                }
                else if(sz[X[a]] > p.fst){
                    ev[X[a]][{p.fst, p.snd - sz[Y[a]]}] += count;
                }
                else if(sz[Y[a]] > p.snd){
                    ev[Y[a]][{p.fst - sz[X[a]], p.snd}] += count;
                }
            }
        }
        ev[a].clear();
    }
    debug("fim\n");
    for(auto it: ev[0]){
        pll p = it.fst;
        ll count = it.snd;
        ll i = p.fst;
        ll j = sz[0] - p.snd; // exclusivo

        debug("i %lld j %lld (%lld %lld)\n", i, j, p.fst, p.snd);
        cnt[i] = mod(cnt[i] + count);
        cnt[j] = mod(modn + mod(cnt[j] - count));
    }
    ll mult = 0;
    ll res = 0;
    for(int a=0;a<sz[0];a++){
        mult = mod(modn + mod(mult + cnt[a]));
        //printf("a %d cnt %lld mult %lld\n", a, cnt[a], mult);
        res = mod(res + mult*s[a]);
    }
    printf("%lld\n", res);
}

