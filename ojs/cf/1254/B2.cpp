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

const int MAXN = 1000056;

int n, m, k;
ll s[MAXN];
int mrk[MAXN];

int main (){
    vector<int> pri;
    for(int i=2;i<MAXN;i++){
        if(mrk[i]) continue;
        pri.pb(i);
        for(ll a = i; a*i < MAXN;a++)
            mrk[a*i] = 1;
    }
	scanf("%d", &n);
    ll sum = 0;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        sum += s[a];
	}
    if(sum == 1){
        puts("-1");
        return 0;
    }
    vector<ll> t;
    for(int p: pri){
        if(sum%p == 0){
            t.pb(p);
            while(sum%p == 0)
                sum/=p;
        }
    }
    if(sum > 1)
        t.pb(sum);
    ll res = LLONG_MAX;
    for(ll k: t){
        ll ans = 0;
        ll curr = 0;
        for(int a=0;a<n;a++){
            curr += s[a];
            curr %= k;
            ans += min(curr, k-curr);
        }
        res = min(res, ans);
    }
    printf("%lld\n", res);
}
