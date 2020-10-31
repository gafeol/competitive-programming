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

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];

ll bit[MAXN];

ll qry(int i){
    i += 2;
    ll ans = 0;
    while(i < MAXN){
        ans += bit[i]; 
        i += (i&-i);
    }
    return ans;
}

void upd(int i, ll x){
    i += 2; 
    while(i > 0){
        bit[i] += x;
        i -= (i&-i);
    }
}


int main (){
	scanf("%d", &n);
    vector<ll> X;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        X.pb(s[a]);
	}
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    ll ans = 0;
    bool fst = true;
    for(int a=0;a<n;a++){
        int i = lower_bound(X.begin(), X.end(), s[a]) - X.begin();
        ans += qry(i+1);
        upd(i, s[a]);
        if(!fst)
            printf(" ");
        printf("%lld", ans);
        fst = false;
    }
    puts("");
    return 0;
}
