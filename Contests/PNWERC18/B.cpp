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

const int MAXN = 10000009;

int n, m, k;

bool mrk[MAXN];
vector<int> pri;
ll l, r, ii, jj;

ll go(int i, ll mul, int cnt){
    if(mul > min(r, jj))
        return 0;
    if(i == pri.size())
        return 0;
    ll mx = mul*pri[i];
    if(mx <= min(r, jj))
        return ((cnt&1) ? 1 : -1)*(r/mx - (l-1)/mx)*(jj/mx - (ii-1)/mx) + go(i+1, mul*pri[i], cnt+1) + go(i+1, mul, cnt);
    return 0;
}

int main (){
    for(ll i=2;i<MAXN;i++){
        if(!mrk[i])
            pri.pb(i);
        for(ll j = i;i*j < MAXN;j++)
            mrk[i*j] = true;
    }
	scanf("%lld%lld%lld%lld", &l, &r, &ii, &jj);
    printf("%lld\n", (r-l+1)*(jj-ii+1) + go(0, 1ll, 0));
}

