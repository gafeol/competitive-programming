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

const int MAXN = 1123;

int n, m;
ll k;
ll s[MAXN];

ll dp[MAXN][6];

ll go(int i, int c){
    if(i == n)
        return 0;
    ll &r = dp[i][c];
    if(r != -1)
        return r;

    r = max(r, go(i+1, c));
    for(ll v=1;v<=c;v++)
        r = max(r, go(i+1, c-v) + s[i]*v*100 - k);
    for(ll a=1;a<=5-c;a++)
        r = max(r, go(i+1, c+a) - s[i]*a*100 - k);

    return r;
}

int main (){
	scanf("%d%d%lld", &m, &n, &k);
    string sans = "None";
    ll ans = 0;
	for(int a=0;a<m;a++){
        memset(dp, -1, sizeof(dp));
        string name;
        cin >>name;
        for(int i=0;i<n;i++){
            scanf("%lld", s+i);
        }
        ll val = go(0, 0);
        if(val > ans){
            ans = val;
            sans = name;
        }
	}
    cout << sans << " " << ans << endl;
}

