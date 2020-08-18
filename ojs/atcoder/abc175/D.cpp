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

const int MAXN = 5123;

int n, m;
ll k;
ll s[MAXN];
int p[MAXN];


int main (){
	scanf("%d%lld", &n, &k);
    ll ok = k;
    for(int a=0;a<n;a++){
        scanf("%d", p+a);
        p[a]--;
    }
    for(int a=0;a<n;a++)
        scanf("%lld", s+a);
    ll res = LLONG_MIN;
	for(int a=0;a<n;a++){
        int u = p[a];
        ll sum = s[u];
        ll sz = 1;
        res = max(res, sum);
        while(u != a){
            u = p[u];
            sum += s[u];
            sz++;
            if(sz <= k)
                res = max(res, sum);
        }
        ll ans = 0;
        if(k >= 2*sz){
            ans = (k/sz - 1)*sum;
            k %= sz; 
            k += sz;
            res = max(res, ans);
        }
        assert(u == a);
        while(k--){
            u = p[u];
            ans += s[u];
            res = max(res, ans);
        }
        k = ok;
	}
    printf("%lld\n", res);
}

