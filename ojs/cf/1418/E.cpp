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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
ll sum[MAXN];

inline ll expo(ll base, ll e){
    ll res = 1, val = base;
    while(e){
        if(e&1)
            res = mod(res*val);
        val = mod(val*val);
        e >>= 1;
    }
    return res;
}

int main (){
    assert(expo(3, 2) == 9);
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    sort(s, s+n);
    for(int a=0;a<n;a++)
        sum[a] = mod(s[a] + (a == 0 ? 0 : sum[a-1]));
    for(int a=0;a<m;a++){
        int dur, def;
        scanf("%d%d", &dur, &def);
        int i = lower_bound(s, s+n, def) - s;
        //printf("i %d\n", i);
        ll res = 0;
        int qtdSt = n - i;
        int qtdWk = i;
        if(dur <= qtdSt){
            ll wk = (i == 0 ? 0 : sum[i-1]);
            ll st  = mod(modn + sum[n-1] - wk);
            //printf("wk %lld st %lld\n", wk, st);
            res = mod(st*(1 - mod(dur*expo(qtdSt, modn-2))));
            res = mod(res + wk*(1 - mod(dur*expo(qtdSt + 1, modn-2))));
            res = mod(modn + res);
        }
        printf("%lld\n", res);
    }
}
