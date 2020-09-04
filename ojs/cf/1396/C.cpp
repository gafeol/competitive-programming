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

const int MAXN = 1000006;

int n;
ll s[MAXN];
ll c[3], d;
ll dp[MAXN][2];

ll go(int i, bool fimPassou){
    ll &r = dp[i][fimPassou];
    if(r != -1) return r;
    r = LLONG_MAX;
    if(i == n-1){
        if(fimPassou){
            r = min(r, 3*d + c[0]*(s[i]+1) + c[0]);
            r = min(r, 3*d + c[1] + c[0]);
            r = min(r, d + c[0]*s[i] + c[2]);
        }
        else{
            // esse eh o fim
            r = min(r, 2*d + c[0]*(s[i]+1) + c[0]);
            r = min(r, 2*d + c[1] + c[0]);
            r = min(r, c[0]*s[i] + c[2]);
        }
        return r;
    }

    if(fimPassou){
        // assume que tudo atras ta resolvido
        // lazy
        ll pass = 2*d; // vou prox e volto pro ant
        r = min(r, pass + go(i+1, fimPassou) + c[0]*(s[i]+1) + c[0]);
        r = min(r, pass + go(i+1, fimPassou) + c[1] + c[0]);
        // nao lazy
        r = min(r, pass + go(i+1, fimPassou) + c[0]*s[i] + c[2]);
    }
    else{
        // assume que tudo atras ta resolvido
        // esse eh o fim
        ll pass = d;
        r = min(r, pass + go(i+1, 1) + c[0]*(s[i]+1) + c[0]);        
        r = min(r, pass + go(i+1, 1) + c[1] + c[0]);
        r = min(r, pass + go(i+1, 1) + c[0]*s[i] + c[2]); // nao precisa voltar pra ele aqui no fundo

        //esse nao eh o fim
        r = min(r, go(i+1, 0) + c[0]*s[i] + c[2] + d); // so mata vai
        r = min(r, go(i+1, 0) + c[0]*(s[i] + 1) + c[0] + 3*d); // atira vai volta atira vai
        r = min(r, go(i+1, 0) + c[1] + c[0] + 3*d);
        if(i+2 < n)
            r = min(r, go(i+2, 0) + 4*d + c[0]*2 + min(c[0]*(s[i]+1), c[1]) + min(c[0]*(s[i+1]+1), c[1]));
        if(i+1 == n-1)
            r = min(r, 3*d + c[0]*2 + min(c[0]*(s[i]+1), c[1]) + min(c[0]*(s[i+1]+1), c[1]));
    }
    return r;
}

int main (){
	scanf("%d%lld%lld%lld", &n, c, c+1, c+2);
    scanf("%lld", &d);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
	}
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(0, 0));
}

