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

int n, m, k;
int s[MAXN];

int prv[MAXN];

map<ll, int> cnt;

map<int, int> factor(int x){
    map<int, int> pcnt;
    //printf("factor %d\n", x);
    while(x > 1){
        //printf("conta %d\n", prv[x]);
        pcnt[prv[x]]++; 
        x /= prv[x];
    }
    return pcnt;
}

ll expo(ll base, ll e){
    if(e == 0) return 1;
    ll ans = expo(base, e/2);
    ans = ans*ans;
    if(e&1)
        ans = ans*base;
    return ans;
}

int main (){
    prv[1] = 1;
    for(int a=2;a<MAXN;a++){
        if(!prv[a])
            prv[a] = a;
        else
            continue;
        for(ll b=a;a*b < MAXN;b++){
            if(!prv[a*b])
                prv[a*b] = a;
        }
    }
	scanf("%d%d", &n, &k);
    ll ans = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        map<int, int> f = factor(s[a]);
        ll x = 1;
        ll o = 1;
        //printf("val %d\n", s[a]);
        for(auto it: f){
            int e = it.snd%k;
            //printf("pri %d e %d\n", it.fst, e);
            x *= expo(it.fst, e);
            if(e)
                o *= expo(it.fst, k - e);
        }
        ans += cnt[o]; 
        //printf("ans += cnt[%d] %d\n", o, cnt[o]);
        cnt[x]++;
        //printf("cnt[%d]++\n", x);
	}
    printf("%lld\n", ans);
}

