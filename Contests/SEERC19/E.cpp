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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 112345;

int n, m, k;
int d;
ll t;
ll idc, idm, pc, pm;
ll s[MAXN];

// se 0 ... i for driver, soma s[i] - max(idc, s[i] - d)  (pode ser negativa essa subtracao)
ll dSobra[MAXN];

ll mSobra[MAXN];
ll mFalta[MAXN];

// soma o quanto sobra de idade pra mandar todo mundo de i...n-1 pra max(1, s[i]-d)
ll umSobra[MAXN];


ll custoMoto(int i, int j, ll sob){
    //printf("custoMoto %d %d %lld\n", i, j, sob);
    if(i > j){
        if(sob >= 0)
            return 0;
        else
            return LLONG_MAX;
    }
    if(s[j] + d < idm) return LLONG_MAX;
    ll sobra = mSobra[j] - (i == 0 ? 0 : mSobra[i-1]);
    if(sobra + sob < 0)
        return LLONG_MAX;
    ll falta = mFalta[j] - (i == 0 ? 0 : mFalta[i-1]);
    //printf("sobra %lld falta %lld\n", sobra, falta);
    return falta*t + pm*(j-i+1);
}

int main (){
	scanf("%d%d", &n, &k);
    scanf("%lld%lld%lld%lld", &idc, &pc, &idm, &pm);
    scanf("%lld%d", &t, &d);
	for(int a=0;a<n;a++)
        scanf("%lld", s+a);

    sort(s, s+n, greater<ll>());

    for(int i=0;i<n;i++){
        dSobra[i] = (i > 0 ? dSobra[i-1] : 0);
        dSobra[i] += s[i] - max(idc, s[i] - d);

        mSobra[i] = (i > 0 ? mSobra[i-1] : 0);
        mSobra[i] += s[i] - max(idm, s[i]-d);

        mFalta[i] = (i > 0 ? mFalta[i-1] : 0);
        mFalta[i] += max(0ll, idm - s[i]);

        //printf("i %d dSobra %lld mSobra %lld mFalta %lld\n", i, dSobra[i], mSobra[i], mFalta[i]);
    }

    for(int i=n-1;i>=0;i--){
        umSobra[i] = umSobra[i+1] + s[i] - max(1ll, s[i]-d);
    }

    ll ans = LLONG_MAX;
    ll faltaD = 0; // qtos anos faltam pra tdo mundo poder dirigir
    for(ll nc=0;nc<=n;nc++){
        int ultD = nc-1; 
        int ultC = max(ultD + 1ll, n-nc*(k-1));
        if(nc && idc - s[ultD] > d)
            break;
        if(ultD >= 0)
            faltaD += max(0ll, idc - s[ultD]);
        ll sobra = (nc ? dSobra[ultD] + umSobra[ultC] : 0);
        ll cus = custoMoto(ultD+1, ultC-1, sobra);
        //printf("nc %d faltaD %lld ultD %d ultC %d sobra %lld cus %lld\n", nc, faltaD, ultD, ultC, sobra, cus);
        if(cus == LLONG_MAX)
            continue;
        ans = min(ans, nc*pc + faltaD*t + cus);
    }
    if(ans == LLONG_MAX)
        puts("-1");
    else
        printf("%lld\n", ans);
}

