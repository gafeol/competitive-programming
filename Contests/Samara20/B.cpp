#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

int n, m; ll k;
ll s[MAXN];

int main (){
	scanf("%d%lld", &n, &k);
    vector<ll> bef, aft;
	for(int a=1;a<=n;a++){
        ll x;
        scanf("%lld", &x);
        if(x < 0) bef.pb(-x);
        else aft.pb(x);
	}
    sort(bef.begin(), bef.end());
    sort(aft.begin(), aft.end());
    bef.pb(LLONG_MAX);
    int ans = 0;
    for(int i=0;i<aft.size();i++){
        if(aft[i] > k) break;
        ll sob = k - 2*aft[i];
        int res =  1 + i + (upper_bound(bef.begin(), bef.end(), sob) - bef.begin());
        ans = max(ans, res);
    }
    for(int i=0;i<bef.size();i++){
        if(bef[i] > k) break;
        ll sob = k - 2*bef[i];
        int res =  1 + i + (upper_bound(aft.begin(), aft.end(), sob) - aft.begin());
        ans = max(ans, res);
    }

    printf("%d\n", ans);

    return 0;
}

